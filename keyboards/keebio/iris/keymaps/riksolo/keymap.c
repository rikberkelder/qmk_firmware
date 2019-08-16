#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                         KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSLS,
				 KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                         KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
				 KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                         KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
				 KC_LSPO,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,   KC_ASTG,  TG(2),    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSPC,
				 LCTL_T(KC_LBRC), KC_SPC, LGUI_T(KC_MINS), LT(1,KC_EQL), KC_ENT, LALT_T(KC_RBRC)),

	[1] = LAYOUT(KC_F1,     KC_F2,       KC_F3,      KC_F4,      KC_F5,      KC_F5,                         KC_F7,     KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
				 LGUI(KC_MINS), KC_WH_U, KC_BTN2,    KC_MS_U,    KC_BTN1,    KC_HOME,                       KC_END,    KC_NO,      KC_NO,      KC_NO,      KC_NO,  LGUI(KC_EQL),
				 KC_NO,     KC_WH_D,     KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_NO,                         KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,      KC_NO,
				 KC_CAPS,    KC_NO,      KC_LBRC,    KC_LPRN,    KC_LT,      KC_LCBR,  RESET, KC_END,       KC_RCBR,   KC_GT,      KC_RCBR,    KC_RBRC,    KC_NO,      KC_RCTL,
				 KC_LSFT, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO),

	[2] = LAYOUT(RGB_HUI,     RGB_MOD,       RGB_M_P,      KC_F4,      KC_F5,      KC_F5,                         KC_F7,     KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
				 RGB_HUD,     RGB_TOG,       KC_NO,      KC_NO,      KC_NO,      KC_HOME,                       KC_END,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
				 TG(2),     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,      KC_NO,
				 KC_LSFT,     KC_NO,       KC_LBRC,    KC_LPRN,    KC_LT,      KC_LCBR,  KC_HOME, KC_END,     KC_RCBR,   KC_GT,      KC_RCBR,    KC_RBRC,    KC_NO,      KC_NO,
				 KC_LSFT, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO),
};

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_sethsv(180,255,255);
}
