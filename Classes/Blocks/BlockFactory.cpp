#include "BlockFactory.h"
#include "TBlock.h"
#include "LBlock.h"
#include "ZBlock.h"
#include "OBlock.h"
#include "IBlock.h"

TetrisGame::Block* TetrisGame::BlockFactory::getBlock(Block::BlockType type, TetrisGame::Block::COLOR color)
{
	switch (type)
	{
	case Block::TBlock:
		return TBlock::create(color);

	case Block::LBlock:
		return LBlock::create(color);
		break;

	case Block::ZBlock:
		return ZBlock::create(color);
		break;

	case Block::OBlock:
		return OBlock::create(color);
		break;

	case Block::IBlock: 
		return IBlock::create(color);
		break;

	default:
		break;
	}
	return nullptr;
}
