# This file intentionally left blank

LTO_ENABLE = yes            # Link Time Optimization enabled

# OLED_ENABLE = yes
# OLED_DRIVER = ssd1306
# OLED_TRANSPORT = i2c


# OPT_DEFS += -DHAL_USE_I2C=TRUE

RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor


KEY_OVERRIDE_ENABLE = yes       # alters the keycode sent for certain combos
CAPS_WORD_ENABLE = yes          # caps till whitespace character
LEADER_ENABLE = yes
UNICODE_COMMON = no
UNICODEMAP_ENABLE = no
TRI_LAYER_ENABLE = yes      # lower + raise gives adjust layer ( tri-layer )
DYNAMIC_MACRO_ENABLE = yes  # dynamic recorded macros (temp, resets on reboot)


VPATH  +=  keyboards/gboards/
COMBO_ENABLE = yes 			# https://docs.qmk.fm/features/combo#dictionary-management
