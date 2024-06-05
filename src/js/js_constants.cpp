#include "js_constants.h"

#include "js_defines.h"

#include "input/hotkey.h"
#include "mujs/mujs.h"
#include "window/file_dialog.h"
#include "overlays/city_overlay_fwd.h"
#include "building/building.h"
#include "graphics/image_desc.h"
#include "graphics/image_groups.h"
#include "graphics/font.h"
#include "city/labor.h"

#include "sound/sound_city.h"

#define _R(name) js_newnumber(J, name); js_setglobal(J, #name);
void js_register_game_constants(js_State *J) {
   _R(FILE_TYPE_SAVED_GAME)
   _R(FILE_DIALOG_LOAD)
}

void js_register_city_images(js_State *J) {
#define REGISTER_IMG(a, b) REGISTER_GLOBAL_CONSTANT(J, a)
#include "graphics/indexes.h"
#undef REGISTER_IMG
}

void js_register_collection_images(js_State *J) {
   _R(PACK_UNLOADED)
   _R(PACK_TERRAIN)
   _R(PACK_GENERAL)
   _R(PACK_SPR_MAIN)
   _R(PACK_SPR_AMBIENT)
   _R(PACK_EMPIRE)
   _R(PACK_FONT)
   _R(PACK_TEMPLE)
   _R(PACK_MONUMENT)
   _R(PACK_ENEMY)
   _R(PACK_EXPANSION)
   _R(PACK_EXPANSION_SPR)
   _R(PACK_MASTABA)
   _R(PACK_TEMPLE_RA)
   _R(PACK_CUSTOM)
}

void js_register_city_walkers(js_State *J) {
#define REGISTER_FIGURE(a, b) REGISTER_GLOBAL_CONSTANT(J, a)
#include "figure/figure_type_indexes.h"
#undef REGISTER_FIGURE
}

