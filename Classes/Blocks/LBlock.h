#ifndef LBLOCK_H
#define LBLOCK_H
#include "Block.h"
#include "define.h"

namespace TetrisGame {
	class LBlock : public TetrisGame::Block {
	private:

	public:
		LBlock(){}

		LBlock(COLOR color): Block(color){}

		bool init() override;

		CREATE_FUNC_BLOCK(LBlock);

		Block* clone() const override;
	};
}

#endif
