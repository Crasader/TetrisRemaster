#ifndef TBLOCK_H
#define TBLOCK_H
#include "Block.h"
#include "define.h"

namespace TetrisGame {
	class TBlock : public TetrisGame::Block {
	private:

	public:

		TBlock()
		{
		}

		TBlock(COLOR color)
			: Block(color)
		{
		}

		bool init() override;
		CREATE_FUNC_BLOCK(TBlock);

		Block* clone() const override;
	};
}

#endif
