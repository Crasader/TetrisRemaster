#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "Block.h"
#include "define.h"

namespace TetrisGame {
	class ZBlock : public TetrisGame::Block {
	private:

	public:
		ZBlock(){}
		ZBlock(COLOR color):Block(color){}

		bool init() override;
		CREATE_FUNC_BLOCK(ZBlock);

		Block* clone() const override;
	};
}

#endif
