#include "empire.h"

#include "building/count.h"
#include "city/constants.h"
#include "city/population.h"
#include "city/resource.h"
#include "city/trade.h"
#include "core/calc.h"
#include "core/log.h"
#include "empire/empire_city.h"
#include "empire/empire_object.h"
#include "empire/trade_route.h"
#include "io/io.h"
#include "type.h"

#include "io/io_buffer.h"
#include <string.h>

const static vec2i EMPIRE_SIZE{1200, 1600};

enum E_EMPIRE {
    //    EMPIRE_WIDTH = 2000,
    //    EMPIRE_HEIGHT = 1000,
    EMPIRE_HEADER_SIZE = 1280,
    //    EMPIRE_DATA_SIZE = 12800
};

const static int EMPIRE_DATA_SIZE[2] = {12800, 15200};

struct empire_map_data_t {
    int initial_scroll_x;
    int initial_scroll_y;
    int scroll_x;
    int scroll_y;
    int selected_object;
    int viewport_width;
    int viewport_height;
};

empire_map_data_t g_empire_map_data;

const char SCENARIO_FILE[2][2][100] = {{"c32.emp", "c3.emp"}, {"", "Pharaoh2.emp"}};

bool empire_city_type_can_trade(int type) {
    switch (type) {
    case EMPIRE_CITY_PHARAOH_TRADING:
    case EMPIRE_CITY_EGYPTIAN_TRADING:
    case EMPIRE_CITY_FOREIGN_TRADING:
        return true;
    }
    
    return false;
}

static void check_scroll_boundaries(void) {
    auto& data = g_empire_map_data;
    int max_x = EMPIRE_SIZE.x - data.viewport_width;
    int max_y = EMPIRE_SIZE.y - data.viewport_height + 20;

    data.scroll_x = calc_bound(data.scroll_x, 0, max_x);
    data.scroll_y = calc_bound(data.scroll_y, 0, max_y);
}

void empire_load_editor(int empire_id, int viewport_width, int viewport_height) {
    //    empire_load_external_c3(1, empire_id);
    //    empire_object_init_cities();
    //
    //    const empire_object *our_city = empire_object_get_our_city();
    //
    //    data.viewport_width = viewport_width;
    //    data.viewport_height = viewport_height;
    //    if (our_city) {
    //        data.scroll_x = our_city->x - data.viewport_width / 2;
    //        data.scroll_y = our_city->y - data.viewport_height / 2;
    //    } else {
    //        data.scroll_x = data.initial_scroll_x;
    //        data.scroll_y = data.initial_scroll_y;
    //    }
    //    check_scroll_boundaries();
}
void empire_init_scenario(void) {
    auto& data = g_empire_map_data;
    data.scroll_x = data.initial_scroll_x;
    data.scroll_y = data.initial_scroll_y;
    data.viewport_width = EMPIRE_SIZE.x;
    data.viewport_height = EMPIRE_SIZE.y;

    empire_object_init_cities();
}

void empire_set_viewport(int width, int height) {
    auto& data = g_empire_map_data;
    data.viewport_width = width;
    data.viewport_height = height;
    check_scroll_boundaries();
}
void empire_get_scroll(int* x_scroll, int* y_scroll) {
    auto& data = g_empire_map_data;
    *x_scroll = data.scroll_x;
    *y_scroll = data.scroll_y;
}
void empire_adjust_scroll(int* x_offset, int* y_offset) {
    auto& data = g_empire_map_data;
    *x_offset = *x_offset - data.scroll_x;
    *y_offset = *y_offset - data.scroll_y;
}
void empire_set_scroll(int x, int y) {
    auto& data = g_empire_map_data;
    data.scroll_x = x;
    data.scroll_y = y;
    check_scroll_boundaries();
}
void empire_scroll_map(int x, int y) {
    auto& data = g_empire_map_data;
    data.scroll_x += x;
    data.scroll_y += y;
    check_scroll_boundaries();
}

int empire_selected_object(void) {
    auto& data = g_empire_map_data;
    return data.selected_object;
}
void empire_clear_selected_object(void) {
    auto& data = g_empire_map_data;
    data.selected_object = 0;
}
void empire_select_object(int x, int y) {
    auto& data = g_empire_map_data;
    int map_x = x + data.scroll_x;
    int map_y = y + data.scroll_y;

    data.selected_object = empire_object_get_closest(vec2i(map_x, map_y));
}

