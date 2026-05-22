#include "quantum.h"

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_set_cursor(0, 0);
        oled_write_ln("LEFT OLED OK", false);
    } else {
        oled_set_cursor(0, 0);
        oled_write_ln("RIGHT OLED OK", false);
    }
    return true;
}