void js_register_city_sound_constants(js_State *J) {
   _R(SOUND_CHANNEL_CITY_HOUSE_SLUM)
   _R(SOUND_CHANNEL_CITY_HOUSE_POOR)
   _R(SOUND_CHANNEL_CITY_HOUSE_MEDIUM)
   _R(SOUND_CHANNEL_CITY_HOUSE_GOOD)
   _R(SOUND_CHANNEL_CITY_HOUSE_POSH)
   _R(SOUND_CHANNEL_CITY_BOOTH)
   _R(SOUND_CHANNEL_CITY_BANDSTAND)
   _R(SOUND_CHANNEL_CITY_PAVILION)
   _R(SOUND_CHANNEL_CITY_SENET_HOUSE)
   _R(SOUND_CHANNEL_CITY_JUGGLER_SCHOOL)
   _R(SOUND_CHANNEL_CITY_DANCE_SCHOOL)
   _R(SOUND_CHANNEL_CITY_CONSERVATORY)
   _R(SOUND_CHANNEL_CITY_GARDEN)
   _R(SOUND_CHANNEL_CITY_APOTHECARY)
   _R(SOUND_CHANNEL_CITY_PHYSICIAN)
   _R(SOUND_CHANNEL_CITY_MORTUARY)
   _R(SOUND_CHANNEL_CITY_TOWER)
   _R(SOUND_CHANNEL_CITY_TEMPLE_OSIRIS)
   _R(SOUND_CHANNEL_CITY_TEMPLE_RA)
   _R(SOUND_CHANNEL_CITY_TEMPLE_PTAH)
   _R(SOUND_CHANNEL_CITY_TEMPLE_SETH)
   _R(SOUND_CHANNEL_CITY_TEMPLE_BAST)
   _R(SOUND_CHANNEL_CITY_SHRINE_OSIRIS)
   _R(SOUND_CHANNEL_CITY_SHRINE_RA)
   _R(SOUND_CHANNEL_CITY_SHRINE_PTAH)
   _R(SOUND_CHANNEL_CITY_SHRINE_SETH)
   _R(SOUND_CHANNEL_CITY_SHRINE_BAST)
   _R(SOUND_CHANNEL_CITY_MARKET)
   _R(SOUND_CHANNEL_CITY_GRANARY)
   _R(SOUND_CHANNEL_CITY_STORAGE_YARD)
   _R(SOUND_CHANNEL_CITY_SHIPYARD)
   _R(SOUND_CHANNEL_CITY_DOCK)
   _R(SOUND_CHANNEL_CITY_WHARF)
   _R(SOUND_CHANNEL_CITY_PALACE)
   _R(SOUND_CHANNEL_CITY_ENGINEERS_POST)
   _R(SOUND_CHANNEL_CITY_FORUM)
   _R(SOUND_CHANNEL_CITY_WATER_SUPPLY)
   _R(SOUND_CHANNEL_CITY_WELL)
   _R(SOUND_CHANNEL_CITY_BURNING_RUIN)
   _R(SOUND_CHANNEL_CITY_GRAIN_FARM)
   _R(SOUND_CHANNEL_CITY_FIG_FARM)
   _R(SOUND_CHANNEL_CITY_QUARRY)
   _R(SOUND_CHANNEL_CITY_GOLD_MINE)
   _R(SOUND_CHANNEL_CITY_TIMBER_YARD)
   _R(SOUND_CHANNEL_CITY_CLAY_PIT)
   _R(SOUND_CHANNEL_CITY_WEAPONS_WORKSHOP)
   _R(SOUND_CHANNEL_CITY_POTTERY_WORKSHOP)
   _R(SOUND_CHANNEL_CITY_EMPTY_LAND)
   _R(SOUND_CHANNEL_CITY_RIVER)
   _R(SOUND_CHANNEL_CITY_HUNTER_LOUDGE)
   _R(SOUND_CHANNEL_CITY_POLICE)
   _R(SOUND_CHANNEL_CITY_ROCK)
   _R(SOUND_CHANNEL_CITY_STATUE)
   _R(SOUND_CHANNEL_CITY_TAX_COLLECTOR)
   _R(SOUND_CHANNEL_CITY_DENTIST)
   _R(SOUND_CHANNEL_CITY_MANSION)
   _R(SOUND_CHANNEL_CITY_TREE)
   _R(SOUND_CHANNEL_CITY_WATER)
   _R(SOUND_CHANNEL_CITY_SHRUB)
   _R(SOUND_CHANNEL_CITY_CANAL)
   _R(SOUND_CHANNEL_CITY_MEADOW)
   _R(SOUND_CHANNEL_CITY_FLOODPLAIN)
   _R(SOUND_CHANNEL_CITY_MARSHLAND)
   _R(SOUND_CHANNEL_CITY_CHICKFARM)
   _R(SOUND_CHANNEL_CITY_COWFARM)
}

void js_register_city_buildings(js_State *J) {
#define REGISTER_BLD(a, b) REGISTER_GLOBAL_CONSTANT(J, a)
#include "building/building_type_indexes.h"
#undef REGISTER_BLD
}

void js_register_ui_fonts(js_State *J) {
   _R(FONT_SMALL_PLAIN)
   _R(FONT_NORMAL_BLACK_ON_LIGHT)
   _R(FONT_NORMAL_WHITE_ON_DARK)
   _R(FONT_NORMAL_YELLOW)
   _R(FONT_NORMAL_BLUE)
   _R(FONT_LARGE_BLACK_ON_LIGHT)
   _R(FONT_LARGE_BLACK_ON_DARK)
   _R(FONT_SMALL_OUTLINED)
   _R(FONT_NORMAL_BLACK_ON_DARK)
   _R(FONT_SMALL_SHADED)
}

void js_register_city_labor_category(js_State *J) {
   _R(LABOR_CATEGORY_NONE)
   _R(LABOR_CATEGORY_FOOD_PRODUCTION)
   _R(LABOR_CATEGORY_INDUSTRY_COMMERCE)
   _R(LABOR_CATEGORY_ENTERTAINMENT)
   _R(LABOR_CATEGORY_RELIGION)
   _R(LABOR_CATEGORY_EDUCATION)
   _R(LABOR_CATEGORY_WATER_HEALTH)
   _R(LABOR_CATEGORY_INFRASTRUCTURE)
   _R(LABOR_CATEGORY_GOVERNMENT)
   _R(LABOR_CATEGORY_MILITARY)
   _R(LABOR_CATEGORY_SIZE)
}

