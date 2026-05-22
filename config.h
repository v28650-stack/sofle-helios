#pragma once

// OLED timeout (60 seconds, set to 0 to never sleep)
#define OLED_TIMEOUT 60000

// Ocean Dream: define the flag used in keymap.c
#ifdef OCEAN_DREAM_ENABLE
// is_calm is set to true when Ctrl is held — calms the waves
extern bool is_calm;
#endif
