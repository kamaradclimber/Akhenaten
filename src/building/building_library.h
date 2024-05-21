#pragma once

#include "building/building.h"

class building_library : public building_impl {
public:
    BUILDING_METAINFO(BUILDING_LIBRARY, building_library);
    building_library(building &b) : building_impl(b) {}

    //virtual void on_create(int orientation) override;
    virtual void window_info_background(object_info &c) override;
    virtual void spawn_figure() override;
    virtual e_overlay get_overlay() const { return OVERLAY_LIBRARY; }
    //virtual bool draw_ornaments_and_animations_height(painter &ctx, vec2i point, tile2i tile, color mask) override;
    virtual void update_count() const override;
    //virtual void update_month() override;
    //virtual void on_place_checks() override;
};