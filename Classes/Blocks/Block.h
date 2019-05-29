#ifndef BLOCK_H
#define BLOCK_H

namespace TetrisGame {
	class Block {

	protected:
		int color;
		vector<bitset> shape;
		vector<vector<bitset>> rotateShapes;
		Point2D bottomLeftPos;

	public:
		virtual void virtual_Rotate() = 0;

		void softFalling();

		void hardFalling();
	};
}

#endif
