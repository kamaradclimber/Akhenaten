#include "warnings.h"

#include "building/building.h"
#include "building/count.h"
#include "building/model.h"
#include "city/constants.h"
#include "city/labor.h"
#include "city/population.h"
#include "city/resource.h"
#include "city/warning.h"
#include "core/calc.h"
#include "empire/city.h"
#include "map/grid.h"
#include "map/road_access.h"
#include "map/terrain.h"
#include "scenario/property.h"

static bool has_warning = false;

void building_construction_warning_reset(void) {
    has_warning = false;
}

static void show(int warning) {
    city_warning_show(warning);
    has_warning = true;
}

static void check_road_access(int type, int x, int y, int size) {
    switch (type) {
        case BUILDING_NONE:
        case BUILDING_CLEAR_LAND:
        case BUILDING_ROAD:
        case BUILDING_HOUSE_VACANT_LOT:
        case BUILDING_SMALL_STATUE:
        case BUILDING_MEDIUM_STATUE:
        case BUILDING_LARGE_STATUE:
//        case BUILDING_MENU_BEAUTIFICATION:
        case BUILDING_WELL:
        case BUILDING_WATER_LIFT2:
        case BUILDING_GATEHOUSE:
        case BUILDING_ROADBLOCK:
        case BUILDING_TRIUMPHAL_ARCH:
//        case BUILDING_MENU_FORTS:
        case BUILDING_FORT_CHARIOTEERS:
        case BUILDING_FORT_ARCHERS:
        case BUILDING_FORT_INFANTRY:
            return;
    }

    int has_road = 0;
    if (map_has_road_access(x, y, size, 0))
        has_road = 1;
    else if (type == BUILDING_WAREHOUSE && map_has_road_access(x, y, size, 0))
        has_road = 1;
    else if (type == BUILDING_SENET_HOUSE && map_has_road_access_hippodrome(x, y, 0))
        has_road = 1;
    else if (building_is_large_temple(type) && map_has_road_access_temple_complex(x, y, 0))
        has_road = 1;
    else if (type == BUILDING_ORACLE && map_closest_road_within_radius(x, y, size, 2, 0, 0))
        has_road = 1;

    if (!has_road)
        show(WARNING_ROAD_ACCESS_NEEDED);
}

static void check_water(int type, int x, int y) {
    if (!has_warning) {
        if (type == BUILDING_MENU_BEAUTIFICATION || type == BUILDING_MENU_MONUMENTS) {
            int grid_offset = map_grid_offset(x, y);
            int has_water = 0;
            if (map_terrain_is(grid_offset, TERRAIN_GROUNDWATER))
                has_water = 1;
            else if (type == BUILDING_MENU_MONUMENTS) {
                if (map_terrain_is(grid_offset + map_grid_delta(1, 0), TERRAIN_GROUNDWATER) ||
                    map_terrain_is(grid_offset + map_grid_delta(0, 1), TERRAIN_GROUNDWATER) ||
                    map_terrain_is(grid_offset + map_grid_delta(1, 1), TERRAIN_GROUNDWATER)) {
                    has_water = 1;
                }
            }
            if (!has_water)
                show(WARNING_WATER_PIPE_ACCESS_NEEDED);
        }
    }
}

static void check_workers(int type) {
    if (!has_warning && type != BUILDING_WELL && !building_is_fort(type)) {
        if (model_get_building(type)->laborers > 0 && city_labor_workers_needed() >= 10)
            show(WARNING_WORKERS_NEEDED);
    }
}

static void check_market(int type) {
    if (!has_warning && type == BUILDING_GRANARY) {
        if (building_count_active(BUILDING_MARKET) <= 0)
            show(WARNING_BUILD_MARKET);
    }
}

static void check_barracks(int type) {
    if (!has_warning) {
        if (building_is_fort(type) && building_count_active(BUILDING_RECRUITER) <= 0)
            show(WARNING_BUILD_BARRACKS);
    }
}

static void check_weapons_access(int type) {
    if (!has_warning && type == BUILDING_RECRUITER) {
        if (city_resource_count(RESOURCE_WEAPONS_C3) <= 0)
            show(WARNING_WEAPONS_NEEDED);
    }
}

static void check_wall(int type, int x, int y, int size) {
    if (!has_warning && type == BUILDING_TOWER) {
        if (!map_terrain_is_adjacent_to_wall(x, y, size))
            show(WARNING_SENTRIES_NEED_WALL);
    }
}

static void check_actor_access(int type) {
    if (!has_warning && type == BUILDING_BOOTH) {
        if (building_count_active(BUILDING_JUGGLER_SCHOOL) <= 0)
            show(WARNING_BUILD_ACTOR_COLONY);
    }
}

static void check_gladiator_access(int type) {
    if (!has_warning && type == BUILDING_BANDSTAND) {
        if (building_count_active(BUILDING_CONSERVATORY) <= 0)
            show(WARNING_BUILD_GLADIATOR_SCHOOL);
    }
}

static void check_lion_access(int type) {
    if (!has_warning && type == BUILDING_PAVILLION) {
        if (building_count_active(BUILDING_DANCE_SCHOOL) <= 0)
            show(WARNING_BUILD_LION_HOUSE);
    }
}

static void check_charioteer_access(int type) {
    if (!has_warning && type == BUILDING_SENET_HOUSE) {
        if (building_count_active(BUILDING_CHARIOT_MAKER) <= 0)
            show(WARNING_BUILD_CHARIOT_MAKER);
    }
}

