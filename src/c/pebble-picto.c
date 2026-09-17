#include <pebble.h>

// Designed exclusively for the 180 x 180 round Gabbro display.
#define MINUTE_HAND_LENGTH 107
#define MINUTE_HAND_WIDTH 20
#define HOUR_DOT_RADIUS 110
#define HOUR_DOT_SIZE 12

static Window *s_window;
static Layer *s_face_layer;

static GPoint prv_point_on_circle(GPoint centre, int32_t radius, int32_t angle) {
  return GPoint(centre.x + (sin_lookup(angle) * radius) / TRIG_MAX_RATIO,
                centre.y - (cos_lookup(angle) * radius) / TRIG_MAX_RATIO);
}

static void prv_face_update_proc(Layer *layer, GContext *ctx) {
  const GRect bounds = layer_get_bounds(layer);
  const GPoint centre = grect_center_point(&bounds);
  const time_t now = time(NULL);
  const struct tm *tick_time = localtime(&now);

  const int32_t minute_angle = TRIG_MAX_ANGLE * tick_time->tm_min / 60;
  const int32_t hour_angle = TRIG_MAX_ANGLE * (tick_time->tm_hour % 12) / 12;
  const GPoint minute_tip = prv_point_on_circle(centre, MINUTE_HAND_LENGTH,
                                                 minute_angle);
  const GPoint hour_dot = prv_point_on_circle(centre, HOUR_DOT_RADIUS,
                                               hour_angle);

  graphics_context_set_fill_color(ctx, GColorWhite);
  graphics_fill_rect(ctx, bounds, 0, GCornerNone);

  // The long hand is the minute indicator.
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_context_set_stroke_width(ctx, MINUTE_HAND_WIDTH);
  graphics_draw_line(ctx, centre, minute_tip);

  // The orbiting dot is the hour indicator.
  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_circle(ctx, hour_dot, HOUR_DOT_SIZE);
}

static void prv_tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  layer_mark_dirty(s_face_layer);
}

static void prv_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  const GRect bounds = layer_get_bounds(window_layer);

  s_face_layer = layer_create(GRect(0, 0, bounds.size.w, bounds.size.h));
  layer_set_update_proc(s_face_layer, prv_face_update_proc);
  layer_add_child(window_layer, s_face_layer);
}

static void prv_window_unload(Window *window) {
  layer_destroy(s_face_layer);
}

static void prv_init(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorWhite);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = prv_window_load,
    .unload = prv_window_unload,
  });
  window_stack_push(s_window, true);
  tick_timer_service_subscribe(MINUTE_UNIT, prv_tick_handler);
}

static void prv_deinit(void) {
  tick_timer_service_unsubscribe();
  window_destroy(s_window);
}

int main(void) {
  prv_init();
  app_event_loop();
  prv_deinit();
}
