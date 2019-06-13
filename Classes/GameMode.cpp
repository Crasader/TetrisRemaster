#include "GameMode.h"
#include "Blocks/BlockFactory.h"

TetrisGame::Block* TetrisGame::GameMode::getRandomBlock()
{
	auto type = static_cast<Block::BlockType>(
		cocos2d::random(0, 
			static_cast<int>(Block::BlockType::IBlock))
		);

	auto color = static_cast<Block::COLOR>(
		cocos2d::random(0,
			static_cast<int>(Block::COLOR::YELLOW))
		);

	return BlockFactory::getBlock(type, color);
}

void TetrisGame::GameMode::setSpeed(float speed)
{
	this->speed = speed;
}

TetrisGame::Block* TetrisGame::GameMode::getCurrentBlock()
{
	return currentBlock;
}

TetrisGame::GameMode::GameMode()
{
	speed = 1;
	this->currentBlock = this->getRandomBlock();
}

float TetrisGame::GameMode::getSpeed()
{
	return this->speed;
}

cocos2d::Vec2 TetrisGame::GameMode::getBlockShadowPos()
{
	// TODO - implement GameMode::getBlockShadowPos
	throw "Not yet implemented";
}

void TetrisGame::GameMode::moveBlockByLeft()
{
	auto pos = this->currentBlock->getPosition();
	this->currentBlock->setPosition(pos.x - BLOCK_SIZE, pos.y);
}

void TetrisGame::GameMode::moveBlockByRight()
{
	auto pos = this->currentBlock->getPosition();
	this->currentBlock->setPosition(pos.x + BLOCK_SIZE, pos.y);
}

void TetrisGame::GameMode::forceBlockFall()
{
	// TODO - implement GameMode::forceBlockFall
	throw "Not yet implemented";
}

void TetrisGame::GameMode::rotateBlock()
{
	// TODO - implement GameMode::rotateBlock
	throw "Not yet implemented";
}

TetrisGame::Block* TetrisGame::GameMode::getNextBlock()
{
	auto block = this->getRandomBlock();
	block->setAnchorPoint(Vec2(0.5f, 0.5f));
	return block;
}
