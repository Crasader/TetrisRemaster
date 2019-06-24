#include "Block.h"

int TetrisGame::Block::getCurrentAngle() const
{
	return currentAngle;
}

void TetrisGame::Block::setCurrentAngle(int current_angle)
{
	currentAngle = current_angle;
}

std::vector<std::vector<Sprite*>> TetrisGame::Block::getUnitBlocks() const
{
	return unitBlocks;
}

std::vector<std::vector<short>> TetrisGame::Block::getShape()
{
	return shape;
}

void TetrisGame::Block::loadShapeData(std::string filePath)
{
	std::string data;
	std::stringstream ss;

	data = FileUtils::getInstance()->getStringFromFile(filePath);
	ss << data;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ss >> shape[i][j];
		}
	}
}

TetrisGame::Block::Block()
{
}

TetrisGame::Block::Block(COLOR color)
{
	this->color = color;
	Node();
}

std::vector<int> TetrisGame::Block::getLeftMostCols()
{
	std::vector<int> leftMostCols;
	for (int i = 0; i < shape.size(); i++)
	{
		int j = 0;
		
		while (j < shape[i].size() && shape[i][j] != 1) { j++; }

		if (j < shape[i].size())
		{
			leftMostCols.push_back(j);
		}
	}
	return leftMostCols;
}

std::vector<int> TetrisGame::Block::getRightMostCols()
{
	std::vector<int> rightMostCols;
	for (int i = 0; i < shape.size(); i++)
	{
		int j = shape.size() - 1;

		while (j >= 0 && shape[i][j] != 1) { j--; }
		if (j >= 0)
		{
			rightMostCols.push_back(j);
		}
	}
	return rightMostCols;
}

std::vector<int> TetrisGame::Block::getLowestRows()
{
	std::vector<int> lowestRows;
	for (int j = 0; j < shape[0].size(); j++)
	{
		int i = shape.size() - 1;
		while (i >= 0 && shape[i][j] != 1) { i--; }
		if (i >= 0)
		{
			lowestRows.push_back(i);
		}
	}
	return lowestRows;
}

void TetrisGame::Block::rotate()
{
	int shapeSize = shape.size();
	Vec2 anchor = Vec2::ZERO;
	std::vector<std::vector<short>> newShape;
	newShape.resize(shapeSize);
	for (auto& v : newShape)
		v.resize(shapeSize);

	std::vector<int> maxYs;
	maxYs.reserve(shapeSize);
	std::for_each(shape.begin(), shape.end(), [&maxYs](const std::vector<short>& v) {
		int maxY = v.size() - 1;
		while (v[maxY] != 1 && maxY > 0)
			maxY--;

		maxYs.push_back(maxY);
	});

	int shift = *std::max_element(maxYs.begin(), maxYs.end());

	for (int row = 0; row < shapeSize; row++)
	{
		for (int col = 0; col < shapeSize; col++)
		{
			if (shape[row][col] == 1)
			{
				int newRow = (shapeSize - 1) + col - shift;
				int newCol = (shapeSize - 1) - row;

				newShape[newRow][newCol] = 1;
			}
		}
	}

	shape = newShape;
	for (auto& row : unitBlocks)
		for (auto& unitBlock : row)
		{
			if (unitBlock != nullptr)
			{
				unitBlock->removeFromParent();
				unitBlock = nullptr;
			}
		}

	for (int row = 0; row < shapeSize; row++)
	{
		for (int col = 0; col < shapeSize; col++)
		{
			if (shape[row][col])
			{
				//this->removeChild(unitBlocks[row][col], true);
				//unitBlocks[row][col] = NULL;
				auto block = Sprite::create(color_map[color]);

				block->setContentSize(Size(
					TetrisGame::BLOCK_SIZE,
					TetrisGame::BLOCK_SIZE));

				block->setPosition(
					BLOCK_SIZE * col,
					BLOCK_SIZE * (shape.size() - 1 - row));

				block->setAnchorPoint(Vec2(0.f, 0.f));

				this->addChild(block);
				unitBlocks[row][col] = block;
			}
		}
	}

	initContentSize();
	currentAngle += 90;
}

void TetrisGame::Block::initContentSize()
{
	auto maxWidth = 0;
	for (int i = 0; i < 4; i++)
	{
		int j = 4 - 1;
		while (j >= 0)
		{
			if (shape[i][j] == 1 && (j + 1) * BLOCK_SIZE > maxWidth)
			{
				maxWidth = (j + 1) * BLOCK_SIZE;
			}
			j--;
		}
	}


	auto maxHeight = 0;
	for (int j = 0 ; j < 4; j++)
	{
		int i = 0;
		while (i < 4)
		{
			if (shape[i][j] == 1 && (4 - i) * BLOCK_SIZE > maxHeight)
			{
				maxHeight = (4 - i) * BLOCK_SIZE;
			}
			i++;
		}
	}
	this->setContentSize(Size(maxWidth, maxHeight));
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
					BLOCK_SIZE * (shape.size() - 1 - row));

				block->setAnchorPoint(Vec2(0.f, 0.f));
				unitBlocks[row][col] = block;
			}
		}
	}
	this->setAnchorPoint(Vec2(0.f, 0.f));

	initContentSize();
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
