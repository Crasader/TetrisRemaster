#ifndef IBLOCK_H
#define IBLOCK_H
#include "Block.h"

namespace TetrisGame {
	class IBlock : public TetrisGame::Block {
	private:

	public:
		IBlock(){}

		IBlock(COLOR color): Block(color){}

		bool init() override
		{
			Block::loadShapeData("block_map/I.txt");
			return Block::init();
		}
		CREATE_FUNC_BLOCK(IBlock);
	};
}

#endif
