#ifndef STARTMENUSCENE_H
#define STARTMENUSCENE_H

#include "cocos2d.h"
#include "CreatorReader.h"
#include "ChooseModeScene.h"
#include "BackgroundScroller.h"
#include "AudioEngine.h"

USING_NS_CC;

namespace TetrisGame {
	class StartMenuScene : cocos2d::Scene {
	private:
		
		static ui::Button* btnNewGame;
		static ui::Button* btnContinue;
		static ui::Button* btnAbout;
		static ui::Button* btnSetting;
		static ui::Button* btnHighScore;
		static ui::Button* btnQuit;
		
		static void handleButtonsClick();

	public:
		static cocos2d::Scene* createScene();
		bool init() override;

		CREATE_FUNC(StartMenuScene);
	};
}

#endif
