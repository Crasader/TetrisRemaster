#ifndef LOSESCENE_H
#define LOSESCENE_H

#include "cocos2d.h"
#include "CreatorReader.h"
#include "BackgroundScroller.h"
#include "AudioEngine.h"

USING_NS_CC;

namespace TetrisGame {
	class LoseScene : cocos2d::Scene {
	private:

		static ui::Button* btnRestart;
		static ui::Button* btnHighScore;
		static ui::Button* btnMainMenu;
		static ui::Button* btnQuit;
		static Label* txtScore;
		static Label* txtTime;
		static void handleButtonsClick();

	public:
		static cocos2d::Scene* createScene();
		bool init() override;

		CREATE_FUNC(LoseScene);
	};
}

#endif
