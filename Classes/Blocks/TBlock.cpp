#include "TBlock.h"

bool TetrisGame::TBlock::init()
{
	Block::loadShapeData("block_map/T.txt");
	return Block::init();
}

TetrisGame::Block* TetrisGame::TBlock::clone() const
{
	auto aclone = TBlock::create(this->color);
	aclone->setPosition(this->getPosition());
	aclone->setAnchorPoint(this->getAnchorPoint());
	aclone->setContentSize(this->getContentSize());

	while (aclone->currentAngle != this->currentAngle)
	{
		aclone->rotate();
	}
	return aclone;
}
