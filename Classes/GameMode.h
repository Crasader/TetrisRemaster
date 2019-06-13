#ifndef GAMEMODE_H
#define GAMEMODE_H
#include <vector>
#include <bitset>
#include "cocos2d.h"
#include "Blocks/Block.h"

namespace TetrisGame {
	class GameMode {

	protected:
		float speed;	// speed here is t in formula v = s / t
		std::vector<std::vector<char>> board;
		Block* currentBlock;

		Block* getRandomBlock();

	public:

		void setSpeed(float speed);

		virtual bool isWin() = 0;
				
		virtual bool isLose() = 0;
				
		virtual bool virtual_computeScore() = 0;

		Block* getCurrentBlock();
		
		GameMode();

		float getSpeed();

		cocos2d::Vec2 getBlockShadowPos();

		void moveBlockByLeft();

		void moveBlockByRight();

		void forceBlockFall();

		void rotateBlock();

		Block* getNextBlock();
	};
}

#endif
