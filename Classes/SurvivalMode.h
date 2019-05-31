#ifndef SURVIVALMODE_H
#define SURVIVALMODE_H
#include "GameMode.h"

namespace TetrisGame {
	class SurvivalMode : public TetrisGame::GameMode {

	private:

	public:

		bool isWin();

		bool isLose();

		bool virtual_computeScore();
	};
}

#endif
