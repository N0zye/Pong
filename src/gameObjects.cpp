#include "game.h"

// Definizioni dei costruttori e delle funzioni member della classe Ball

Ball::Ball(float posX, float posY, float radius, float speedX, float speedY)
    : posX(posX), posY(posY), radius(radius), speedX(speedX), speedY(speedY) {}

void Ball::draw() {
    DrawCircle(posX, posY, radius, WHITE);
}

void Ball::update() {
    posX += speedX;
    posY += speedY;

    if (posX + radius >= GetScreenWidth()) {
        playerScored(1);
        speedX *= -1;
    }
    if (posX - radius <= 0) {
        playerScored(2);
        speedX *= -1;
    }
    if (posY + radius >= GetScreenHeight() || posY - radius <= 0) {
        speedY *= -1;
    }
}

void Ball::reset() {
    posX = GetScreenWidth() / 2;
    posY = GetScreenHeight() / 2;
}

void Ball::invertSpeedX() {
    speedX *= -1;
}

float Ball::getY() const {
    return posY;
}

float Ball::getX() const {
    return posX;
}

float Ball::getRadius() const {
    return radius;
}

// Definizioni dei costruttori e delle funzioni member della classe Player

Player::Player(float posX, float posY, float speed, int width, int height, int keyUP, int keyDOWN)
    : posX(posX), posY(posY), speed(speed), width(width), height(height), keyUP(keyUP), keyDOWN(keyDOWN), CPUisEnabled(false), score(0) {}

void Player::draw() {
    DrawRectangle(posX, posY, width, height, WHITE);
}

void Player::reset() {
    posY = GetScreenHeight() / 2 - height / 2;
}

Rectangle Player::getRectangle() const {
    return Rectangle{ posX, posY, width, height };
}

void Player::update(float ballPosY) {
    if (CPUisEnabled) {
        updateWithCPU(ballPosY);
    }
    else {
        updateWithoutCPU();
    }
}

void Player::limitMovement() {
    if (posY <= 0) {
        posY = 0;
    }
    if (posY + height >= GetScreenHeight()) {
        posY = GetScreenHeight() - height;
    }
}

void Player::updateWithCPU(float ballPosY) {
    if (ballPosY > posY + height / 2) {
        posY += speed;
    }
    if (ballPosY < posY + height / 2) {
        posY -= speed;
    }
    limitMovement();
}

void Player::updateWithoutCPU() {
    if (IsKeyDown(keyUP)) {
        posY -= speed;
    }
    if (IsKeyDown(keyDOWN)) {
        posY += speed;
    }
    limitMovement();
}

void Player::enableCPU() {
    CPUisEnabled = true;
}

void Player::disableCPU() {
    CPUisEnabled = false;
}

void Player::increaseScore() {
    score++;
}

int Player::getScore() {
    return score;
}

// Definizione del costruttore della classe Game

Game::Game(Player* leftPlayer, Player* rightPlayer, Ball* ball, int targetFPS)
	: leftPlayer(leftPlayer), rightPlayer(rightPlayer), ball(ball), targetFPS(targetFPS) {}

Game::Game()
	: leftPlayer(nullptr), rightPlayer(nullptr), ball(nullptr), targetFPS(10) {}

void Game::updateAll() {
	ball->update();
	leftPlayer->update(ball->getY());
	rightPlayer->update(ball->getY());
}

void Game::resetAll(){
	ball->reset();
	leftPlayer->reset();
	rightPlayer->reset();
}

void Game::drawAll() {
	ball->draw();
    leftPlayer->draw();
    rightPlayer->draw();
}