#include "face_logic.h"

// Designed exclusively for the 180 x 180 round Gabbro display.
#define MINUTE_HAND_LENGTH 107
#define HOUR_DOT_RADIUS 110

static GPoint prv_point_on_circle(GPoint centre, int32_t radius, int32_t angle) {
  return GPoint(centre.x + (sin_lookup(angle) * radius) / TRIG_MAX_RATIO,
                centre.y - (cos_lookup(angle) * radius) / TRIG_MAX_RATIO);
}

FaceState face_logic_create_state(GRect bounds, const struct tm *time) {
  const GPoint centre = grect_center_point(&bounds);
  const int32_t minute_angle = TRIG_MAX_ANGLE * time->tm_min / 60;
  const int32_t hour_angle = TRIG_MAX_ANGLE * (time->tm_hour % 12) / 12;

  return (FaceState) {
    .bounds = bounds,
    .centre = centre,
    .minute_tip = prv_point_on_circle(centre, MINUTE_HAND_LENGTH, minute_angle),
    .hour_dot = prv_point_on_circle(centre, HOUR_DOT_RADIUS, hour_angle),
  };
}
