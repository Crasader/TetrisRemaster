#ifndef PUZZLEMODE_H
#define PUZZLEMODE_H
#include "GameMode.h"

namespace TetrisGame {
	class PuzzleMode : public TetrisGame::GameMode {

	private:
		int blockUsed;

	public:

		bool isWin();
		
		bool isLose();
		
		bool virtual_computeScore();
	};
}

#endif
