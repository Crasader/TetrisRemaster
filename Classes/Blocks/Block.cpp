#include "Block.h"

void TetrisGame::Block::loadShapeData(std::string filePath)
{
	std::ifstream ifs(filePath);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ifs >> shape[i][j];
		}
	}
	ifs.close();
}

TetrisGame::Block::Block()
{
}

TetrisGame::Block::Block(COLOR color)
{
	this->color = color;
	Node();
}

bool TetrisGame::Block::init()
{
	if (!Node::init())
		return false;

	for (int row = shape.size() - 1; row >= 0; row--)
	{
		for (int col = 0; col < shape[row].size(); col++)
		{
			if (shape[row][col] == 1)
			{
				auto block = Sprite::create(color_map[color]);
				
				block->setContentSize(Size(
					TetrisGame::BLOCK_SIZE,
					TetrisGame::BLOCK_SIZE));

				this->addChild(block);

				block->setPosition(
					BLOCK_SIZE * col, 
					BLOCK_SIZE *(shape.size() - 1 - row));
				
				block->setAnchorPoint(Vec2(0.f, 0.f));
			}
		}
	}
	this->setAnchorPoint(Vec2(0.f, 0.f));
	return true;
}

void TetrisGame::Block::softFalling()
{
	// TODO - implement Block::softFalling
	throw "Not yet implemented";
}

void TetrisGame::Block::hardFalling()
{
	// TODO - implement Block::hardFalling
	throw "Not yet implemented";
}
