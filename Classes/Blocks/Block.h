#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <bitset>
#include "cocos2d.h"

namespace TetrisGame {
	class Block {

	protected:
		int color;
		std::vector<std::vector<char>> shape;
		std::vector<std::vector<std::vector<char>>> rotateShapes;
		cocos2d::Vec2 bottomLeftPos;

	public:
		virtual void virtual_Rotate() = 0;

		void softFalling();

		void hardFalling();
	};
}

#endif
