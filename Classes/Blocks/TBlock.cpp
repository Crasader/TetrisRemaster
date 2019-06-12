#include "TBlock.h"

bool TetrisGame::TBlock::init()
{
	Block::loadShapeData("block_map/T.txt");
	return Block::init();
}
