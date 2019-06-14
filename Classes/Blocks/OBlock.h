#ifndef OBLOCK_H
#define OBLOCK_H
#include "Block.h"

namespace TetrisGame {
	class OBlock :public TetrisGame::Block {
	private:

	public:
		OBlock(){}
		OBlock(COLOR color): Block(color){}

		bool init() override;
		
		CREATE_FUNC_BLOCK(OBlock);

		Block* clone() const override;
	};
}

#endif
