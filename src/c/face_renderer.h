#pragma once

#include "face_logic.h"

// Draws a precomputed face state; this module has no timekeeping logic.
void face_renderer_draw(GContext *ctx, const FaceState *state,
                        const FaceConfig *config);
