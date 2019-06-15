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

void TetrisGame::GameMode::drawCurrentBlockToBoard(Node* playArea)
{
	auto unitBlocks = currentBlock->clone()->getUnitBlocks();
	int height = currentBlock->getContentSize().height;
	auto pos = currentBlock->getPosition();
	
	int rowBegin = unitBlocks.size() - height / BLOCK_SIZE;

	int boardCol = pos.x / BLOCK_SIZE;
	int boardRow = MAX_ROW - pos.y / BLOCK_SIZE - height / BLOCK_SIZE;

	for (int i = rowBegin; i < unitBlocks.size(); i++)
	{

		for (int j = 0; j < unitBlocks[i].size(); j++)
		{
			if (unitBlocks[i][j] != nullptr)
			{
				board[boardRow + i - rowBegin][boardCol + j] = unitBlocks[i][j];
				unitBlocks[i][j]->setPosition(pos + unitBlocks[i][j]->getPosition());
				unitBlocks[i][j]->removeFromParent();
				playArea->addChild(unitBlocks[i][j]);
			}
		}
	}
}

void TetrisGame::GameMode::logCurrentBlockPosition()
{
	
	int height = currentBlock->getContentSize().height;
	auto pos = currentBlock->getPosition();
	auto shape = currentBlock->getShape();
	int rowBegin = shape.size() - height / BLOCK_SIZE;

	float boardCol = pos.x / BLOCK_SIZE;
	float boardRow = MAX_ROW - pos.y / BLOCK_SIZE - height / BLOCK_SIZE;

	log("Top Left: (%f, %f)", boardRow, boardCol);

	for (int i = rowBegin; i < shape.size(); i++)
	{
		std::stringstream ss;
		for (int j = 0; j < shape[i].size(); j++)
		{
			if (shape[i][j] == 1)
			{
				ss << "[" << boardRow + i - rowBegin << ", " << boardCol + j << "] ";
			}else
			{
				ss << "      ";
			}
		}
		log("%s", ss.str().c_str());
	}
	log("");
}

bool TetrisGame::GameMode::canMoveLeft()
{
	// do the block hit the left wall or any other block ?
	auto pos = this->currentBlock->getPosition();
	auto leftMostCols = this->currentBlock->getLeftMostCols();
	auto height = this->currentBlock->getContentSize().height;
	// move left so row index not change
	// only change col index

	for (int row = 0; row < leftMostCols.size(); ++row)
	{
		int newCol = leftMostCols[row] - 1;

		int boardCol = pos.x / BLOCK_SIZE + newCol;
		int boardRow = MAX_ROW - pos.y / BLOCK_SIZE - height / BLOCK_SIZE + row;

		// hit the left wall
		if (boardCol == LEFT_WALL)
			return false;

		// hit other block
		if (board[boardRow][boardCol] != nullptr)
			return false;
	}
	return true;
}

bool TetrisGame::GameMode::canMoveRight()
{
	// do the block hit the right wall or any other block
	auto pos = this->currentBlock->getPosition();
	auto rightMostCols = this->currentBlock->getRightMostCols();
	auto height = this->currentBlock->getContentSize().height;
	// move left so row index not change
	// only change col index

	for (int row = 0; row < rightMostCols.size(); ++row)
	{
		int newCol = rightMostCols[row] + 1;

		int boardCol = pos.x / BLOCK_SIZE + newCol;
		int boardRow = MAX_ROW - pos.y / BLOCK_SIZE - height / BLOCK_SIZE + row;

		// hit the right wall
		if (boardCol == RIGHT_WALL)
			return false;

		// hit other block
		if (board[boardRow][boardCol] != nullptr)
			return false;
	}
	return true;
}

bool TetrisGame::GameMode::canMoveDown()
{
	// do the block hit the right wall or any other block
	auto pos = this->currentBlock->getPosition();

	auto lowestRows = this->currentBlock->getLowestRows(); // matrix coordinate

	auto height = this->currentBlock->getContentSize().height;
	// move down so col index not change
	// only change row index
	auto shape = currentBlock->getShape();
	int rowBegin = shape.size() - height / BLOCK_SIZE;

	for (int col = 0; col < lowestRows.size(); ++col)
	{
		int newRow = lowestRows[col] + 1;

		int boardCol = pos.x / BLOCK_SIZE + col;
		int boardRow = MAX_ROW - pos.y / BLOCK_SIZE - height / BLOCK_SIZE + newRow - rowBegin;

		// hit the FLOOR
		if (boardRow == FLOOR)
			return false;

		// // hit other block
		if (board[boardRow][boardCol] != nullptr)
			return false;
	}
	return true;
}

bool TetrisGame::GameMode::isMoveable()
{
	return canMoveDown() || canMoveLeft() || canMoveRight();
}

void TetrisGame::GameMode::clearRow(int index)
{
	auto row = board[index];
	for (auto sprite : row)
	{
		sprite->removeFromParent();
	}
}

void TetrisGame::GameMode::setSpeed(float speed)
{
	this->speed = speed;
}

TetrisGame::Block* TetrisGame::GameMode::getCurrentBlock()
{
	return currentBlock;
}

void TetrisGame::GameMode::moveBlockDown()
{
	auto pos = currentBlock->getPosition();
	currentBlock->setPosition(pos.x, pos.y - BLOCK_SIZE);
	logCurrentBlockPosition();
}

// init random position for block
//
//     position here
// | - - - - - - - - - - - |
// |		Play area	   |
// |					   |

void TetrisGame::GameMode::initCurrentBlock()
{
	auto pos = Vec2::ZERO;
	auto height = currentBlock->getContentSize().height;
	pos.x = cocos2d::random(0, MAX_COL) * BLOCK_SIZE;
	pos.y = MAX_ROW * BLOCK_SIZE - height;

	// avoid overlap the right border
	// the pos.x always between [0, MAX_COL * BLOCK_SIZE -  blockWidth]
	auto blockWidth = currentBlock->getContentSize().width;
	pos.x = cocos2d::clampf(
		pos.x,
		0,
		MAX_COL * BLOCK_SIZE - blockWidth);

	this->currentBlock->setPosition(pos);
	this->currentBlock->setAnchorPoint(Vec2::ZERO);
}

TetrisGame::GameMode::GameMode()
{
	srand(time(NULL));
	speed = 1;
	this->currentBlock = this->getRandomBlock();

	initCurrentBlock();

	initNextBlock();
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
	logCurrentBlockPosition();
}


void TetrisGame::GameMode::moveBlockByRight()
{
	auto pos = this->currentBlock->getPosition();
	this->currentBlock->setPosition(pos.x + BLOCK_SIZE, pos.y);
	logCurrentBlockPosition();
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
	return nextBlock;
}

void TetrisGame::GameMode::initNextBlock()
{
	nextBlock = getRandomBlock();
	nextBlock->setAnchorPoint(Vec2(0.5f,0.5f));
}

void TetrisGame::GameMode::updateCurrentBlock(Node* playArea)
{
	drawCurrentBlockToBoard(playArea);

	currentBlock->removeFromParent();
	currentBlock = nextBlock->clone();
	initCurrentBlock();

	nextBlock->removeFromParent();
	initNextBlock();
}
