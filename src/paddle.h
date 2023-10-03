#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

#define PADDLE_WIDTH 0.02
#define PADDLE_HEIGHT 0.3

typedef struct {
    float x;
    float y;
    float width;
    float height;
}Paddle;


void MovePaddle(Paddle *paddle, float delta);
void DrawPaddle(Paddle *paddle, Color color);
void ResetPaddle(Paddle *paddle);

#endif
