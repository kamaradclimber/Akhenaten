#ifndef GRAPHICS_IMAGE_GROUP_H
#define GRAPHICS_IMAGE_GROUP_H

static const int PHARAOH_FORCE_OFFSET = 99999;
static const int GENERAL_OFFSET = 66;
static const int SPR_MAIN_OFFSET = 341;
static const int SPR_AMBIENT_OFFSET = 555;

enum {
    GROUP_TERRAIN_BLACK = 1,
    GROUP_TERRAIN_SHRUB = 2,
    GROUP_TERRAIN_UGLY_GRASS = 3,
    GROUP_TERRAIN_TREE = 4,
    GROUP_TERRAIN_WATER = 5,
    GROUP_TERRAIN_EARTHQUAKE = 6,
    GROUP_TERRAIN_EMPTY_LAND_ALT = 7,
    GROUP_TERRAIN_ELEVATION_ROCK = 8,
    GROUP_TERRAIN_ELEVATION = 9,
    GROUP_TERRAIN_EMPTY_LAND = 10,
    GROUP_TOP_MENU_SIDEBAR = 11,
    GROUP_SIDE_PANEL = 12,
    GROUP_SIDEBAR_ADVISORS_EMPIRE = 13,
    GROUP_MAIN_MENU_BACKGROUND = 14,
    GROUP_PANEL_BUTTON = 15,
    GROUP_FONT = 16,
    GROUP_BUILDING_TOWER = 17,
    // 18 unused
    GROUP_BUILDING_AQUEDUCT = 19,
    GROUP_TERRAIN_OVERLAY_FLAT = 20,
    GROUP_TERRAIN_OVERLAY_COLORED = 21,
    GROUP_BUILDING_MARKET = 22,
    GROUP_BUILDING_WELL = 23,
    GROUP_BUILDING_WALL = 24,
    GROUP_BUILDING_RESERVOIR = 25,
    // 26-35: houses
    GROUP_BUILDING_HOUSE_TENT = 26,
    GROUP_BUILDING_HOUSE_SHACK = 27,
    GROUP_BUILDING_HOUSE_HOVEL = 28,
    GROUP_BUILDING_HOUSE_CASA = 29,
    GROUP_BUILDING_HOUSE_INSULA_1 = 30,
    GROUP_BUILDING_HOUSE_INSULA_2 = 31,
    GROUP_BUILDING_HOUSE_VILLA_1 = 32,
    GROUP_BUILDING_HOUSE_VILLA_2 = 33,
    GROUP_BUILDING_HOUSE_PALACE_1 = 34,
    GROUP_BUILDING_HOUSE_PALACE_2 = 35,
    GROUP_BUILDING_HOUSE_VACANT_LOT = 36,
    GROUP_BUILDING_FARM_HOUSE = 37,
    GROUP_BUILDING_MARBLE_QUARRY = 38,
    GROUP_BUILDING_IRON_MINE = 39,
    GROUP_BUILDING_CLAY_PIT = 40,
    GROUP_BUILDING_SCHOOL = 41,
    GROUP_BUILDING_LIBRARY = 42,
    GROUP_BUILDING_ACADEMY = 43,
    GROUP_BUILDING_WINE_WORKSHOP = 44,
    GROUP_BUILDING_AMPHITHEATER = 45, GROUP_BUILDING_BANDSTAND = 45,
    GROUP_BUILDING_THEATER = 46, GROUP_BUILDING_BOOTH = 46,
    GROUP_EMPIRE_MAP = 47,
    GROUP_BUILDING_COLOSSEUM = 48, GROUP_BUILDING_PAVILLION = 48,
    GROUP_BUILDING_GLADIATOR_SCHOOL = 49,
    GROUP_BUILDING_LION_HOUSE = 50,
    GROUP_BUILDING_ACTOR_COLONY = 51,
    GROUP_BUILDING_CHARIOT_MAKER = 52,
    GROUP_BUILDING_FOUNTAIN_4 = 53,
    GROUP_BUILDING_FOUNTAIN_1 = 54,
    GROUP_BUILDING_FOUNTAIN_2 = 55,
    GROUP_BUILDING_FOUNTAIN_3 = 56,
    GROUP_FIGURE_LABOR_SEEKER = 57,
    GROUP_TERRAIN_PLAZA = 58,
    GROUP_TERRAIN_GARDEN = 59,
    GROUP_BUILDING_WORKSHOP_RAW_MATERIAL = 60,
    GROUP_BUILDING_STATUE = 61,
    GROUP_BUILDING_SENATE = 62,
    GROUP_BUILDING_FORUM = 63,
    GROUP_BUILDING_PREFECTURE = 64,
    GROUP_BUILDING_TIMBER_YARD = 65,
    GROUP_BUILDING_FORT = 66,
    GROUP_BUILDING_BARBER = 67, GROUP_BUILDING_DENTIST = 67,
    GROUP_BUILDING_DOCTOR = 68,
    GROUP_BUILDING_BATHHOUSE_WATER = 69,
    GROUP_BUILDING_HOSPITAL = 70,
    GROUP_BUILDING_TEMPLE_CERES = 71,
    GROUP_BUILDING_TEMPLE_NEPTUNE = 72,
    GROUP_BUILDING_TEMPLE_MERCURY = 73,
    GROUP_BUILDING_TEMPLE_MARS = 74,
    GROUP_BUILDING_TEMPLE_VENUS = 75,
    GROUP_BUILDING_ORACLE = 76,
    GROUP_BUILDING_SHIPYARD = 77,
    GROUP_BUILDING_DOCK_1 = 78,
    GROUP_BUILDING_WHARF = 79,
    GROUP_BUILDING_ENGINEERS_POST = 81,
    GROUP_BUILDING_WAREHOUSE = 82,
    GROUP_BUILDING_WAREHOUSE_STORAGE_EMPTY = 83,
    GROUP_BUILDING_WAREHOUSE_STORAGE_FILLED = 84,
    GROUP_BUILDING_GOVERNORS_HOUSE = 85,
    GROUP_BUILDING_GOVERNORS_VILLA = 86,
    GROUP_BUILDING_GOVERNORS_PALACE = 87,
    GROUP_FIGURE_BATHHOUSE_WORKER = 88,
    GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS = 89,
    GROUP_MESSAGE_ICON = 90,
    GROUP_FIGURE_PRIEST = 91,
    GROUP_SIDEBAR_BUTTONS = 92,
    GROUP_LABOR_PRIORITY_LOCK = 94,
    GROUP_PANEL_WINDOWS = 95,
    GROUP_OK_CANCEL_SCROLL_BUTTONS = 96,
    GROUP_FIGURE_CARTPUSHER_CART = 97,
    GROUP_FIGURE_ACTOR = 98, GROUP_FIGURE_JUGGLER = 98,
    GROUP_BUILDING_GRANARY = 99,
    GROUP_BUILDING_FARMLAND = 100,
    GROUP_FIGURE_LION_TAMER = 101, GROUP_FIGURE_DANCER = 101,
    GROUP_FIGURE_EXPLOSION = 102,
    GROUP_OVERLAY_COLUMN = 103,
    GROUP_FIGURE_TAX_COLLECTOR = 104,
    GROUP_FIGURE_SCHOOL_CHILD = 105,
    GROUP_FIGURE_MARKET_LADY = 106,
    GROUP_FIGURE_CARTPUSHER = 107,
    GROUP_FIGURE_MIGRANT = 108,
    GROUP_FIGURE_LION_TAMER_WHIP = 109,
    GROUP_FIGURE_ENGINEER = 110,
    GROUP_FIGURE_GLADIATOR = 111, GROUP_FIGURE_MUSICIAN = 111,
    GROUP_TERRAIN_ROAD = 112,
    GROUP_TERRAIN_RUBBLE = 114,
    GROUP_FIGURE_CRIMINAL = 115,
    GROUP_FIGURE_BARBER = 116,
    GROUP_FIGURE_PREFECT = 117,
    GROUP_FIGURE_HOMELESS = 118,
    GROUP_TERRAIN_RUBBLE_TENT = 119,
    GROUP_TERRAIN_RUBBLE_GENERAL = 120,
    GROUP_FIGURE_PREFECT_WITH_BUCKET = 121,
    GROUP_BUILDING_OIL_WORKSHOP = 122,
    GROUP_BUILDING_WEAPONS_WORKSHOP = 123,
    GROUP_BUILDING_FURNITURE_WORKSHOP = 124,
    GROUP_BUILDING_POTTERY_WORKSHOP = 125,
    GROUP_FIGURE_FORT_FLAGS = 126,
    GROUP_FIGURE_FORT_STANDARD_ICONS = 127,
    GROUP_ADVISOR_ICONS = 128,
    GROUP_RESOURCE_ICONS = 129,
    GROUP_FIGURE_TRADE_CARAVAN = 130,
    GROUP_FIGURE_MIGRANT_CART = 131,
    GROUP_DIALOG_BACKGROUND = 132,
    GROUP_SUNKEN_TEXTBOX_BACKGROUND = 133,
    GROUP_CONTEXT_ICONS = 134,
    GROUP_TERRAIN_DESIRABILITY = 135,
    GROUP_ADVISOR_BACKGROUND = 136,
    GROUP_EDITOR_SIDEBAR_BUTTONS = 137,
    GROUP_TERRAIN_MEADOW = 138,
    GROUP_FIGURE_MAP_FLAG_FLAGS = 139,
    GROUP_FIGURE_MAP_FLAG_ICONS = 140,
    GROUP_MINIMAP_EMPTY_LAND = 141,
    GROUP_MINIMAP_WATER = 142,
    GROUP_MINIMAP_TREE = 143,
    GROUP_MINIMAP_ROCK = 145,
    GROUP_MINIMAP_MEADOW = 146,
    GROUP_MINIMAP_ROAD = 147,
    GROUP_MINIMAP_HOUSE = 148,
    GROUP_MINIMAP_BUILDING = 149,
    GROUP_MINIMAP_WALL = 150,
    GROUP_MINIMAP_AQUEDUCT = 151,
    GROUP_MINIMAP_BLACK = 152,
    GROUP_FIGURE_FLOTSAM_0 = 153,
    GROUP_FIGURE_FLOTSAM_1 = 154,
    GROUP_FIGURE_FLOTSAM_2 = 155,
    GROUP_FIGURE_FLOTSAM_3 = 156,
    GROUP_POPULATION_GRAPH_BAR = 157,
    GROUP_BULLET = 158,
    GROUP_MESSAGE_IMAGES = 159,
    GROUP_WIN_GAME_BACKGROUND = 160,
    GROUP_CONFIG = 161,
    GROUP_LOGO = 162,
    GROUP_FIGURE_LION = 163,
    GROUP_BUILDING_BRIDGE = 164,
    GROUP_FIGURE_SHIP = 165,
    GROUP_BUILDING_BARRACKS = 166,
    GROUP_BUILDING_DOCK_2 = 168,
    GROUP_BUILDING_DOCK_3 = 169,
    GROUP_BUILDING_DOCK_4 = 170,
    GROUP_BUILDING_DOCK_DOCKERS = 171,
    GROUP_EMPIRE_PANELS = 172,
    GROUP_EMPIRE_RESOURCES = 173,
    GROUP_EMPIRE_CITY = 174,
    GROUP_EMPIRE_CITY_TRADE = 175,
    GROUP_EMPIRE_CITY_DISTANT_ROMAN = 176,
    GROUP_EMPIRE_TRADE_ROUTE_TYPE = 179,
    GROUP_BUILDING_NATIVE = 183,
    GROUP_BUILDING_MISSION_POST = 184,
    GROUP_BUILDING_BATHHOUSE_NO_WATER = 185,
    GROUP_RATINGS_COLUMN = 189,
    GROUP_BIG_PEOPLE = 190,
    GROUP_BUILDING_THEATER_SHOW = 191, GROUP_JUGGLERS_SHOW = 191,
    GROUP_BUILDING_AMPHITHEATER_SHOW = 192, GROUP_DANCERS_SHOW = 192,
    GROUP_BUILDING_COLOSSEUM_SHOW = 193, GROUP_MUSICIANS_SHOW = 193,
    GROUP_FIGURE_TOWER_SENTRY = 194,
    GROUP_RATINGS_BACKGROUND = 195,
    GROUP_FORT_FORMATIONS = 197,
    GROUP_FIGURE_MISSILE = 198,
    GROUP_MESSAGE_ADVISOR_BUTTONS = 199,
    GROUP_FIGURE_BALLISTA = 200,
    GROUP_BUILDING_MILITARY_ACADEMY = 201,
    GROUP_BUILDING_FORT_JAVELIN = 202,
    GROUP_BUILDING_FORT_LEGIONARY = 204,
    GROUP_BUILDING_TRIUMPHAL_ARCH = 205,
    GROUP_FIGURE_SEAGULLS = 206,
    GROUP_TERRAIN_WATER_SHORE = 207,
    GROUP_BORDERED_BUTTON = 208,
    GROUP_FIGURE_DELIVERY_BOY = 209,
    GROUP_BUILDING_MARKET_FANCY = 210,
    GROUP_BUILDING_BATHHOUSE_FANCY_WATER = 211,
    GROUP_BUILDING_BATHHOUSE_FANCY_NO_WATER = 212,
    GROUP_BUILDING_HIPPODROME_1 = 213, GROUP_BUILDING_SENET_HOUSE = 213,
    GROUP_BUILDING_HIPPODROME_2 = 214,
    GROUP_FIGURE_CHARIOTEER = 215,
    GROUP_TERRAIN_ACCESS_RAMP = 216,
    GROUP_FIGURE_HIPPODROME_HORSE_1 = 217,
    GROUP_FIGURE_HIPPODROME_HORSE_2 = 218,
    GROUP_FIGURE_HIPPODROME_CART_1 = 219,
    GROUP_FIGURE_HIPPODROME_CART_2 = 220,
    GROUP_BUILDING_SENATE_FANCY = 221,
    GROUP_FORT_ICONS = 222,
    GROUP_EMPIRE_FOREIGN_CITY = 223,
    GROUP_GOD_BOLT = 225,
    GROUP_FIGURE_SHIPWRECK = 226,
    GROUP_PLAGUE_SKULL = 227,
    GROUP_FIGURE_DOCTOR_SURGEON = 228,
    GROUP_FIGURE_PATRICIAN = 229,
    GROUP_FIGURE_MISSIONARY = 230,
    GROUP_FIGURE_TEACHER_LIBRARIAN = 231,
    GROUP_FIGURE_FORT_MOUNTED = 232,
    GROUP_FIGURE_SHEEP = 233,
    GROUP_FIGURE_WOLF = 234, GROUP_FIGURE_OSTRICH = 234,
    GROUP_FIGURE_ZEBRA = 235,
    GROUP_FIGURE_CAESAR_LEGIONARY = 236,
    GROUP_FIGURE_CARTPUSHER_CART_MULTIPLE_FOOD = 237,
    GROUP_BUILDING_TRADE_CENTER_FLAG = 238,
    GROUP_TERRAIN_ROCK = 239,
    GROUP_TERRAIN_ENTRY_EXIT_FLAGS = 240,
    GROUP_FIGURE_FORT_STANDARD_POLE = 241,
    GROUP_FIGURE_FLOTSAM_SHEEP = 242,
    GROUP_TRADE_AMOUNT = 243,
    GROUP_SELECT_MISSION_BACKGROUND = 244,
    GROUP_SELECT_MISSION = 245,
    GROUP_CCK_BACKGROUND = 246,
    GROUP_SCENARIO_IMAGE = 247,
    GROUP_BULIDING_GATEHOUSE = 248,
    GROUP_FIGURE_CARTPUSHER_CART_MULTIPLE_RESOURCE = 250,
    GROUP_LOADING_SCREEN = 251,
    GROUP_INTERMEZZO_BACKGROUND = 252,
    GROUP_PANEL_WINDOWS_DESERT = 253,
    GROUP_SELECT_MISSION_BUTTON = 254,
    //
    
