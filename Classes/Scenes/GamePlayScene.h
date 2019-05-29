#ifndef GAMEPLAYSCENE_H
#define GAMEPLAYSCENE_H
#include <vector>
#include "cocos2d.h"

namespace TetrisGame {
	class GamePlayScene : cocos2d::Scene {

	private:
		int currentScore;
		std::vector<int> highScore;

	public:

		static cocos2d::Scene* createScene();
		virtual bool init();
		CREATE_FUNC(GamePlayScene);

		void handleAction(int PlayerAction_action);

		

		void End();

		void Save();

		void setMode(int GameMode_mode);

		void Update();
	};
}

#endif
