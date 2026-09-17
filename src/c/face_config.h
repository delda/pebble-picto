#pragma once

#include <pebble.h>

typedef struct {
  int16_t minute_hand_length;
  uint8_t minute_hand_width;
  int16_t hour_dot_radius;
  uint8_t hour_dot_size;
  GColor background_color;
  GColor foreground_color;
} FaceConfig;

// Returns the configuration selected at compile time for the current watch.
const FaceConfig *face_config_get(void);
