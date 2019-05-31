#include "PuzzleMode.h"

bool TetrisGame::PuzzleMode::isWin()
{
	return true;
}

bool TetrisGame::PuzzleMode::isLose()
{
	return true;
}

bool TetrisGame::PuzzleMode::virtual_computeScore()
{
	return true;
}
