#include "face_renderer.h"

void face_renderer_draw(GContext *ctx, const FaceState *state,
                        const FaceConfig *config) {
  graphics_context_set_fill_color(ctx, config->background_color);
  graphics_fill_rect(ctx, state->bounds, 0, GCornerNone);

  // The long hand is the minute indicator.
  graphics_context_set_stroke_color(ctx, config->foreground_color);
  graphics_context_set_stroke_width(ctx, config->minute_hand_width);
  graphics_draw_line(ctx, state->centre, state->minute_tip);

  // The orbiting dot is the hour indicator.
  graphics_context_set_fill_color(ctx, config->foreground_color);
  graphics_fill_circle(ctx, state->hour_dot, config->hour_dot_size);
}