static void check_iron_access(int type) {
    if (type == BUILDING_WEAPONS_WORKSHOP &&
        building_count_industry_active(RESOURCE_IRON) <= 0) {
        if (city_resource_count(RESOURCE_WEAPONS_C3) <= 0 && city_resource_count(RESOURCE_IRON) <= 0) {
            show(WARNING_IRON_NEEDED);
            if (empire_can_produce_resource(RESOURCE_IRON, true))
                show(WARNING_BUILD_IRON_MINE);
            else if (!empire_can_import_resource(RESOURCE_IRON, true))
                show(WARNING_OPEN_TRADE_TO_IMPORT);
            else if (city_int(RESOURCE_IRON) != TRADE_STATUS_IMPORT)
                show(WARNING_TRADE_IMPORT_RESOURCE);
        }
    }
}

static void check_vines_access(int type) {
    if (type == BUILDING_BEER_WORKSHOP &&
        building_count_industry_active(RESOURCE_VINES) <= 0) {
        if (city_resource_count(RESOURCE_WINE) <= 0 && city_resource_count(RESOURCE_VINES) <= 0) {
            show(WARNING_VINES_NEEDED);
            if (empire_can_produce_resource(RESOURCE_VINES, true))
                show(WARNING_BUILD_VINES_FARM);
            else if (!empire_can_import_resource(RESOURCE_VINES, true))
                show(WARNING_OPEN_TRADE_TO_IMPORT);
            else if (city_int(RESOURCE_VINES) != TRADE_STATUS_IMPORT)
                show(WARNING_TRADE_IMPORT_RESOURCE);
        }
    }
}

static void check_olives_access(int type) {
    if (type == BUILDING_LINEN_WORKSHOP &&
        building_count_industry_active(RESOURCE_OLIVES) <= 0) {
        if (city_resource_count(RESOURCE_OIL_C3) <= 0 && city_resource_count(RESOURCE_OLIVES) <= 0) {
            show(WARNING_OLIVES_NEEDED);
            if (empire_can_produce_resource(RESOURCE_OLIVES, true))
                show(WARNING_BUILD_OLIVE_FARM);
            else if (!empire_can_import_resource(RESOURCE_OLIVES, true))
                show(WARNING_OPEN_TRADE_TO_IMPORT);
            else if (city_int(RESOURCE_OLIVES) != TRADE_STATUS_IMPORT)
                show(WARNING_TRADE_IMPORT_RESOURCE);
        }
    }
}

static void check_timber_access(int type) {
    if (type == BUILDING_JEWELS_WORKSHOP &&
        building_count_industry_active(RESOURCE_TIMBER_C3) <= 0) {
        if (city_resource_count(RESOURCE_FURNITURE) <= 0 && city_resource_count(RESOURCE_TIMBER_C3) <= 0) {
            show(WARNING_TIMBER_NEEDED);
            if (empire_can_produce_resource(RESOURCE_TIMBER_C3, true))
                show(WARNING_BUILD_TIMBER_YARD);
            else if (!empire_can_import_resource(RESOURCE_TIMBER_C3, true))
                show(WARNING_OPEN_TRADE_TO_IMPORT);
            else if (city_int(RESOURCE_TIMBER_C3) != TRADE_STATUS_IMPORT)
                show(WARNING_TRADE_IMPORT_RESOURCE);
        }
    }
}

static void check_clay_access(int type) {
    if (type == BUILDING_POTTERY_WORKSHOP &&
        building_count_industry_active(RESOURCE_CLAY) <= 0) {
        if (city_resource_count(RESOURCE_POTTERY_C3) <= 0 && city_resource_count(RESOURCE_CLAY) <= 0) {
            show(WARNING_CLAY_NEEDED);
            if (empire_can_produce_resource(RESOURCE_CLAY, true))
                show(WARNING_BUILD_CLAY_PIT);
            else if (!empire_can_import_resource(RESOURCE_CLAY, true))
                show(WARNING_OPEN_TRADE_TO_IMPORT);
            else if (city_int(RESOURCE_CLAY) != TRADE_STATUS_IMPORT)
                show(WARNING_TRADE_IMPORT_RESOURCE);
        }
    }
}

void building_construction_warning_generic_checks(int type, int x, int y, int size) {
    building_construction_warning_check_food_stocks(type);
    check_workers(type);
    check_market(type);
    check_actor_access(type);
    check_gladiator_access(type);
    check_lion_access(type);
    check_charioteer_access(type);

    check_barracks(type);
    check_weapons_access(type);

    check_wall(type, x, y, size);
    check_water(type, x, y);

    check_iron_access(type);
    check_vines_access(type);
    check_olives_access(type);
    check_timber_access(type);
    check_clay_access(type);

    check_road_access(type, x, y, size);
}

void building_construction_warning_check_food_stocks(int type) {
    if (!has_warning && type == BUILDING_HOUSE_VACANT_LOT) {
        if (city_population() >= 200 && !scenario_property_rome_supplies_wheat()) {
            if (city_resource_food_percentage_produced() <= 95)
                show(WARNING_MORE_FOOD_NEEDED);
        }
    }
}

void building_construction_warning_check_reservoir(int type) {
    if (!has_warning && type == BUILDING_WATER_LIFT2) {
        if (building_count_active(BUILDING_WATER_LIFT2))
            show(WARNING_CONNECT_TO_RESERVOIR);
        else
            show(WARNING_PLACE_RESERVOIR_NEXT_TO_WATER);
    }
}
