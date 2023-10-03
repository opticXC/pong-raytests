#include "main.h"
#include "GLFW/glfw3.h"
#include "ball.h"
#include "paddle.h"
#include "raylib.h"

int main(void){
    int screen_width = 800;
    int screen_height = 600;
    char *title = "title";

    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(60);


    TraceLogLevel(LOG_DEBUG);

    #ifdef RELEASE_BUILD
        TraceLogLevel(LOG_INFO); 
    #endif


    Paddle player1 = {0}, player2 = {0};

    player1.width = PADDLE_WIDTH;
    player1.height = PADDLE_HEIGHT; 
    player1.x = player1.width;
    player1.y = 0.5 - (PADDLE_HEIGHT/2.0);
 
    player2.width = PADDLE_WIDTH;
    player2.height = PADDLE_HEIGHT;
    player2.x = 1 - 2 * PADDLE_WIDTH;
    player2.y = 0.5 - (PADDLE_HEIGHT/2.0);


    int score_1 = 0, score_2 = 0;
    
    Ball ball = {};
    ball.x = 0.5;
    ball.y = 0.5;
    ball.radius = BALL_WIDTH;
    ResetBall(&ball);

    Color textcolor = {0,0,0,175};

    float paddle_speed = 2.0/3.0;
    float deltaTime;


    while (!WindowShouldClose()) {
        deltaTime = GetFrameTime();
        if (GetScreenHeight() != screen_height || GetScreenWidth() != screen_width){

            screen_width = GetScreenWidth();
            screen_height = GetScreenHeight();

            player1.x = player1.width;

            paddle_speed = 0.5;

            TraceLog(LOG_DEBUG, "[WINDOW]: Updated Window Dimenstions [w:%4.2f|h:%4.2f]", screen_width, screen_height);
        }

        if (IsKeyPressed(KEY_R)){
            player1.y = 0.5;
            player2.y = 0.5;
            ResetBall(&ball);
        }

        if (IsKeyDown(KEY_W)) {
            MovePaddle(&player1, paddle_speed * deltaTime);
        }
        if (IsKeyDown(KEY_S)){
            MovePaddle(&player1, -paddle_speed * deltaTime );
        }
        
        if (IsKeyDown(KEY_UP)) {
            MovePaddle(&player2, paddle_speed * deltaTime);
        }
        if (IsKeyDown(KEY_DOWN)){
            MovePaddle(&player2, -paddle_speed * deltaTime );
        }

        MoveBall(&ball, &player1, &player2, &score_1, &score_2);

        BeginDrawing();
        {
            ClearBackground(WHITE);
            DrawFPS(10, 20);
            
            DrawLine(screen_width/2, 0, screen_width/2, GetScreenHeight(), textcolor);
            DrawText(TextFormat("%d", score_1), (screen_width * 1/4)  - (screen_width/24) , screen_height * 1/3, screen_width/12, textcolor);
            DrawText(TextFormat("%d", score_2), (screen_width * 3/4)  - (screen_width/24) , screen_height * 1/3, screen_width/12, textcolor);
            
            DrawPaddle(&player1, BLACK);
            DrawPaddle(&player2, BLACK);
            DrawBall(&ball, BLACK);
        }
        EndDrawing();

        TraceLog(LOG_DEBUG, "[PADDLE DATA]: { [x:%d|y:%d] , [%3.2fx%3.2f]   }",player1.x, player1.y, player1.width, player1.height);
    }

    
    CloseWindow();
    return 0;
}
