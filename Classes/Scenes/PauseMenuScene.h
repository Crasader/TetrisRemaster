#ifndef PAUSEMENUSCENE_H
#define PAUSEMENUSCENE_H

#include "cocos2d.h"
#include "CreatorReader.h"
#include "BackgroundScroller.h"
#include "AudioEngine.h"

USING_NS_CC;

namespace TetrisGame {
	class PauseMenuScene : cocos2d::Scene {
	private:

		static ui::Button* btnResume;
		static ui::Button* btnSave;
		static ui::Button* btnRestart;
		static ui::Button* btnMainMenu;

		static void handleButtonsClick();

	public:
		static cocos2d::Scene* createScene();
		bool init() override;

		CREATE_FUNC(PauseMenuScene);
	};
}

#endif
