#ifndef LBLOCK_H
#define LBLOCK_H
#include "Block.h"
#include "define.h"

namespace TetrisGame {
	class LBlock : public TetrisGame::Block {
	private:

	public:
		LBlock(){}

		LBlock(COLOR color): Block(color){}

		bool init() override
		{
			Block::loadShapeData("block_map/L.txt");
			return Block::init();
		}
		CREATE_FUNC_BLOCK(LBlock);
	};
}

#endif
