#include "drawGrid.c"
#include "linkedList.h"
#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

#define MAX_SEGMENTS 100

const int screenWidth = 800;
const int screenHeight = 600;
const int cellSize = 20;
const float speed = 0.50f;
const float movementDelay = 0.08f;

bool isGameOver = false;

float timer = 0.0f;
int direction_x = 1;
int direction_y = 0;

Node *head = NULL;
Node *tail = NULL;

void drawSnake() {
  Node *currentNode = head;
  while (currentNode != NULL) {
    DrawRectangle(currentNode->x * cellSize, currentNode->y * cellSize,
                  cellSize, cellSize, RED);
    currentNode = currentNode->next;
  }
}

void drawGame() {
  BeginDrawing();

  ClearBackground(RAYWHITE);
  if (isGameOver) {
    int buttonWidth = 200;
    int buttonHeight = 50;
    int buttonX = (screenWidth - buttonWidth) / 2;
    int buttonY = (screenHeight - buttonHeight) / 2;
    DrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawText("Start Again", buttonX + 20, buttonY + 15, 20, DARKGRAY);
  }

  EndDrawing();
}

int snake_length = 3;

void handleMovement() {
  if (IsKeyDown(KEY_RIGHT)) {
    printf("test");
    direction_x = 1;
    direction_y = 0;
  }
  if (IsKeyDown(KEY_LEFT)) {
    direction_x = -1;
    direction_y = 0;
  }
  if (IsKeyDown(KEY_UP)) {
    direction_x = 0;
    direction_y = -1;
  }
  if (IsKeyDown(KEY_DOWN)) {
    direction_x = 0;
    direction_y = 1;
  }
}

void initSnake() {
  for (int i = 0; i < snake_length; i++) {
    int x = (screenWidth / 2) / (cellSize)-i;
    int y = screenHeight / 2 / cellSize;
    insertLinkedList(&head, x, y);
  }
}

void screenCollisionDetection() {

  if (head->x >= screenWidth / cellSize) {

    // isGameOver = true;
  }
}

void updateGame(float deltaTime) {

  timer += deltaTime;
  if (timer >= movementDelay && !isGameOver) {
    timer = 0.0f;
    Node *currentHead = head;

    int prevX, prevY;
    prevX = currentHead->x;
    prevY = currentHead->y;
    while (currentHead->next != NULL) {
      currentHead->x += direction_x;
      currentHead->y += direction_y;

      currentHead->next->x = prevX;
      currentHead->next->y = prevY;
      currentHead = currentHead->next;
    }
  }
  screenCollisionDetection();
}

int main(void) {

  InitWindow(screenWidth, screenHeight, "c-kata snake game");

  initSnake();
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();
    updateGame(deltaTime);
    drawGrid(screenWidth, screenHeight, cellSize);

    drawSnake();
    drawGame();
    handleMovement();
    /*printLinkedList(head);*/
  }

  CloseWindow();

  return 0;
}
