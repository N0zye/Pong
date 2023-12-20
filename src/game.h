#pragma once

#include "raylib.h"
#include "raygui.h"
#include "mainmenu.h"
#include <string>

class Ball {
private:
    float posX, posY, radius;
    float speedX, speedY;

public:
    Ball(float posX, float posY, float radius, float speedX, float speedY);

    void draw();
    void update();
    void reset();
    void invertSpeedX();
    float getY() const;
    float getX() const;
    float getRadius() const;
};

class Player {
private:
    float posX, posY, speed;
    float width, height;
    int keyUP, keyDOWN;
    bool CPUisEnabled;
    int score;

    void limitMovement();
    void updateWithCPU(float ballPosY);
    void updateWithoutCPU();

public:
    Player(float posX, float posY, float speed, int width, int height, int keyUP, int keyDOWN);

    void draw();
    void reset();
    Rectangle getRectangle() const;
    void update(float ballPosY);
    void enableCPU();
    void disableCPU();
    void increaseScore();
    int getScore();
};

class Game {
public:
	Player* leftPlayer;
	Player* rightPlayer;
	Ball* ball;
	int targetFPS;
    Game(Player*, Player*, Ball*, int);
	Game();
	void updateAll();
	void resetAll();
	void drawAll();
};

extern Game* game;

void drawCenteredText(const char* text, int size);
void displayGame();
void resetGame();
void playerScored(int playerNuber);
void mainMenu();
void InitGame(Player* leftPlayer, Player* rightPlayer, Ball* ball, int maxFPS);