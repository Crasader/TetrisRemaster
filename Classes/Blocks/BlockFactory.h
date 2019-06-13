#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H
#include "Block.h"

namespace TetrisGame {
	class BlockFactory {


	public:
		static TetrisGame::Block* getBlock(Block::BlockType type, Block::COLOR color);
	};
}

#endif