void js_register_city_overlays(js_State *J) {
   _R(OVERLAY_NONE)
   _R(OVERLAY_WATER)
   _R(OVERLAY_RELIGION)
   _R(OVERLAY_FIRE)
   _R(OVERLAY_DAMAGE)
   _R(OVERLAY_CRIME)
   _R(OVERLAY_ENTERTAINMENT)
   _R(OVERLAY_BOOTH)
   _R(OVERLAY_BANDSTAND)
   _R(OVERLAY_PAVILION)
   _R(OVERLAY_SENET_HOUSE)
   _R(OVERLAY_EDUCATION)
   _R(OVERLAY_SCRIBAL_SCHOOL)
   _R(OVERLAY_LIBRARY)
   _R(OVERLAY_ACADEMY)
   _R(OVERLAY_APOTHECARY)
   _R(OVERLAY_DENTIST)
   _R(OVERLAY_PHYSICIAN)
   _R(OVERLAY_MORTUARY)
   _R(OVERLAY_TAX_INCOME)
   _R(OVERLAY_FOOD_STOCKS)
   _R(OVERLAY_DESIRABILITY)
   _R(OVERLAY_WORKERS_UNUSED)
   _R(OVERLAY_NATIVE)
   _R(OVERLAY_PROBLEMS)
   _R(OVERLAY_RELIGION_OSIRIS)
   _R(OVERLAY_RELIGION_RA)
   _R(OVERLAY_RELIGION_PTAH)
   _R(OVERLAY_RELIGION_SETH)
   _R(OVERLAY_RELIGION_BAST)
   _R(OVERLAY_FERTILITY)
   _R(OVERLAY_BAZAAR_ACCESS)
   _R(OVERLAY_ROUTING)
   _R(OVERLAY_HEALTH)
   _R(OVERLAY_LABOR)
   _R(OVERLAY_COUTHOUSE)
}

void js_register_terrain(js_State *J) {
   _R(TERRAIN_USAGE_ANY)
   _R(TERRAIN_USAGE_ROADS)
   _R(TERRAIN_USAGE_ENEMY)
   _R(TERRAIN_USAGE_PREFER_ROADS)
   _R(TERRAIN_USAGE_WALLS)
   _R(TERRAIN_USAGE_ANIMAL)
}

void js_register_city_resources(js_State *J) {
    _R(RESOURCE_NONE)
    _R(RESOURCE_MIN)
    _R(RESOURCE_FOOD_MIN)
    _R(RESOURCE_GRAIN)
    _R(RESOURCE_MEAT)
    _R(RESOURCE_LETTUCE)
    _R(RESOURCE_CHICKPEAS)
    _R(RESOURCE_POMEGRANATES)
    _R(RESOURCE_FIGS)
    _R(RESOURCE_FISH)
    _R(RESOURCE_GAMEMEAT)
    _R(RESOURCES_FOODS_MAX)
    _R(RESOURCE_STRAW)
    _R(RESOURCE_WEAPONS)
    _R(RESOURCE_CLAY)
    _R(RESOURCE_BRICKS)
    _R(RESOURCE_POTTERY)
    _R(RESOURCE_BARLEY)
    _R(RESOURCE_BEER)
    _R(RESOURCE_FLAX)
    _R(RESOURCE_LINEN)
    _R(RESOURCE_GEMS)
    _R(RESOURCE_LUXURY_GOODS)
    _R(RESOURCE_TIMBER)
    _R(RESOURCE_GOLD)
    _R(RESOURCE_REEDS)
    _R(RESOURCE_PAPYRUS)
    _R(RESOURCE_STONE)
    _R(RESOURCE_LIMESTONE)
    _R(RESOURCE_GRANITE)
    _R(RESOURCE_UNUSED12)
    _R(RESOURCE_CHARIOTS)
    _R(RESOURCE_COPPER)
    _R(RESOURCE_SANDSTONE)
    _R(RESOURCE_OIL)
    _R(RESOURCE_HENNA)
    _R(RESOURCE_PAINT)
    _R(RESOURCE_LAMPS)
    _R(RESOURCE_MARBLE)
    _R(RESOURCES_MAX)
    _R(RESOURCE_DEBEN)
    _R(RESOURCE_TROOPS)
}