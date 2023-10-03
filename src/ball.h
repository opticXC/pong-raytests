#ifndef BALL_H
#define BALL_H

#include <raylib.h>

#include "paddle.h"

#define BALL_SPEED 0.5
#define BALL_WIDTH 0.01

 typedef struct{
    float x;
    float y;

    float radius;

    Vector2 speed;
 }Ball;


void DrawBall(Ball *ball, Color color);
void MoveBall(Ball *ball, Paddle *p1, Paddle *p2, int *s1, int *s2);

void ResetBall(Ball* ball);

void RandomizeBall(Ball *ball);

#endif
