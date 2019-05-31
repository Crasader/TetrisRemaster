#ifndef CHOOSEMODESCENE_H
#define CHOOSEMODESCENE_H

#include "cocos2d.h"
#include "GamePlayScene.h"

namespace TetrisGame {
	class ChooseModeScene : public cocos2d::Scene {
	private:
		void onClickPuzzleMenuItem(cocos2d::Ref*);
		void onClickSurvivalMenuItem(cocos2d::Ref*);
		void onClickBackMenuItem(cocos2d::Ref*);

	public:
		static cocos2d::Scene* createScene();
		virtual bool init();

		CREATE_FUNC(ChooseModeScene);
	};
}

#endif
