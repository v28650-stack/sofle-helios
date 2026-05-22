#pragma once
// Copyright 2021 Tyler Thrailkill (@snowe/@snowe2010)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

// ============================================================
// SCREEN DIMENSIONS — Sofle uses 128x32 OLED
// ============================================================
#define WIDTH  128
#define HEIGHT 32

// ============================================================
// TUNABLE ANIMATION SETTINGS (feel free to tweak these)
// ============================================================

// How many ms between each animation frame
#define STARRY_NIGHT_ANIM_FRAME_DURATION 200

// Total animation frames before looping
#define NUMBER_OF_FRAMES 60

// --- Stars ---
#define ENABLE_STARS
#define STARS_PER_LINE        4   // stars per horizontal group
#define NUMBER_OF_STAR_LINES  2   // how many rows of stars
#define TWINKLE_PROBABILITY   50  // % chance a star twinkles each frame
#define STAR_ANIMATION_SPEED  1

// --- Shooting Stars ---
#define ENABLE_SHOOTING_STARS
#define MAX_NUMBER_OF_SHOOTING_STARS  2
#define SHOOTING_STAR_FRAMES          16
#define SHOOTING_STAR_DELAY           3
#define SHOOTING_STAR_WPM_INCREMENT   20  // one new shooting star per 20 WPM
#define SHOOTING_STAR_ANIMATION_SPEED 2

// --- Ocean Waves ---
#define ENABLE_WAVE
#define OCEAN_LINE            3   // which pixel row the ocean starts on (0-indexed 8px rows)
#define WAVE_CALM             10  // WPM below which ocean is still
#define WAVE_HEAVY_STORM      40
#define WAVE_HURRICANE        80
#define OCEAN_ANIMATION_SPEED 3

// --- Island ---
#define ENABLE_ISLAND
#define ISLAND_LINE           2   // OLED row for island
#define ISLAND_COLUMN         14  // OLED column for island
#define ISLAND_CALM           10
#define ISLAND_HEAVY_STORM    40
#define ISLAND_HURRICANE      80

// --- Moon ---
#define ENABLE_MOON
#define MOON_LINE             0
#define MOON_COLUMN           0
#define ANIMATE_MOON_EVERY_N_FRAMES 10

// ============================================================
// PUBLIC API
// ============================================================
extern bool is_calm;   // set true when Ctrl held — calms the waves

void render_ocean_dream(void);
