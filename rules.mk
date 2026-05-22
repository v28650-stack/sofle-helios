OLED_ENABLE = yes
WPM_ENABLE = yes
OCEAN_DREAM_ENABLE = yes
ENCODER_MAP_ENABLE = yes

# Include Ocean Dream source files
SRC += ocean_dream.c

# Firmware size optimisation (RP2040 has plenty of flash, but good practice)
LTO_ENABLE = yes
