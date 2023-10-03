#include "paddle.h"
#include "raylib.h"

void MovePaddle(Paddle *paddle, float delta ){    
    paddle->y -= delta;

    if (paddle->y + paddle->height >= 1.0) {
        paddle->y = 1.0 - paddle->height;

    }else if ( paddle->y <= 0 ) {
        paddle->y = 0; 
    }
}

void DrawPaddle(Paddle *paddle, Color color){
    int sh = GetScreenHeight();
    int sw = GetScreenWidth();
    DrawRectangle(paddle->x * sw, paddle->y * sh, paddle->width * sw, paddle->height * sh, color);
}


void ResetPaddle(Paddle *paddle){
    paddle->y = (2/paddle->height) - paddle->height/2;
}
