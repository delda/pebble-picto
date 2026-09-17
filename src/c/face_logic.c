#include "face_logic.h"

static GPoint prv_point_on_circle(GPoint centre, int32_t radius, int32_t angle) {
  return GPoint(centre.x + (sin_lookup(angle) * radius) / TRIG_MAX_RATIO,
                centre.y - (cos_lookup(angle) * radius) / TRIG_MAX_RATIO);
}

FaceState face_logic_create_state(GRect bounds, const struct tm *time,
                                  const FaceConfig *config) {
  const GPoint centre = grect_center_point(&bounds);
  const int32_t minute_angle = TRIG_MAX_ANGLE * time->tm_min / 60;
  const int32_t hour_angle = TRIG_MAX_ANGLE * (time->tm_hour % 12) / 12;

  return (FaceState) {
    .bounds = bounds,
    .centre = centre,
    .minute_tip = prv_point_on_circle(centre, config->minute_hand_length,
                                      minute_angle),
    .hour_dot = prv_point_on_circle(centre, config->hour_dot_radius, hour_angle),
  };
}
