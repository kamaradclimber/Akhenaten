#pragma once

#include <cstdint>

enum e_image_id : uint16_t {
    IMG_NONE = 0,
    IMG_IMMIGRANT = 1,
    IMG_IMMIGRANT_DEATH = 2,
    IMG_EMIGRANT = 3,
    IMG_EMIGRANT_DEATH = 4,
    IMG_HOMELESS = 5,
    IMG_HOMELESS_DEATH = 6,
    IMG_FISHIHG_WHARF_ANIM = 7,
    IMG_CARTPUSHER = 8,
    IMG_CARTPUSHER_DEATH = 9,
    IMG_FISHING_BOAT = 10,
    IMG_FISHING_BOAT_WORK = 11,
    IMG_FISHING_BOAT_DEATH = 13,
    IMG_FISHING_BOAT_IDLE = 14,
    IMG_FLOTSAM = 15,
    IMG_LABOR_SEEKER = 16,
    IMG_LABOR_SEEKER_DEATH = 17,
    IMG_FISHING_POINT = 18,
    IMG_FISHING_POINT_BUBLES = 19,
    IMG_ENGINEER = 20,
    IMG_ENGINEER_DEATH = 21,
    IMG_WATER_SUPPLY = 22,
    IMG_WATER_SUPPLY_FANCY = 23,
    IMG_WELL = 24,
    IMG_WELL_FANCY = 25,
    IMG_EXPLOSION = 26,
    IMG_CATTLE_RANCH = 27,
    IMG_TAX_COLLECTOR = 28,
    IMG_BRICKS_WORKSHOP = 29,
    IMG_RESOURCE_GAMEMEAT = 30,
    IMG_RESOURCE_CLAY = 31,
    IMG_RESOURCE_STRAW = 32,
    IMG_RESOURCE_ICONS = 33,
    IMG_OSTRICH_WALK = 34,
    IMG_FIREMAN = 35,
    IMG_GOLD_MINE = 36,
    ANIM_GOLD_MINE = 37,
    IMG_SANDSTONE_QUARRY = 38,
    ANIM_SANDSTONE_QUARRY_1 = 39,
    ANIM_SANDSTONE_QUARRY_2 = 40,
    IMG_CARTPUSHER_CART = 41,
    IMG_SLED_SANDSTONE_SMALL = 42,
    IMG_SLED_EMPTY_SMALL = 43,
    IMG_SLED_GRANITE_SMALL = 44,
    IMG_JUGGLER_WALK = 45,
    IMG_PLAINSTONE_QUARRY = 46,
    IMG_SLED_STONE_SMALL = 47,
    IMG_SLED_LIMESTONE_SMALL = 48,
    IMG_SLED_BRICKS = 49,
    IMG_GRANARY = 50,
    IMG_GRANARY_RESOURCES = 51,
    IMG_CART_COPPER = 52,
    IMG_COPPER_MINE = 53,
    IMG_CONSERVATORY = 54,
    IMG_PHYSICIAN = 55,
    IMG_BARRACKS = 56,
    IMG_SCRIBAL_SCHOOL = 57,
    IMG_TEACHER_WALK = 58,
    IMG_TEACHER_DEATH = 59,
    IMG_SCRIBER_WALK = 60,
    IMG_SCRIBER_DEATH = 61,
    IMG_BANDSTAND_SN_S = 62,
    IMG_BANDSTAND_SN_N = 63,
    IMG_BANDSTAND_WE_W = 64,
    IMG_BANDSTAND_WE_E = 65,
    IMG_BOOTH = 66,
    IMG_BOOTH_SQUARE = 67,
    IMG_BANDSTAND_SQUARE = 68,
    IMG_MUSICIAN = 69,
    IMG_JUGGLER_SHOW = 70,
    IMG_MUSICIAN_SHOW_SN = 71,
    IMG_MUSICIAN_SHOW_WE = 72,
    IMG_CART_BARLEY = 73,
    IMG_SIDE_PANEL = 74,
    IMG_TOP_MENU_BACKGROUND = 75,
    IMG_EDITOR_SIDE_PANEL = 76,
    IMG_RESOURCE_PAPYRUS = 77,
    IMG_EMPIRE_ROUTE_HL_CLOSED = 78,
    IMG_EMPIRE_ROUTE_OPEN = 79,
    IMG_EMPIRE_ROUTE_HL_OPEN = 80,
    IMG_MINIMAP_BLACK = 81,
    IMG_MINIMAP_BRIGHT_TEAL = 82,
    IMG_MINIMAP_DARK_GREY = 83,
    IMG_MINIMAP_GREEN = 84,
    IMG_MINIMAP_DARK_RED = 85,
    IMG_MINIMAP_PURPLE = 86,
    IMG_MINIMAP_LIGHT_YELLOW = 87,
    IMG_MINIMAP_BRIGHT_BLUE = 88,
    IMG_MINIMAP_LILAC = 89,
    IMG_MINIMAP_ORANGE = 90,
    IMG_MINIMAP_SPENT_TEAL = 91,
    IMG_MINIMAP_COLOR = 92,

    IMG_SIZE
};

struct image_desc {
    int pack = 0;
    int id = 0;
    int offset = 0;
};

image_desc get_image_desc(e_image_id t);