    GROUP_BUILDING_VILLAGE_PALACE = 47 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET, // general
    GROUP_BUILDING_TOWN_PALACE = 39 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_BUILDING_CITY_PALACE = 18 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_BUILDING_ROADBLOCK = 98 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_BUILDING_FARM_CROPS_PH = 100 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_SINGLE_SQUARE = 107 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_BOOTH_SQUARE = 112 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_BANDSTAND_SQUARE = 58 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_PAVILLION_SQUARE = 50 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FESTIVAL_SQUARE = 49 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,

    GROUP_PRIEST_OSIRIS = 197 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET, // sprmain
    GROUP_PRIEST_RA = 210 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_PRIEST_SETH = 193 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_PRIEST_PTAH = 187 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_PRIEST_BAST = 208 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_MARKET_LADY_2 = 18 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_POLICEMAN = 20 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_REED_GATHERER = 37 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_HUNTER = 45 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_HUNTER_ARROW = 0 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_TRADE_CARAVAN_DONKEY = 52 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_WATER_CARRIER = 59 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_WORKER_PH = 116 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_MORTUARY = 195 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_MAGISTRATE = 212 + SPR_MAIN_OFFSET + PHARAOH_FORCE_OFFSET,
    //
    GROUP_FIGURE_ARCHER_PH = 62 + SPR_MAIN_OFFSET,
    GROUP_FIGURE_INFANTRY_PH = 65 + SPR_MAIN_OFFSET,
    GROUP_FIGURE_CHARIOTEER_PH = 68 + SPR_MAIN_OFFSET,

