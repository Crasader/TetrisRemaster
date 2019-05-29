#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H
#include "Block.h"
#include "BlockType.h"

namespace TetrisGame {
	class BlockFactory {


	public:
		static TetrisGame::Block* getBlock(BlockType type);
	};
}

#endif
