#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _BLANK
};

#define KC_ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST  RESET
#define KC_BL_S BL_STEP

#define KC_AQUO LALT_T(KC_QUOT)
#define KC_CESC LCTL_T(KC_ESC)
#define KC_L2MI LT(2,KC_MINS)
#define KC_L1EQ LT(1,KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CESC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,AQUO,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSPO, Z  , X  , C  , V  , B  ,    ,         , N  , M  ,COMM,DOT ,SLSH,RSPC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,SPC ,L2MI,         L1EQ,ENT ,RCTL
  //                  `----+----+----'        `----+----+----'
		),

[1] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F1  , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,WH_U,BTN2,MS_U,BTN1,HOME,               END ,    ,    ,    ,    ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,WH_D,MS_L,MS_D,MS_R,    ,               LEFT,DOWN,UP  ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     CAPS,    ,    ,    ,    ,    ,RST ,        ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,   ,          TRNS,    ,
  //                  `----+----+----'        `----+----+----'
		),

	[2] = LAYOUT(RGB_HUI,     RGB_MOD,       RGB_M_P,    KC_F4,      KC_F5,      KC_F5,                         KC_F7,     KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
		     RGB_HUD,     RGB_TOG,       KC_NO,      KC_NO,      KC_NO,      KC_HOME,                       KC_END,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
		     TG(2),       KC_NO,         KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,      KC_NO,
		     KC_LSFT,     KC_NO,         KC_LBRC,    KC_LPRN,    KC_LT,      KC_LCBR,  KC_HOME, KC_END,     KC_RCBR,   KC_GT,      KC_RCBR,    KC_RBRC,    KC_NO,      KC_NO,
		     KC_LSFT, KC_NO, KC_NO,                                                                         KC_TRNS, KC_NO, KC_NO),

	[3] = LAYOUT(
				 MI_C_4, MI_Cs_4, MI_D_4, MI_Ds_4, MI_E_4, MI_F_4, MI_Fs_4, MI_G_4, MI_Gs_4, MI_A_4, MI_As_4, MI_B_4,
				 MI_C_3, MI_Cs_3, MI_D_3, MI_Ds_3, MI_E_3, MI_F_3, MI_Fs_3, MI_G_3, MI_Gs_3, MI_A_3, MI_As_3, MI_B_3,
				 MI_C_2, MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2, MI_F_2, MI_Fs_2, MI_G_2, MI_Gs_2, MI_A_2, MI_As_2, MI_B_2,
				 MI_C_1, MI_Cs_1, MI_D_1, MI_Ds_1, MI_E_1, MI_F_1, KC_NO, KC_NO, MI_Fs_1, MI_G_1, MI_Gs_1, MI_A_1, MI_As_1, MI_B_1,
				 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(3)),

	[4] = LAYOUT(KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,      KC_NO,                       KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
		     KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,      KC_NO,                       KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
		     KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,      KC_NO,                       KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,      KC_NO,
		     KC_NO,      KC_NO,       KC_NO,       KC_NO,      KC_NO,      KC_NO,  KC_NO, KC_NO,        KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
		     KC_NO, KC_NO, KC_NO,                                                                       KC_NO, KC_NO, KC_NO),

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





//[9] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
//         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
//         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
//         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
//         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
//                           ,    ,   ,              ,    ,
  //                  `----+----+----'        `----+----+----'
//		),

