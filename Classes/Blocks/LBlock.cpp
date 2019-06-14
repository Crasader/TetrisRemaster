#include "LBlock.h"

bool TetrisGame::LBlock::init()
{
	Block::loadShapeData("block_map/L.txt");
	return Block::init();
}

TetrisGame::Block* TetrisGame::LBlock::clone() const
{
	auto aclone = LBlock::create(this->color);
	aclone->setPosition(this->getPosition());
	aclone->setAnchorPoint(this->getAnchorPoint());
	aclone->setContentSize(this->getContentSize());

	return aclone;
}