    GROUP_WATER_LIFT = 1 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET, // sprambient
    GROUP_GRANARY_ANIM_PH = 47 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_WAREHOUSE_ANIM_PH = 51 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
//    GROUP_DOCK_WAITING = 55 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
//    GROUP_DOCK_UNLOADING = 56 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_MINES = 48 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_DANCERS = 6 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_JUGGLERS = 7 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_MUSICIANS = 9 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_FISH = 8 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_HIPPO = 22 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_ANTILOPE = 30 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_FIGURE_HUNTER2 = 36 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_SHIP_BUILDING_1 = 45 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_SHIP_BUILDING_2 = 52 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_SHIP_BUILDING_3 = 53 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_SHIP_BUILDING_4 = 54 + SPR_AMBIENT_OFFSET + PHARAOH_FORCE_OFFSET,

    GROUP_BUILDING_TEMPLE_COMPLEX_BAST = 753,
    GROUP_BUILDING_TEMPLE_COMPLEX_OSIRIS = 760,
    GROUP_BUILDING_TEMPLE_COMPLEX_PTAH = 767,
    GROUP_BUILDING_TEMPLE_COMPLEX_RA = 774,
    GROUP_BUILDING_TEMPLE_COMPLEX_SETH = 781,

    GROUP_SYSTEM_GRAPHICS = 0,
    GROUP_PANEL_WINDOWS_PH = 300,
    GROUP_BUTTON_EXCLAMATION = 193 + GENERAL_OFFSET,
    GROUP_MENU_ADVISOR_BUTTONS = 159 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_MENU_ADVISOR_LAYOUT = 160 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_TINY_ARROWS = 212 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_GOD_ANGEL = 9 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,

