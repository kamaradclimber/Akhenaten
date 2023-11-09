#include "demand_changes.h"

#include "game/resource.h"
#include "graphics/boilerplate.h"
#include "graphics/elements/button.h"
#include "graphics/elements/generic_button.h"
#include "graphics/elements/lang_text.h"
#include "graphics/elements/panel.h"
#include "graphics/view/view.h"
#include "graphics/image_groups.h"
#include "graphics/text.h"
#include "graphics/window.h"
#include "input/input.h"
#include "scenario/editor.h"
#include "scenario/property.h"
#include "window/editor/attributes.h"
#include "window/editor/edit_demand_change.h"
#include "window/editor/map.h"
#include "game/game.h"

static void button_demand_change(int id, int param2);

static generic_button buttons[] = {
  {20, 42, 290, 25, button_demand_change, button_none, 0, 0},
  {20, 72, 290, 25, button_demand_change, button_none, 1, 0},
  {20, 102, 290, 25, button_demand_change, button_none, 2, 0},
  {20, 132, 290, 25, button_demand_change, button_none, 3, 0},
  {20, 162, 290, 25, button_demand_change, button_none, 4, 0},
  {20, 192, 290, 25, button_demand_change, button_none, 5, 0},
  {20, 222, 290, 25, button_demand_change, button_none, 6, 0},
  {20, 252, 290, 25, button_demand_change, button_none, 7, 0},
  {20, 282, 290, 25, button_demand_change, button_none, 8, 0},
  {20, 312, 290, 25, button_demand_change, button_none, 9, 0},
  {320, 42, 290, 25, button_demand_change, button_none, 10, 0},
  {320, 72, 290, 25, button_demand_change, button_none, 11, 0},
  {320, 102, 290, 25, button_demand_change, button_none, 12, 0},
  {320, 132, 290, 25, button_demand_change, button_none, 13, 0},
  {320, 162, 290, 25, button_demand_change, button_none, 14, 0},
  {320, 192, 290, 25, button_demand_change, button_none, 15, 0},
  {320, 222, 290, 25, button_demand_change, button_none, 16, 0},
  {320, 252, 290, 25, button_demand_change, button_none, 17, 0},
  {320, 282, 290, 25, button_demand_change, button_none, 18, 0},
  {320, 312, 290, 25, button_demand_change, button_none, 19, 0},
};

static int focus_button_id;

static void draw_background() {
    window_editor_map_draw_all();
}

static void draw_foreground() {
    painter ctx = game.painter();

    graphics_set_to_dialog();

    outer_panel_draw(0, 0, 40, 23);
    lang_text_draw(44, 94, 20, 14, FONT_LARGE_BLACK_ON_LIGHT);
    lang_text_draw_centered(13, 3, 0, 342, 640, FONT_NORMAL_BLACK_ON_LIGHT);

    for (int i = 0; i < 20; i++) {
        int x, y;
        if (i < 10) {
            x = 20;
            y = 42 + 30 * i;
        } else {
            x = 320;
            y = 42 + 30 * (i - 10);
        }
        button_border_draw(x, y, 290, 25, focus_button_id == i + 1);
        editor_demand_change demand_change;
        scenario_editor_demand_change_get(i, &demand_change);
        if (demand_change.year) {
            text_draw_number(demand_change.year, '+', " ", x + 10, y + 6, FONT_NORMAL_BLACK_ON_LIGHT);
            lang_text_draw_year(scenario_property_start_year() + demand_change.year, x + 35, y + 6, FONT_NORMAL_BLACK_ON_LIGHT);
            int offset = demand_change.resource + resource_image_offset(demand_change.resource, RESOURCE_IMAGE_ICON);
            ImageDraw::img_generic(ctx, image_id_from_group(GROUP_EDITOR_RESOURCE_ICONS) + offset, x + 115, y + 3);
            int width = lang_text_draw(44, 97, x + 140, y + 6, FONT_NORMAL_BLACK_ON_LIGHT);
            width
              += text_draw_number(demand_change.route_id, '@', " ", x + 140 + width, y + 6, FONT_NORMAL_BLACK_ON_LIGHT);
            lang_text_draw(44, demand_change.is_rise ? 99 : 98, x + 140 + width, y + 6, FONT_NORMAL_BLACK_ON_LIGHT);
        } else {
            lang_text_draw_centered(44, 96, x, y + 6, 290, FONT_NORMAL_BLACK_ON_LIGHT);
        }
    }

    graphics_reset_dialog();
}

static void handle_input(const mouse* m, const hotkeys* h) {
    if (generic_buttons_handle_mouse(mouse_in_dialog(m), 0, 0, buttons, 20, &focus_button_id))
        return;
    if (input_go_back_requested(m, h))
        window_editor_attributes_show();
}

static void button_demand_change(int id, int param2) {
    window_editor_edit_demand_change_show(id);
}

void window_editor_demand_changes_show(void) {
    window_type window = {WINDOW_EDITOR_DEMAND_CHANGES, draw_background, draw_foreground, handle_input};
    window_show(&window);
}