bool empire_can_export_resource_to_city(int city_id, e_resource resource) {
    empire_city* city = empire_city_get(city_id);
    if (city_id && trade_route_limit_reached(city->route_id, resource)) {
        // quota reached
        return false;
    }
    if (city_resource_count(resource) <= city_resource_trading_amount(resource)) {
        // stocks too low
        return false;
    }
    if (city_id == 0 || city->buys_resource[resource]) {
        int status = city_resource_trade_status(resource);
        switch (status) {
        case TRADE_STATUS_EXPORT: return true;
        case TRADE_STATUS_EXPORT_SURPLUS: return city_resource_trade_surplus(resource);
        }
    }
    
    return false;
}

static int get_max_food_stock_for_population(e_resource resource) {
    switch (resource) {
    case RESOURCE_GRAIN:
    case RESOURCE_MEAT:
    case RESOURCE_LETTUCE:
    case RESOURCE_GAMEMEAT:
    case RESOURCE_POTTERY:
    case RESOURCE_LUXURY_GOODS:
    case RESOURCE_OIL:
    case RESOURCE_BEER:
        return std::max(100, (city_population() / 100) * 100);
    }

    return 0;
}

static int get_max_raw_stock_for_population(e_resource resource) {
    int finished_good = RESOURCE_NONE;
    switch (resource) {
    case RESOURCE_CLAY: finished_good = RESOURCE_POTTERY; break;
    case RESOURCE_TIMBER: finished_good = RESOURCE_LUXURY_GOODS; break;
    case RESOURCE_STRAW: finished_good = RESOURCE_OIL; break;
    case RESOURCE_BARLEY: finished_good = RESOURCE_BEER; break;
    case RESOURCE_COPPER: finished_good = RESOURCE_WEAPONS; break;
    }

    int max_in_stock = 0;
    if (finished_good) {
        max_in_stock = 200 + 200 * building_count_industry_active(resource);
    }

    return max_in_stock;
}

int empire_can_import_resource_from_city(int city_id, e_resource resource) {
    empire_city* city = empire_city_get(city_id);
    if (!city->sells_resource[resource])
        return 0;

    int status = city_resource_trade_status(resource);
    switch (status) {
    case TRADE_STATUS_IMPORT:
    case TRADE_STATUS_IMPORT_AS_NEEDED:
        ;
        break;

    default:
        return 0;
    }

    if (trade_route_limit_reached(city->route_id, resource)) {
        return 0;
    }

    int in_stock = city_resource_count(resource);
    int max_in_stock = 0;

    if (status == TRADE_STATUS_IMPORT_AS_NEEDED) {
        switch (resource) {
        // food and finished materials
        case RESOURCE_GRAIN:
        case RESOURCE_MEAT:
        case RESOURCE_LETTUCE:
        case RESOURCE_GAMEMEAT:
        case RESOURCE_OIL:
        case RESOURCE_BEER:
            max_in_stock = get_max_food_stock_for_population(resource);
            break;

        case RESOURCE_MARBLE:
        case RESOURCE_WEAPONS:
            max_in_stock = 10;
            break;

        case RESOURCE_CLAY:
        case RESOURCE_TIMBER:
        case RESOURCE_STRAW: 
        case RESOURCE_BARLEY:
        case RESOURCE_COPPER:
            max_in_stock = get_max_raw_stock_for_population(resource);
            break;

        case RESOURCE_BRICKS:
            max_in_stock = std::max(100, (city_population() / 100) * 100);
            break;

        case RESOURCE_POTTERY:
        case RESOURCE_LUXURY_GOODS:
            max_in_stock = std::max(100, (city_population() / 100) * 50);
            break;

        case RESOURCE_PAPYRUS:
            max_in_stock = std::max(100, (building_count_active(BUILDING_SCRIBAL_SCHOOL) + building_count_active(BUILDING_LIBRARY)) * 100);
            break;

        default:
            max_in_stock = 100;
            break;
        }
    } else {
        max_in_stock = city_resource_trading_amount(resource);
    }

    return in_stock < max_in_stock ? 1 : 0;
}

io_buffer* iob_empire_map_params = new io_buffer([](io_buffer* iob, size_t version) {
    auto& data = g_empire_map_data;
    iob->bind(BIND_SIGNATURE_INT32, &data.scroll_x);
    iob->bind(BIND_SIGNATURE_INT32, &data.scroll_y);
    iob->bind(BIND_SIGNATURE_INT32, &data.selected_object);
});