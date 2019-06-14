#include "ZBlock.h"

bool TetrisGame::ZBlock::init()
{
	Block::loadShapeData("block_map/Z.txt");
	return Block::init();
}

TetrisGame::Block* TetrisGame::ZBlock::clone() const
{
	auto aclone = ZBlock::create(this->color);
	aclone->setPosition(this->getPosition());
	aclone->setAnchorPoint(this->getAnchorPoint());
	aclone->setContentSize(this->getContentSize());

	return aclone;
}
