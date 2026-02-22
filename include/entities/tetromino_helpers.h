#include <functional>

// Helpers
int getRandomShape();
void loopTetromino(int tet[16], std::function<void(int x, int y, int val)> f);
bool canMoveX(const std::vector<int> &grid, int xDir, int CurX, int CurY, int shape[16]);