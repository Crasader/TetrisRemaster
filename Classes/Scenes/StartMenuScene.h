#ifndef STARTMENUSCENE_H
#define STARTMENUSCENE_H

#include "cocos2d.h"
#include "ChooseModeScene.h"

namespace TetrisGame {
	class StartMenuScene : cocos2d::Scene {
	private:

		void onClickStartMenu(cocos2d::Ref*);
		void onClickLoadGame(cocos2d::Ref*);
	public:
		static cocos2d::Scene* createScene();
		virtual bool init();

		CREATE_FUNC(StartMenuScene);
	};
}

#endif
