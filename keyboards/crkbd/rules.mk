# Build Options
#   change yes to no to disable
#

DEFAULT_FOLDER = crkbd/rev1

RGBLIGHT_SUPPORTED = yes
RGB_MATRIX_SUPPORTED = yes
OLED_ENABLE = yes
LTO_ENABLE = yes
WPM_ENABLE = yes
EXTRAFLAGS+=-flto
COMMAND_ENABLE   = no  # Commands for debug and configuration
UNICODE_ENABLE   = no  # Unicode
SWAP_HANDS_ENABLE= no  # Allow swapping hands of keyboard