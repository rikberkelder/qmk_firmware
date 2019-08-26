#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                         KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSLS,
				 KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                         KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
				 LCTL_T(KC_ESC),     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                         KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    LALT_T(KC_QUOT),
				 KC_LSPO,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,   KC_NO,  KC_NO,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSPC,
				 KC_LBRC, LGUI_T(KC_SPC), LT(2,KC_MINS), LT(1,KC_EQL), RCTL_T(KC_ENT), KC_RBRC),

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

	[3] = LAYOUT(
				 MI_C_4, MI_Cs_4, MI_D_4, MI_Ds_4, MI_E_4, MI_F_4, MI_Fs_4, MI_G_4, MI_Gs_4, MI_A_4, MI_As_4, MI_B_4,
      MI_C_3, MI_Cs_3, MI_D_3, MI_Ds_3, MI_E_3, MI_F_3, MI_Fs_3, MI_G_3, MI_Gs_3, MI_A_3, MI_As_3, MI_B_3,
      MI_C_2, MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2, MI_F_2, MI_Fs_2, MI_G_2, MI_Gs_2, MI_A_2, MI_As_2, MI_B_2,
				 MI_C_1, MI_Cs_1, MI_D_1, MI_Ds_1, MI_E_1, MI_F_1, KC_NO, KC_NO, MI_Fs_1, MI_G_1, MI_Gs_1, MI_A_1, MI_As_1, MI_B_1,
				 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(3)),

	[4] = LAYOUT(KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,     KC_NO,      KC_NO,      KC_NO,     KC_NO,     KC_NO,
				 KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
				 KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,      KC_NO,
				 KC_NO,     KC_NO,       KC_NO,    KC_NO,    KC_NO,      KC_NO,  KC_NO, KC_NO,     KC_NO,   KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,
				 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),


};

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_sethsv_noeeprom(200,255,255);
}

void matrix_scan_user(void) {
  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  if(old_layer != new_layer){
	switch (new_layer) {
	default:
	  rgblight_sethsv_noeeprom(180,255,255);
	  break;
	case 1:
	  rgblight_sethsv_noeeprom(200,255,255);
	  break;
	}
  }

 }

