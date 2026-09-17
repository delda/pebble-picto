#include "face_renderer.h"

#define MINUTE_HAND_WIDTH 20
#define HOUR_DOT_SIZE 12

void face_renderer_draw(GContext *ctx, const FaceState *state) {
  graphics_context_set_fill_color(ctx, GColorWhite);
  graphics_fill_rect(ctx, state->bounds, 0, GCornerNone);

  // The long hand is the minute indicator.
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_context_set_stroke_width(ctx, MINUTE_HAND_WIDTH);
  graphics_draw_line(ctx, state->centre, state->minute_tip);

  // The orbiting dot is the hour indicator.
  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_circle(ctx, state->hour_dot, HOUR_DOT_SIZE);
}
