#pragma once

#include "building/building.h"

class building_tax_collector : public building_impl {
public:
    BUILDING_METAINFO(BUILDING_TAX_COLLECTOR, building_tax_collector)
    building_tax_collector(building &b) : building_impl(b) {}

    virtual bool is_workshop() const override { return false; }
    virtual void spawn_figure() override;
    virtual void window_info_background(object_info &c) override;
    virtual e_overlay get_overlay() const override { return OVERLAY_TAX_INCOME; }
    virtual void update_month() override;
    virtual e_sound_channel_city sound_channel() const override { return SOUND_CHANNEL_CITY_TAX_COLLECTOR; }
    virtual bool draw_ornaments_and_animations_height(painter &ctx, vec2i point, tile2i tile, color color_mask) override;
    virtual const static_params &params() const override;
};

class building_tax_collector_up : public building_tax_collector {
public:
    BUILDING_METAINFO(BUILDING_TAX_COLLECTOR_UPGRADED, building_tax_collector)
    building_tax_collector_up(building &b) : building_tax_collector(b) {}
};