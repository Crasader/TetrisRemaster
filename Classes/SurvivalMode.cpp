#include "SurvivalMode.h"

bool TetrisGame::SurvivalMode::isWin()
{
	return true;
}

bool TetrisGame::SurvivalMode::isLose()
{
	return currentBlock->getPosition() == currentBlockStartPos && !canMoveDown();
}

bool TetrisGame::SurvivalMode::virtual_computeScore()
{
	return true;
}
