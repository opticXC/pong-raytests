#include "ball.h"
#include "raylib.h"
#include <raymath.h>
#include <math.h>


void DrawBall(Ball *ball, Color color){
    float sw = GetScreenWidth();
    float sh = GetScreenHeight();

    DrawCircle(ball->x * sw, ball->y * sh , ball->radius * sw , color);
}


void MoveBall(Ball *ball, Paddle *p1, Paddle *p2, int *s1, int *s2){
    float dt = GetFrameTime();
    ball->x += ball->speed.x * dt;
    ball->y += ball->speed.y * dt;

    if (ball->y + ball->radius > 1.0 || ball->y - ball->radius < 0.0){
        ball->speed.y *= -1.0;
    }
    
    if (ball->x - ball->radius <=0.0){
        *s2 += 1;
        ResetBall(ball);
    }

    if (ball->x + ball->radius >=1.0){
        *s1 += 1;
        ResetBall(ball);
    }
    
    if (ball->x - ball->radius <= p1->x + p1->width && ball->y - ball->radius >= p1->y && ball->y + ball->radius <= p1->y + p1->height ){
        ball->speed.x *= -1.0;
    }

    if (ball->x + ball->radius >= p2->x  && ball->y - ball->radius >= p2->y && ball->y + ball->radius <= p2->y + p2->height ){
        ball->speed.x *= -1.0;
    }
}


void ResetBall(Ball* ball){
    ball->x = 0.5;
    ball->y = 0.5;
    
    RandomizeBall(ball);

}

void RandomizeBall(Ball *ball){
    int rand_angle = GetRandomValue(0, 360);
    

    float v_speed = sinf( rand_angle *  RAD2DEG) * BALL_SPEED;
    float h_speed = BALL_SPEED - v_speed;
    
    v_speed = sqrtf(powf(v_speed, 2) );
    h_speed = sqrtf(powf(h_speed, 2) ); 

    if (rand_angle < 90){
    }else if (rand_angle < 180){
       h_speed *= -1.0; 
    }else if (rand_angle < 270){
        h_speed *= -1.0;
        v_speed *= -1.0;
    }else{
        v_speed *= -1.0;
    }


    ball->speed = (Vector2){h_speed, v_speed } ;
}
