#include "scenario.h"

#include "city/resource.h"
#include "empire/trade_route.h"
#include "game/difficulty.h"
#include "game/settings.h"
#include "scenario/data.h"

struct scenario_t scenario;

int scenario_is_saved(void) {
    return scenario.is_saved;
}

void scenario_save_state(scenario_data_buffers *data) {
    // header
    buffer_write_i16(data->header, scenario.start_year);
    buffer_write_i16(data->header, 0);
    buffer_write_i16(data->header, scenario.empire.id);
    buffer_skip(data->header, 8);

    // requests
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_i16(data->requests, scenario.requests[i].year);
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_i16(data->requests, scenario.requests[i].resource);
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_i16(data->requests, scenario.requests[i].amount);
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_i16(data->requests, scenario.requests[i].deadline_years);

    // invasions
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        buffer_write_i16(data->invasions, scenario.invasions[i].year);
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        buffer_write_i16(data->invasions, scenario.invasions[i].type);
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        buffer_write_i16(data->invasions, scenario.invasions[i].amount);
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        buffer_write_i16(data->invasions, scenario.invasions[i].from);
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        buffer_write_i16(data->invasions, scenario.invasions[i].attack_type);

    // info 1
    buffer_write_i16(data->info1, 0);
    buffer_write_i32(data->info1, scenario.initial_funds);
    buffer_write_i16(data->info1, scenario.enemy_id);
    buffer_write_i16(data->info1, 0);
    buffer_write_i16(data->info1, 0);
    buffer_write_i16(data->info1, 0);
    buffer_write_i32(data->info1, scenario.map.width);
    buffer_write_i32(data->info1, scenario.map.height);
    buffer_write_i32(data->info1, scenario.map.grid_start);
    buffer_write_i32(data->info1, scenario.map.grid_border_size);
    buffer_write_raw(data->info1, scenario.brief_description, env_sizes().MAX_BRIEF_DESCRIPTION);
    buffer_write_raw(data->info1, scenario.briefing, env_sizes().MAX_BRIEFING);

    // request comply dialog
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_u8(data->request_comply_dialogs, scenario.requests[i].can_comply_dialog_shown);

    // info 2
    buffer_write_i16(data->info2, scenario.image_id);
    buffer_write_i16(data->info2, scenario.is_open_play);
    buffer_write_i16(data->info2, scenario.player_rank);

    // herds
    for (int i = 0; i < env_sizes().MAX_HERD_POINTS; i++)
        buffer_write_i16(data->herds, scenario.herd_points[i].x);
    for (int i = 0; i < env_sizes().MAX_HERD_POINTS; i++)
        buffer_write_i16(data->herds, scenario.herd_points[i].y);

    // demand changes
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++)
        buffer_write_i16(data->demands, scenario.demand_changes[i].year);
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++)
        buffer_write_u8(data->demands, scenario.demand_changes[i].month);
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++)
        buffer_write_u8(data->demands, scenario.demand_changes[i].resource);
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++)
        buffer_write_u8(data->demands, scenario.demand_changes[i].route_id);
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++)
        buffer_write_u8(data->demands, scenario.demand_changes[i].is_rise);

    // price changes
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++)
        buffer_write_i16(data->price_changes, scenario.price_changes[i].year);
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++)
        buffer_write_u8(data->price_changes, scenario.price_changes[i].month);
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++)
        buffer_write_u8(data->price_changes, scenario.price_changes[i].resource);
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++)
        buffer_write_u8(data->price_changes, scenario.price_changes[i].amount);
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++)
        buffer_write_u8(data->price_changes, scenario.price_changes[i].is_rise);

    // events
    buffer_write_i32(data->events, scenario.gladiator_revolt.enabled);
    buffer_write_i32(data->events, scenario.gladiator_revolt.year);
    buffer_write_i32(data->events, scenario.emperor_change.enabled);
    buffer_write_i32(data->events, scenario.emperor_change.year);
    buffer_write_i32(data->events, scenario.random_events.sea_trade_problem);
    buffer_write_i32(data->events, scenario.random_events.land_trade_problem);
    buffer_write_i32(data->events, scenario.random_events.raise_wages);
    buffer_write_i32(data->events, scenario.random_events.lower_wages);
    buffer_write_i32(data->events, scenario.random_events.contaminated_water);
    buffer_write_i32(data->events, scenario.random_events.iron_mine_collapse);
    buffer_write_i32(data->events, scenario.random_events.clay_pit_flooded);

    // fishing points
    for (int i = 0; i < env_sizes().MAX_FISH_POINTS; i++)
        buffer_write_i16(data->fishing_points, scenario.fishing_points[i].x);
    for (int i = 0; i < env_sizes().MAX_FISH_POINTS; i++)
        buffer_write_i16(data->fishing_points, scenario.fishing_points[i].y);

    // requests extra
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_u8(data->request_extra, scenario.requests[i].favor);
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        buffer_write_u8(data->request_extra, scenario.invasions[i].month);
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_u8(data->request_extra, scenario.requests[i].month);
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_u8(data->request_extra, scenario.requests[i].state);
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_u8(data->request_extra, scenario.requests[i].visible);
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        buffer_write_u8(data->request_extra, scenario.requests[i].months_to_comply);

    // rome wheat supplies enabled
    buffer_write_i32(data->wheat, scenario.rome_supplies_wheat);

    // allowed buildings
    int MAX_ALLOWED_BUILDINGS = 50;
    if (GAME_ENV == ENGINE_ENV_PHARAOH)
        MAX_ALLOWED_BUILDINGS = 114;
    for (int i = 0; i < MAX_ALLOWED_BUILDINGS; i++)
        buffer_write_i16(data->allowed_builds, scenario.allowed_buildings[i]);

    // win criteria
    buffer_write_i32(data->win_criteria, scenario.win_criteria.culture.goal);
    buffer_write_i32(data->win_criteria, scenario.win_criteria.prosperity.goal);
    buffer_write_i32(data->win_criteria, scenario.win_criteria.peace.goal);
    buffer_write_i32(data->win_criteria, scenario.win_criteria.favor.goal);
    if (GAME_ENV == ENGINE_ENV_PHARAOH) {
        buffer_write_i32(data->win_criteria, scenario.win_criteria.ph_goal1.goal);
        buffer_write_i32(data->win_criteria, scenario.win_criteria.ph_goal2.goal);
    }
    buffer_write_u8(data->win_criteria, scenario.win_criteria.culture.enabled);
    buffer_write_u8(data->win_criteria, scenario.win_criteria.prosperity.enabled);
    buffer_write_u8(data->win_criteria, scenario.win_criteria.peace.enabled);
    buffer_write_u8(data->win_criteria, scenario.win_criteria.favor.enabled);
    if (GAME_ENV == ENGINE_ENV_PHARAOH) {
        buffer_write_u8(data->win_criteria, scenario.win_criteria.ph_goal1.enabled);
        buffer_write_u8(data->win_criteria, scenario.win_criteria.ph_goal2.enabled);
    }
    buffer_write_i32(data->win_criteria, scenario.win_criteria.time_limit.enabled);
    buffer_write_i32(data->win_criteria, scenario.win_criteria.time_limit.years);
    buffer_write_i32(data->win_criteria, scenario.win_criteria.survival_time.enabled);
    buffer_write_i32(data->win_criteria, scenario.win_criteria.survival_time.years);
    buffer_write_i32(data->win_criteria, scenario.earthquake.severity);
    if (GAME_ENV == ENGINE_ENV_C3)
        buffer_write_i32(data->win_criteria, scenario.earthquake.year);
    else if (GAME_ENV == ENGINE_ENV_PHARAOH)
        buffer_write_i16(data->win_criteria, 0);
    buffer_write_i32(data->win_criteria, scenario.win_criteria.population.enabled);
    buffer_write_i32(data->win_criteria, scenario.win_criteria.population.goal);

    // map points
    buffer_write_i16(data->map_points, scenario.earthquake_point.x);
    buffer_write_i16(data->map_points, scenario.earthquake_point.y);
    buffer_write_i16(data->map_points, scenario.entry_point.x);
    buffer_write_i16(data->map_points, scenario.entry_point.y);
    buffer_write_i16(data->map_points, scenario.exit_point.x);
    buffer_write_i16(data->map_points, scenario.exit_point.y);

    // invasion points
    for (int i = 0; i < env_sizes().MAX_INVASION_POINTS; i++)
        buffer_write_i16(data->invasion_points, scenario.invasion_points[i].x);
    for (int i = 0; i < env_sizes().MAX_INVASION_POINTS; i++)
        buffer_write_i16(data->invasion_points, scenario.invasion_points[i].y);

    // river points
    buffer_write_i16(data->river_points, scenario.river_entry_point.x);
    buffer_write_i16(data->river_points, scenario.river_entry_point.y);
    buffer_write_i16(data->river_points, scenario.river_exit_point.x);
    buffer_write_i16(data->river_points, scenario.river_exit_point.y);

    // info 3
    buffer_write_i32(data->info3, scenario.rescue_loan);
    buffer_write_i32(data->info3, scenario.win_criteria.milestone25_year);
    buffer_write_i32(data->info3, scenario.win_criteria.milestone50_year);
    buffer_write_i32(data->info3, scenario.win_criteria.milestone75_year);
    buffer_write_i32(data->info3, scenario.native_images.hut);
    buffer_write_i32(data->info3, scenario.native_images.meeting);
    buffer_write_i32(data->info3, scenario.native_images.crops);
    buffer_write_u8(data->info3, scenario.climate);
    buffer_write_u8(data->info3, scenario.flotsam_enabled);
    buffer_write_i16(data->info3, 0);

    // empire
    buffer_write_i32(data->empire, scenario.empire.is_expanded);
    buffer_write_i32(data->empire, scenario.empire.expansion_year);
    buffer_write_u8(data->empire, scenario.empire.distant_battle_roman_travel_months);
    buffer_write_u8(data->empire, scenario.empire.distant_battle_enemy_travel_months);
    buffer_write_u8(data->empire, scenario.open_play_scenario_id);
    buffer_write_u8(data->empire, 0);

    scenario.is_saved = 1;
}
void scenario_load_state(scenario_data_buffers *data) {

    // C3:
    // 1. header
    // 2. requests/invasions
    // 3. map info 1
    // 4. request can-comply dialog
    // 5. map info 2
    // 6. herds
    // 7. demands
    // 8. random events
    // 9. fishing
    // 10. other request data
    // 11. wheat
    // 12. allowed buildings
    // 13. win criteria
    // 14. map points
    // 15. invasion entry points
    // 16. river entry points
    // 17. map info 3
    // 18. empire info

    // 1. header (14)
    scenario.start_year = buffer_read_i16(data->header); // 2 bytes
    buffer_skip(data->header, 2);
    scenario.empire.id = buffer_read_i16(data->header); // 2 bytes
    buffer_skip(data->header, 8);

    // 3. map info (614)
    // (12)
    scenario.initial_funds = buffer_read_i32(data->info1); // 4
    scenario.enemy_id = buffer_read_i16(data->info1); // 2
    buffer_skip(data->info1, 6);
    // (16)
    scenario.map.width = buffer_read_i32(data->info1); // 4
    scenario.map.height = buffer_read_i32(data->info1); // 4
    scenario.map.grid_start = buffer_read_i32(data->info1); // 4
    scenario.map.grid_border_size = buffer_read_i32(data->info1); // 4
    // (64 + 522 = 576)
    buffer_read_raw(data->info1, scenario.brief_description, env_sizes().MAX_BRIEF_DESCRIPTION);
    buffer_read_raw(data->info1, scenario.briefing, env_sizes().MAX_BRIEFING);

    // 5. map info 2 (6)
    scenario.image_id = buffer_read_i16(data->info2); // 2
    scenario.is_open_play = buffer_read_i16(data->info2); // 2
    scenario.player_rank = buffer_read_i16(data->info2); // 2

    // 17. map info 3 (30 + 2)
    scenario.rescue_loan = buffer_read_i32(data->info3); // 4                                                       70 17 00 00 0A 00 00 00 14
    scenario.win_criteria.milestone25_year = buffer_read_i32(data->info3); // 4                00 00 00 1E 00 00 00 0B 0B 00 00 0D 0B 00 00 44
    scenario.win_criteria.milestone50_year = buffer_read_i32(data->info3); // 4                0B 00 00 00 01 00 00
    scenario.win_criteria.milestone75_year = buffer_read_i32(data->info3); // 4
    scenario.native_images.hut = buffer_read_i32(data->info3); // 4
    scenario.native_images.meeting = buffer_read_i32(data->info3); // 4
    scenario.native_images.crops = buffer_read_i32(data->info3); // 4
    scenario.climate = buffer_read_u8(data->info3); // 1
    scenario.flotsam_enabled = buffer_read_u8(data->info3); // 1
    buffer_skip(data->info3, 2); //                                                                            00 00

    // 8. random events (44)
    // events
    scenario.gladiator_revolt.enabled = buffer_read_i32(data->events); // 4                              00 00 00 00 00 00 00 00 00 00 00 00 00
    scenario.gladiator_revolt.year = buffer_read_i32(data->events); // 4                        00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    scenario.emperor_change.enabled = buffer_read_i32(data->events); // 4                       00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    scenario.emperor_change.year = buffer_read_i32(data->events); // 4
    scenario.random_events.sea_trade_problem = buffer_read_i32(data->events); // 4
    scenario.random_events.land_trade_problem = buffer_read_i32(data->events); // 4
    scenario.random_events.raise_wages = buffer_read_i32(data->events); // 4
    scenario.random_events.lower_wages = buffer_read_i32(data->events); // 4
    scenario.random_events.contaminated_water = buffer_read_i32(data->events); // 4
    scenario.random_events.iron_mine_collapse = buffer_read_i32(data->events); // 4
    scenario.random_events.clay_pit_flooded = buffer_read_i32(data->events); // 4

    // 13. win criteria (52 / 60)
    scenario.win_criteria.culture.goal = buffer_read_i32(data->win_criteria); // 4                                                                 2D
    scenario.win_criteria.prosperity.goal = buffer_read_i32(data->win_criteria); // 4                 00 00 00 19 00 00 00 1E 00 00 00 46 00 00 00 01
    scenario.win_criteria.peace.goal = buffer_read_i32(data->win_criteria); // 4                      01 01 01 00 00 00 00 00 00 00 00 00 00 00 00 00
    scenario.win_criteria.favor.goal = buffer_read_i32(data->win_criteria); // 4                      00 00 00 03 00 00 00 02 00 00 00 01 00 00 00 C4
    if (GAME_ENV == ENGINE_ENV_PHARAOH) { //                                           09 00 00
        scenario.win_criteria.ph_goal1.goal = buffer_read_i32(data->win_criteria); // 4
        scenario.win_criteria.ph_goal2.goal = buffer_read_i32(data->win_criteria); // 4
    }
    scenario.win_criteria.culture.enabled = buffer_read_u8(data->win_criteria); // 1
    scenario.win_criteria.prosperity.enabled = buffer_read_u8(data->win_criteria); // 1
    scenario.win_criteria.peace.enabled = buffer_read_u8(data->win_criteria); // 1
    scenario.win_criteria.favor.enabled = buffer_read_u8(data->win_criteria); // 1
    if (GAME_ENV == ENGINE_ENV_PHARAOH) {
        scenario.win_criteria.ph_goal1.enabled = buffer_read_u8(data->win_criteria); // 1
        scenario.win_criteria.ph_goal2.enabled = buffer_read_u8(data->win_criteria); // 1
    }
    scenario.win_criteria.time_limit.enabled = buffer_read_i32(data->win_criteria); // 4
    scenario.win_criteria.time_limit.years = buffer_read_i32(data->win_criteria); // 4
    scenario.win_criteria.survival_time.enabled = buffer_read_i32(data->win_criteria); // 4
    scenario.win_criteria.survival_time.years = buffer_read_i32(data->win_criteria); // 4
    scenario.earthquake.severity = buffer_read_i32(data->win_criteria); // 4
    if (GAME_ENV == ENGINE_ENV_C3) {
        scenario.earthquake.year = buffer_read_i32(data->win_criteria); // 4
    } else if (GAME_ENV == ENGINE_ENV_PHARAOH)
        buffer_skip(data->win_criteria, 2); // 2
    scenario.win_criteria.population.enabled = buffer_read_i32(data->win_criteria); // 4
    scenario.win_criteria.population.goal = buffer_read_i32(data->win_criteria); // 4

    // 14. map points (12)
    scenario.earthquake_point.x = buffer_read_i16(data->map_points); // 2                                    20 00 09 00 00 00 1C 00 4F 00 29 00
    scenario.earthquake_point.y = buffer_read_i16(data->map_points); // 2
    scenario.entry_point.x = buffer_read_i16(data->map_points); // 2
    scenario.entry_point.y = buffer_read_i16(data->map_points); // 2
    scenario.exit_point.x = buffer_read_i16(data->map_points); // 2
    scenario.exit_point.y = buffer_read_i16(data->map_points); // 2

    // 16. river entry points (8)
    scenario.river_entry_point.x = buffer_read_i16(data->river_points); // 2                                                                       00
    scenario.river_entry_point.y = buffer_read_i16(data->river_points); // 2                          00 20 00 00 00 38 00
    scenario.river_exit_point.x = buffer_read_i16(data->river_points); // 2
    scenario.river_exit_point.y = buffer_read_i16(data->river_points); // 2

    // 18. empire (11 + 1)
    scenario.empire.is_expanded = buffer_read_i32(data->empire); // 4                                                      00 00 00 00 00 00 00
    scenario.empire.expansion_year = buffer_read_i32(data->empire); // 4                        00 00 00 32 41
    scenario.empire.distant_battle_roman_travel_months = buffer_read_u8(data->empire); // 1
    scenario.empire.distant_battle_enemy_travel_months = buffer_read_u8(data->empire); // 1
    scenario.open_play_scenario_id = buffer_read_u8(data->empire); // 1
    buffer_skip(data->empire, 1); //                                                                      00

    // 11. wheat??? (4)
    scenario.rome_supplies_wheat = buffer_read_i32(data->wheat); // 4                                               00 00 00 00

    // 2. requests (160)
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        scenario.requests[i].year = buffer_read_i16(data->requests); // 40
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        scenario.requests[i].resource = buffer_read_i16(data->requests); // 40
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        scenario.requests[i].amount = buffer_read_i16(data->requests); // 40
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        scenario.requests[i].deadline_years = buffer_read_i16(data->requests); // 40
    // invasions (200 + 2)
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        scenario.invasions[i].year = buffer_read_i16(data->invasions); // 40
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        scenario.invasions[i].type = buffer_read_i16(data->invasions); // 40
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        scenario.invasions[i].amount = buffer_read_i16(data->invasions); // 40
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        scenario.invasions[i].from = buffer_read_i16(data->invasions); // 40
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++)
        scenario.invasions[i].attack_type = buffer_read_i16(data->invasions); // 40
    buffer_skip(data->invasions, 2);

    // 15. invasion entry points (32)
    for (int i = 0; i < env_sizes().MAX_INVASION_POINTS; i++) //                                                                                FF
        scenario.invasion_points[i].x = buffer_read_i16(data->invasion_points); // 2                     FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
    for (int i = 0; i < env_sizes().MAX_INVASION_POINTS; i++) //                                   FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
        scenario.invasion_points[i].y = buffer_read_i16(data->invasion_points); // 2

    // 4. request can-comply dialog (20)
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        scenario.requests[i].can_comply_dialog_shown = buffer_read_u8(data->request_comply_dialogs); // 1

    // 6. animal herds (16)
    for (int i = 0; i < env_sizes().MAX_HERD_POINTS; i++) //                                                09 00 3C 00 00 00 00 00 35 00 1A 00 00
        scenario.herd_points[i].x = buffer_read_i16(data->herds); // 2                         00 00 00
    for (int i = 0; i < env_sizes().MAX_HERD_POINTS; i++) //
        scenario.herd_points[i].y = buffer_read_i16(data->herds); // 2

    // 7. demands (240)
    // demand changes (120)
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++) //                                             00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.demand_changes[i].year = buffer_read_i16(data->demands); // 2                   00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++) //                                    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.demand_changes[i].month = buffer_read_u8(data->demands); // 1                   00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++) //                                    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.demand_changes[i].resource = buffer_read_u8(data->demands); // 1                00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++) //                                    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.demand_changes[i].route_id = buffer_read_u8(data->demands); // 1                00 00 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_DEMAND_CHANGES; i++)
        scenario.demand_changes[i].is_rise = buffer_read_u8(data->demands); // 1
    // price changes (120)
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++) //                                                                      05 00 08 00 0F
        scenario.price_changes[i].year = buffer_read_i16(data->price_changes); // 2                    00 14 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++) //                                     00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.price_changes[i].month = buffer_read_u8(data->price_changes); // 1                    00 00 00 07 06 04 02 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++) //                                     00 00 00 00 00 00 00 03 0C 0E 0F 00 00 00 00 00
        scenario.price_changes[i].resource = buffer_read_u8(data->price_changes); // 1                 00 00 00 00 00 00 00 00 00 00 00 14 14 14 0F 00
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++) //                                     00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01
        scenario.price_changes[i].amount = buffer_read_u8(data->price_changes); // 1                   01 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_PRICE_CHANGES; i++) //                                     00 00 00
        scenario.price_changes[i].is_rise = buffer_read_u8(data->price_changes); // 1

    // 9. fishing (32)
    for (int i = 0; i < env_sizes().MAX_FISH_POINTS; i++) //                                                                                    00
        scenario.fishing_points[i].x = buffer_read_i16(data->fishing_points); // 2                      00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_FISH_POINTS; i++) //                                       00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.fishing_points[i].y = buffer_read_i16(data->fishing_points); // 2

    // 10. other request data (120)
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++) //                                                                                       08
        scenario.requests[i].favor = buffer_read_u8(data->request_extra); // 1                         08 0A 0A 0A 0A 0A 0A 0A 0A 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_INVASIONS; i++) //                                         00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.invasions[i].month = buffer_read_u8(data->request_extra); // 1                        00 00 00 00 00 00 00 03 08 02 04 08 02 04 05 08
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++) //                                          08 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.requests[i].month = buffer_read_u8(data->request_extra); // 1                         00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++) //                                          00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
        scenario.requests[i].state = buffer_read_u8(data->request_extra); // 1                         00 00 00 18 18 18 18 18 18 18 18 18 18 00 00 00
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++) //                                          00 00 00 00 00 00 00
        scenario.requests[i].visible = buffer_read_u8(data->request_extra); // 1
    for (int i = 0; i < env_sizes().MAX_REQUESTS; i++)
        scenario.requests[i].months_to_comply = buffer_read_u8(data->request_extra); // 1

    // 12. allowed buildings (100 / 228)
    int MAX_ALLOWED_BUILDINGS = 50;
    if (GAME_ENV == ENGINE_ENV_PHARAOH)
        MAX_ALLOWED_BUILDINGS = 114;
    for (int i = 0; i < MAX_ALLOWED_BUILDINGS; i++) //                                                                  01 00 01 00 01
        scenario.allowed_buildings[i] = buffer_read_i16(data->allowed_builds); // 2                     00 01 00 01 00 00 00 01 00 01 00 01 00 01 00 00
                                                    //                                 00 01 00 01 00 01 00 01 00 00 00 01 00 01 00 01
                                                    //                                 00 01 00 01 00 01 00 01 00 01 00 01 00 01 00 01
                                                    //                                 00 00 00 00 00 00 00 01 00 01 00 01 00 01 00 01
                                                    //                                 00 00 00 01 00 00 00 01 00 01 00 01 00 01 00 01
                                                    //                                 00 01 00 00 00 01 00 00 00 00 00 01 00 01 00


    scenario.is_saved = 1;
}

