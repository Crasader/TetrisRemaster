#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "Block.h"
#include "define.h"

namespace TetrisGame {
	class ZBlock : public TetrisGame::Block {
	private:

	public:
		ZBlock(){}
		ZBlock(COLOR color):Block(color){}

		bool init() override
		{
			Block::loadShapeData("block_map/Z.txt");
			return Block::init();
		}
		CREATE_FUNC_BLOCK(ZBlock);
	};
}

#endif
