
#include "gif.hpp"

GIF::GIF(std::string uid, lv_obj_t* parent): BasicComponent() {
    this->type = COMP_TYPE_GIF;

    this->uid = uid;
    this->instance = lv_gif_create(parent != nullptr ? parent : lv_scr_act());
    
    lv_obj_add_flag(this->instance, LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_user_data(this->instance, this);
    this->initStyle(LV_PART_MAIN);
};

void GIF::setGIFBinary(uint8_t* buf, size_t len) {
    uint8_t* prev_buf = this->image_buf;
    lv_img_dsc_t_1* prev_desc = this->image_desc;
    this->image_desc = static_cast<lv_img_dsc_t_1*>(malloc(sizeof(lv_img_dsc_t_1)));
    uint8_t* img_data = GetImgDesc(buf, len, image_desc);
    this->image_buf = img_data;

    if (img_data != nullptr) {
        lv_img_set_src(this->instance, this->image_desc);
    }

    if (prev_buf != nullptr) {
        free(prev_buf);
    }
    if (prev_desc != nullptr) {
        free(prev_desc);
    }
};

GIF::~GIF () {
    if (this->image_buf != nullptr) {
        free(this->image_buf);
        this->image_buf = nullptr;
    }
    if (this->image_desc != nullptr) {
        free(this->image_desc);
        this->image_desc = nullptr;
    }
};

void GIF::initCompStyle (int32_t type) {
};