void scenario_settings_init(void) {
    scenario.settings.campaign_mission = 0;
    scenario.settings.campaign_rank = 0;
    scenario.settings.is_custom = 0;
    scenario.settings.starting_favor = difficulty_starting_favor();
    scenario.settings.starting_personal_savings = 0;
}
void scenario_settings_init_mission(void) {
    scenario.settings.starting_favor = difficulty_starting_favor();
    scenario.settings.starting_personal_savings = setting_personal_savings_for_mission(scenario.settings.campaign_rank);
}

void scenario_fix_patch_trade(int mission_id) { // todo: only C3
    // Damascus, allow import of marble
    if (mission_id == 15)
        trade_route_init(1, RESOURCE_MARBLE, 15);
}

void scenario_settings_save_state(buffer *part1, buffer *part2, buffer *part3, buffer *player_name, buffer *scenario_name)
{
    switch (GAME_ENV) {
        case ENGINE_ENV_C3:
            buffer_write_i32(part1, scenario.settings.campaign_mission);
            break;
        case ENGINE_ENV_PHARAOH:
            buffer_write_i8(part1, scenario.settings.campaign_mission);
            break;
    }

    buffer_write_i32(part2, scenario.settings.starting_favor);
    buffer_write_i32(part2, scenario.settings.starting_personal_savings);
    buffer_write_i32(part2, scenario.settings.campaign_rank);

    buffer_write_i32(part3, scenario.settings.is_custom);

    for (int i = 0; i < env_sizes().MAX_PLAYER_NAME; i++) {
        buffer_write_u8(player_name, 0);
    }
    buffer_write_raw(player_name, scenario.settings.player_name, env_sizes().MAX_PLAYER_NAME);
    buffer_write_raw(scenario_name, scenario.scenario_name, env_sizes().MAX_SCENARIO_NAME);
}
void scenario_settings_load_state(buffer *part1, buffer *part2, buffer *part3, buffer *player_name, buffer *scenario_name)
{
    switch (GAME_ENV) {
        case ENGINE_ENV_C3:
            scenario.settings.campaign_mission = buffer_read_i32(part1);
            break;
        case ENGINE_ENV_PHARAOH:
            scenario.settings.campaign_mission = buffer_read_i8(part1);
            break;
    }

    scenario.settings.starting_favor = buffer_read_i32(part2);
    scenario.settings.starting_personal_savings = buffer_read_i32(part2);
    scenario.settings.campaign_rank = buffer_read_i32(part2);

    scenario.settings.is_custom = buffer_read_i32(part3);

    buffer_skip(player_name, env_sizes().MAX_PLAYER_NAME);
    buffer_read_raw(player_name, scenario.settings.player_name, env_sizes().MAX_PLAYER_NAME);
    buffer_read_raw(scenario_name, scenario.scenario_name, env_sizes().MAX_SCENARIO_NAME);
}
