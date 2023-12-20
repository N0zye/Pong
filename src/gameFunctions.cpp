#include "game.h"

Game* game = new Game();

void drawCenteredText(const char* text, int size) {
    DrawText(text, GetScreenWidth() / 2 - MeasureText(text, size) / 2, GetScreenHeight() / 2 - size / 2, size, WHITE);
}

void displayGame() {
    DrawText(TextFormat("%d", game->leftPlayer->getScore()), GetScreenWidth() / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%d", game->rightPlayer->getScore()), 3 * GetScreenWidth() / 4 - 20, 20, 80, WHITE);
	DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);
	if (GuiButton(Rectangle{ (float)GetScreenWidth()* 8/9 - 60, (float)GetScreenHeight()* 8/9, 120, 40 }, "options")) {
		EndDrawing();
		mainMenu();
    	resetGame();
	}
}

void resetGame() {
	game->resetAll();
    int countdown = 3 * game->targetFPS;
    while (countdown > 0) {
        if (WindowShouldClose()) {
            CloseWindow();
        }
        BeginDrawing();
        ClearBackground(BLACK);
        drawCenteredText(TextFormat("%d", (countdown / game->targetFPS) + 1), 80);
        EndDrawing();
        countdown--;
    }
}

void playerScored(int playerNumber) {

	playerNumber == 1 ? game->leftPlayer->increaseScore() : game->rightPlayer->increaseScore();
    int countdown = 2 * game->targetFPS;
    std::string message = "Player " + std::to_string(playerNumber) + " scored!!!";
    while (countdown > 0) {
        if (WindowShouldClose()) {
            CloseWindow();
        }
        BeginDrawing();
        ClearBackground(BLACK);
        drawCenteredText(message.c_str(), 80);
        EndDrawing();
        countdown--;
    }
    resetGame();
}

void mainMenu() {
    GuiLoadStyleMainMenu();
    bool confirmButtonPressed = false;
    int toggleGroupState = 0;

    while (!confirmButtonPressed) {
        if (WindowShouldClose()) {
            CloseWindow();
        }
        BeginDrawing();
        ClearBackground(BLACK);
        if (GuiButton(Rectangle{ (float)GetScreenWidth() / 2 - 60, (float)GetScreenHeight() / 2, 120, 60 }, "CONFIRM")) {
            switch (toggleGroupState) {
            case 0:
                game->leftPlayer->disableCPU();
                game->rightPlayer->disableCPU();
                break;
            case 1:
                game->leftPlayer->disableCPU();
                game->rightPlayer->enableCPU();
                break;
            case 2:
                game->leftPlayer->enableCPU();
                game->rightPlayer->enableCPU();
                break;
            default:
                break;
            }
            confirmButtonPressed = true;
        }
        GuiToggleGroup({ (float)GetScreenWidth() / 2 - 3 * 60, (float)GetScreenHeight() / 2 - 100, 120, 60 }, "1V1;1Vcpu;cpuVcpu", &toggleGroupState);
        EndDrawing();
    }
}

void InitGame(Player* leftPlayer, Player* rightPlayer, Ball* ball, int maxFPS) {
	game = new Game(leftPlayer, rightPlayer, ball, maxFPS);
}