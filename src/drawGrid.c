#include "drawGrid.h"
#include "raylib.h"

void drawGrid(int sW, int sH, int cellSize) {

  for (int x = 0; x < sW; x++) {
    DrawLine(0, cellSize * x, sW, cellSize * x, BLACK);
  }

  for (int y = 0; y < sH; y++) {
    DrawLine(cellSize * y, 0, cellSize * y, sH, BLACK);
  }
}
