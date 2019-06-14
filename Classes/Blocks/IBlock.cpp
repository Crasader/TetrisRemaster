#include "IBlock.h"

bool TetrisGame::IBlock::init()
{
	Block::loadShapeData("block_map/I.txt");
	return Block::init();
}

TetrisGame::Block* TetrisGame::IBlock::clone() const
{
	auto aclone = IBlock::create(this->color);
	aclone->setPosition(this->getPosition());
	aclone->setAnchorPoint(this->getAnchorPoint());
	aclone->setContentSize(this->getContentSize());

	return aclone;
}
