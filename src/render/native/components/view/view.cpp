
#include "view.hpp"

View::View(std::string uid, lv_obj_t* parent): BasicComponent() {
    this->type = COMP_TYPE_VIEW;
    this->uid = uid;
    this->instance = lv_obj_create(parent != nullptr ? parent : lv_scr_act());
    
    lv_obj_add_flag(this->instance, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_user_data(this->instance, this);
    this->initStyle(LV_PART_MAIN);
};

void View::initCompStyle (int32_t type) {
    this->ensureStyle(type);
    lv_style_t* style = this->style_map.at(type);

    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_top(style, 0);
    lv_style_set_radius(style, 0);
    lv_style_set_outline_width(style, 0);
    lv_style_set_outline_pad(style, 0);
    lv_style_set_border_width(style, 0);
    lv_style_set_border_side(style, LV_BORDER_SIDE_FULL);
};