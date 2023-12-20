#define RAYGUI_IMPLEMENTATION
#include "game.h"

#define PLATFORM_WINDOWS

const int WIDTH = 1200;
const int HEIGHT = 800;

Ball ball(WIDTH/2, HEIGHT/2, 20, 3.5, 3.5);
Player player1(10, HEIGHT/2 - 60, 3.5, 25, 120, KEY_W, KEY_S);
Player player2(WIDTH - 25 - 10, HEIGHT/2 - 60, 3, 25, 120, KEY_UP, KEY_DOWN);

int WinMain() {

    InitWindow(WIDTH, HEIGHT, "Pong");
	InitGame(&player1, &player2, &ball, 144);

    SetTargetFPS(game->targetFPS);

    mainMenu();
    resetGame();

    while (!WindowShouldClose()) {

		game->updateAll();

        if (CheckCollisionCircleRec(Vector2{ ball.getX(), ball.getY() }, ball.getRadius(), player1.getRectangle()) 
		  || CheckCollisionCircleRec(Vector2{ ball.getX(), ball.getY() }, ball.getRadius(), player2.getRectangle())) {
            ball.invertSpeedX();
        }

        BeginDrawing();
        ClearBackground(BLACK);

        game->drawAll();
        displayGame();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}