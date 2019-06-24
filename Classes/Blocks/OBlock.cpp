#include "OBlock.h"

bool TetrisGame::OBlock::init()
{
	Block::loadShapeData("block_map/O.txt");
	return Block::init();
}

TetrisGame::Block* TetrisGame::OBlock::clone() const
{
	auto aclone = OBlock::create(this->color);
	aclone->setPosition(this->getPosition());
	aclone->setAnchorPoint(this->getAnchorPoint());
	aclone->setContentSize(this->getContentSize());

	while (aclone->currentAngle != this->currentAngle)
	{
		aclone->rotate();
	}
	return aclone;
}
