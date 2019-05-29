#ifndef GAMEMODE_H
#define GAMEMODE_H

namespace TetrisGame {
	class GameMode {

	protected:
		int speed;
		std::vector<std::bitset> board;

	public:
		virtual void isWin() = 0;

		virtual void isLose() = 0;

		virtual void virtual_computeScore() = 0;

		void getSpeed();

		Point2D getBlockShadowPos();

		void moveBlockByLeft();

		void moveBlockByRight();

		void forceBlockFall();

		void rotateBlock();

		void getNextBlock();
	};
}

#endif
