#ifndef PLAYERACTION_H
#define PLAYERACTION_H

namespace TetrisGame {
	enum PlayerAction {
		Unknown,
		MoveLeft, 
		MoveRight, 
		HardFall, 
		Rotate90, 
		HoldBlock
	};

	static const char * getActionName(PlayerAction action)
	{
		switch (action)
		{
		case MoveLeft:
			return "Move Left";
		case MoveRight:
			return "Move Right";
		case HardFall:
			return "Hard Fall";
		case Rotate90:
			return "Rotate 90";
		case HoldBlock:
			return "Hold Block";
		default:
			return "Unknown";
		}
	}
}

#endif
