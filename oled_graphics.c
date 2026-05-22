#include "oled_graphics.h"
#include "quantum.h"

// 16x16 pixel-art logo
static const char PROGMEM logo_bitmap[] = {
    0x3C,0x42,0xA9,0x85,0x85,0xA9,0x91,0x91,
    0x91,0xA9,0x85,0x85,0xA9,0x42,0x3C,0x00
};

void render_logo(void) {
    oled_set_cursor(0, 0);
    oled_write_raw_P(logo_bitmap, sizeof(logo_bitmap));
}

void render_wpm(void) {
    uint8_t wpm = get_current_wpm();
    oled_set_cursor(5, 0);
    oled_write_P(PSTR("WPM:"), false);

    char buf[4];
    snprintf(buf, sizeof(buf), "%03d", wpm);
    oled_write(buf, false);
}

void render_caps(void) {
    oled_set_cursor(0, 2);
    if (host_keyboard_led_state().caps_lock) {
        oled_write_P(PSTR("CAPS ON "), false);
    } else {
        oled_write_P(PSTR("caps off"), false);
    }
}

void render_layer_icon(uint8_t layer) {
    oled_set_cursor(0, 4);
    switch (layer) {
        case 0: oled_write_P(PSTR("[BASE]"), false); break;
        case 1: oled_write_P(PSTR("[LOWR]"), false); break;
        case 2: oled_write_P(PSTR("[RASE]"), false); break;
        case 3: oled_write_P(PSTR("[ADJ ]"), false); break;
        default: oled_write_P(PSTR("[????]"), false); break;
    }
}
