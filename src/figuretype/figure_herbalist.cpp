#include "figure_herbalist.h"

#include "core/profiler.h"
#include "figure/service.h"

#include "js/js_game.h"

figures::model_t<figure_herbalist> herbalist_m;

ANK_REGISTER_CONFIG_ITERATOR(config_load_figure_herbalist);
void config_load_figure_herbalist() {
    herbalist_m.load();
}

void figure_herbalist::figure_before_action() {
    building* b = home();
    if (!b->is_valid() || !b->has_figure(0, id())) {
        poof();
    }
}

void figure_herbalist::figure_action() {
    OZZY_PROFILER_SECTION("Game/Run/Tick/Figure/Herbalist");
    //    building *b = building_get(building_id);
    switch (action_state()) {
    default:
        advance_action(ACTION_11_RETURNING_FROM_PATROL);
        break;

    case FIGURE_ACTION_149_CORPSE:
        break;

    case FIGURE_ACTION_60_HERBALIST_CREATED:
        advance_action(ACTION_10_GOING);
        break;

    case FIGURE_ACTION_61_HERBALIST_ENTERING_EXITING:
    case 9:
        do_enterbuilding(true, home());
        break;

    case ACTION_10_GOING:
    case FIGURE_ACTION_62_HERBALIST_ROAMING:
        do_roam(TERRAIN_USAGE_ROADS, ACTION_11_RETURNING_FROM_PATROL);
        break;

    case ACTION_11_RETURNING_FROM_PATROL:
    case FIGURE_ACTION_63_HERBALIST_RETURNING:
        do_returnhome(TERRAIN_USAGE_ROADS, FIGURE_ACTION_61_HERBALIST_ENTERING_EXITING);
        break;
    }
}

figure_sound_t figure_herbalist::get_sound_reaction(pcstr key) const {
    return herbalist_m.sounds[key];
}

const animations_t &figure_herbalist::anim() const {
    return herbalist_m.anim;
}

sound_key figure_herbalist::phrase_key() const {
    if (base.local_data.herbalist.see_low_health > 0) {
        return "have_malaria_risk_here";
    } else {
        return "no_threat_malaria_here";
    }

    return {};
}

void apothecary_coverage(building* b, figure *f, int&) {
    b->data.house.apothecary = MAX_COVERAGE;
    if (b->common_health < 50) {
        b->common_health++;
        if (b->common_health < 20) {
            f->local_data.herbalist.see_low_health++;
        }
    }
}

int figure_herbalist::provide_service() {
    int minmax = 0;
    int houses_serviced = figure_provide_service(tile(), &base, minmax, apothecary_coverage);
    return houses_serviced;
}