    GROUP_TERRAIN_GRASS_PH = 46 + PHARAOH_FORCE_OFFSET, // terrain
    GROUP_TERRAIN_DEEPWATER = 61 + PHARAOH_FORCE_OFFSET,
    GROUP_TERRAIN_GRASS_PH_EDGES = 64 + PHARAOH_FORCE_OFFSET,
    GROUP_TERRAIN_FLOODPLAIN = 31 + PHARAOH_FORCE_OFFSET,
    GROUP_TERRAIN_FLOODSYSTEM = 33 + PHARAOH_FORCE_OFFSET,
    GROUP_TERRAIN_DIRT_ROAD = 43 + PHARAOH_FORCE_OFFSET,
    GROUP_TERRAIN_REEDS = 11 + PHARAOH_FORCE_OFFSET,
    GROUP_TERRAIN_REEDS_GROWN = 32 + PHARAOH_FORCE_OFFSET,

    GROUP_TERRAIN_OVERLAY_WATER = 59 + PHARAOH_FORCE_OFFSET,
    GROUP_TERRAIN_OVERLAY_WATER_HOUSE = 60 + PHARAOH_FORCE_OFFSET,

    GROUP_MINIMAP_REEDS = 144 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_MINIMAP_FLOODPLAIN = 146 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,
    GROUP_MINIMAP_DUNES = 211 + GENERAL_OFFSET + PHARAOH_FORCE_OFFSET,

    GROUP_DEBUG_ARROWPOST = 24 + PHARAOH_FORCE_OFFSET,
    GROUP_DEBUG_WIREFRAME_TILE = 41 + PHARAOH_FORCE_OFFSET,
    GROUP_SUNKEN_TILE = 20 + PHARAOH_FORCE_OFFSET,
    GROUP_TERRAIN_ORE_ROCK = 42 + PHARAOH_FORCE_OFFSET,

    //
    GROUP_MAX_GROUP
};

#endif // GRAPHICS_IMAGE_GROUP_H
