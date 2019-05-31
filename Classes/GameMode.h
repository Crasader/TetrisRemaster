#ifndef GAMEMODE_H
#define GAMEMODE_H
#include <vector>
#include <bitset>
#include "cocos2d.h"

namespace TetrisGame {
	class GameMode {

	protected:
		int speed;
		std::vector<std::vector<char>> board;

	public:
		virtual bool isWin() = 0;
				
		virtual bool isLose() = 0;
				
		virtual bool virtual_computeScore() = 0;

		void getSpeed();

		cocos2d::Vec2 getBlockShadowPos();

		void moveBlockByLeft();

		void moveBlockByRight();

		void forceBlockFall();

		void rotateBlock();

		void getNextBlock();
	};
}

#endif
