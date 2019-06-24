#ifndef CHOOSEMODESCENE_H
#define CHOOSEMODESCENE_H

#include "cocos2d.h"
#include "GamePlayScene.h"
#include "CreatorReader.h"
#include "AudioEngine.h"
#include "BackgroundScroller.h"

USING_NS_CC;

namespace TetrisGame {
	class ChooseModeScene : public cocos2d::Scene {
	private:
		enum Difficult
		{
			Easy,
			Medium,
			Hard,
		};
		
		static ui::Button* btnSurvival;
		static ui::Button* btnPuzzle;
		static ui::Button* btnTimeRacing;
		static ui::Button* btnBack;
		static ChooseModeScene::Difficult currentDifficult;
		static std::map<Difficult, float> speed;
		static void handleButtonsClick();
		static void initDifficultRadioButton(Scene* scene, Size SCREEN_SIZE);

	public:
		static cocos2d::Scene* createScene();
		virtual bool init();

		CREATE_FUNC(ChooseModeScene);
	};
}

#endif
