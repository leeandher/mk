#include QMK_KEYBOARD_H
#include "typehud.h"
#include "bongo.h"

// clang-format off
enum layers {
    _BASE,
    _VIA1,
    _VIA2,
    _VIA3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_all(
    KC_VOLU,          KC_ESC,   KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,    KC_F7,  KC_F8,  KC_F9,   KC_F10,    KC_F11,    KC_F12,   KC_PSCR,  KC_PAUS,           KC_MNXT,
    KC_VOLD, KC_F13,  KC_GRV,   KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,     KC_7,   KC_8,   KC_9,    KC_0,      KC_MINS,   KC_EQL,   KC_BSPC,  KC_DEL,   KC_HOME, KC_MPRV,
             KC_F14,  KC_TAB,   KC_Q,    KC_W,   KC_E,   KC_R,           KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,      KC_P,      KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,
             KC_F15,  KC_CAPS,  KC_A,    KC_S,   KC_D,   KC_F,           KC_G,     KC_H,   KC_J,   KC_K,    KC_L,      KC_SCLN,   KC_QUOT,  KC_ENT,             KC_PGUP,
             KC_F16,  KC_LSFT,  KC_NUHS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,    KC_SLSH,   KC_RSFT,            KC_UP,    KC_PGDN,
             KC_F17,  KC_LCTL,  KC_LGUI, KC_LALT,     MO(_VIA1),         KC_SPC,   KC_SPC,                  MO(_VIA1), KC_RALT,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
    [_VIA1] = LAYOUT_all(
    KC_NO,          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,         KC_NO,
    KC_NO,  RESET,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  RESET, KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,          KC_NO,    KC_NO,                  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),
    [_VIA2] = LAYOUT_all(
    KC_NO,          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,         KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,          KC_NO,    KC_NO,                  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),
    [_VIA3] = LAYOUT_all(
    KC_NO,          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,         KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,          KC_NO,    KC_NO,                  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),
};
// clang-format on

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_clear();
    if (is_keyboard_master()) 
        typehud_init();
        
    if (is_keyboard_left())
        return OLED_ROTATION_0;
    else
        return OLED_ROTATION_180;

}

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        typehud_render();
    } else {
        bongo_render(0, 0);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    typehud_process_record(record);
    return true;
}

bool should_process_keypress(void) {
    return true;
}
