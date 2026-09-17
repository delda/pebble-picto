#include "face_config.h"

#if defined(PBL_PLATFORM_GABBRO)
static const FaceConfig s_face_config = {
  .minute_hand_length = 107,
  .minute_hand_width = 20,
  .hour_dot_radius = 110,
  .hour_dot_size = 12,
  .background_color = GColorWhite,
  .foreground_color = GColorBlack,
};
#elif defined(PBL_PLATFORM_CHALK)
static const FaceConfig s_face_config = {
  // Gabbro is 260 x 260 and Chalk is 180 x 180: scale each dimension by
  // 180 / 260 to preserve the Gabbro face proportions.
  .minute_hand_length = 74,
  .minute_hand_width = 14,
  .hour_dot_radius = 76,
  .hour_dot_size = 8,
  .background_color = GColorWhite,
  .foreground_color = GColorBlack,
};
#else
#error "This watchface supports only Gabbro and Chalk."
#endif

const FaceConfig *face_config_get(void) {
  return &s_face_config;
}
