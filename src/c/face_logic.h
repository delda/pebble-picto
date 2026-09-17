#pragma once

#include <pebble.h>

typedef struct {
  GRect bounds;
  GPoint centre;
  GPoint minute_tip;
  GPoint hour_dot;
} FaceState;

// Converts the current time into the geometry the face needs to display.
FaceState face_logic_create_state(GRect bounds, const struct tm *time);
