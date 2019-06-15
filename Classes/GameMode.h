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

		std::vector<std::vector<Sprite*>> board =
			std::vector<std::vector<Sprite*>>
		(MAX_ROW, std::vector<Sprite*>(MAX_COL, nullptr));
		
		Block* currentBlock;

		Block* nextBlock;

		
	protected:
		Block* getRandomBlock();

		void drawCurrentBlockToBoard(Node* playArea);

		const int LEFT_WALL = -1;

		const int RIGHT_WALL = MAX_COL;

		const int FLOOR = MAX_ROW;

	public:
		void logCurrentBlockPosition();

		bool canMoveLeft();

		bool canMoveRight();

		bool canMoveDown();

		bool isMoveable();

		void clearRow(int index);

		void setSpeed(float speed);

		virtual bool isWin() = 0;
				
		virtual bool isLose() = 0;
				
		virtual bool virtual_computeScore() = 0;

		
		void moveBlockDown();


		GameMode();

		float getSpeed();

		cocos2d::Vec2 getBlockShadowPos();

		void moveBlockByLeft();

		void moveBlockByRight();

		void forceBlockFall();

		void rotateBlock();

		Block* getCurrentBlock();
		Block* getNextBlock();

		void initCurrentBlock();
		void initNextBlock();

		void updateCurrentBlock(Node* playArea);
	};
}

#endif
