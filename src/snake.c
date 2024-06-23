#include "drawGrid.c"
#include "linkedList.h"
#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

const int screenWidth = 800;
const int screenHeight = 600;
const int cellSize = 20;
const int FPS = 60;
const float speed = 0.50f;
const float movementDelay = 0.08f;

bool gameOver = false;

float timer = 0.0f;

int direction_x = 1;
int direction_y = 0;
int score = 0;

Node *head = NULL;

int snake_length = 10;

int gridWidth = screenWidth / cellSize;
int gridHeight = screenHeight / cellSize;

typedef struct Food {
  int x;
  int y;
} Food;

typedef enum { RIGHT, LEFT, UP, DOWN } Direction;

Direction currentDirection = RIGHT;
Food food;

void initFood(struct Food *food) {
  food->x = GetRandomValue(0, gridWidth - 1);
  food->y = GetRandomValue(0, gridHeight - 1);
}

void drawFood(struct Food *food) {
  DrawRectangle(food->x * cellSize, food->y * cellSize, cellSize, cellSize,
                GREEN);
}

void initSnake() {
  if (!gameOver) {
    for (int i = 0; i <= snake_length; i++) {
      int x = (screenWidth / 2) / (cellSize);
      int y = screenHeight / 2 / cellSize;
      insertLinkedList(&head, x, y);
    }
  }
}

void resetGame() {
  resetLinkedList(head);
  head = NULL;
  score = 0;
  snake_length = 3;
  direction_x = 1;
  direction_y = 0;
  timer = 0.0f;
  currentDirection = RIGHT;
  gameOver = false;
  initSnake();
}

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
  DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);
  if (gameOver) {
    int buttonWidth = 200;
    int buttonHeight = 50;
    int buttonX = (screenWidth - buttonWidth) / 2;
    int buttonY = (screenHeight - buttonHeight) / 2;
    DrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawText("Start Again", buttonX + 20, buttonY + 15, 20, DARKGRAY);
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && GetMouseX() >= buttonX &&
        GetMouseX() <= buttonX + buttonWidth && GetMouseY() >= buttonY &&
        GetMouseY() <= buttonY + buttonHeight) {
      resetGame();
    }

  } else {
    drawSnake();
    drawFood(&food);
  }

  EndDrawing();
}
void handleMovement() {
  if (head == NULL) {
    return;
  }
  if (IsKeyDown(KEY_RIGHT) && currentDirection != LEFT) {
    direction_x = 1;
    direction_y = 0;
    currentDirection = RIGHT;
  }
  if (IsKeyDown(KEY_LEFT) && currentDirection != RIGHT) {
    direction_x = -1;
    direction_y = 0;
    currentDirection = LEFT;
  }
  if (IsKeyDown(KEY_UP) && currentDirection != DOWN) {
    direction_x = 0;
    direction_y = -1;
    currentDirection = UP;
  }
  if (IsKeyDown(KEY_DOWN) && currentDirection != UP) {
    direction_x = 0;
    direction_y = 1;
    currentDirection = DOWN;
  }
}

void collisionDetection() {

  // boredes && snake
  if (head->x < 0 || head->x >= gridWidth || head->y < 0 ||
      head->y >= gridHeight) {
    gameOver = true;
  }

  if (head->x == food.x && head->y == food.y) {
    initFood(&food);
    pushLinkedList(&head);
    snake_length++;
    score++;
  }
}

void updateGame(float deltaTime) {

  timer += deltaTime;
  if (timer >= movementDelay && !gameOver) {
    timer = 0.0f;
    Node *currentNode = head;

    // adjust head node direction
    currentNode->x += direction_x;
    currentNode->y += direction_y;

    int prevX = currentNode->x;
    int prevY = currentNode->y;

    // move from head
    currentNode = currentNode->next;

    while (currentNode != NULL) {

      // store current position to pass it to next snake node
      int currentX = currentNode->x;
      int currentY = currentNode->y;

      currentNode->x = prevX;
      currentNode->y = prevY;

      // update prev position to current position
      // in other ways it always updates based on initial head position value
      prevX = currentX;
      prevY = currentY;
      if (currentNode->next != NULL && currentNode->next->x == head->x &&
          currentNode->next->y == head->y) {
        gameOver = true;
      }

      currentNode = currentNode->next;
    }
  }
  collisionDetection();
}

int main(void) {

  InitWindow(screenWidth, screenHeight, "c-kata snake game");

  initSnake();
  initFood(&food);
  SetTargetFPS(FPS);

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();
    updateGame(deltaTime);
    drawGrid(screenWidth, screenHeight, cellSize);

    drawGame();
    handleMovement();
  }

  CloseWindow();

  return 0;
}
