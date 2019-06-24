#ifndef LOSESCENE_H
#define LOSESCENE_H

#include "cocos2d.h"
#include "BackgroundScroller.h"
#include "AudioEngine.h"
#include "Player.h"
#include "ui/UIButton.h"

USING_NS_CC;

namespace TetrisGame {
	class LoseScene : public cocos2d::Scene {
	private:

		ui::Button* btnRestart = nullptr;
		ui::Button* btnHighScore = nullptr;
		ui::Button* btnMainMenu = nullptr;
		ui::Button* btnQuit = nullptr;
		Label* txtScore = nullptr;
		Label* txtTime = nullptr;
		Label* yourScoreLabel = nullptr;
		void handleButtonsClick();

		Player player;
		void updateUI();
		void initBackGround();
		void initLabel(const char* kenney_font_path);
		void initMenu();
	public:
		Player getPlayer() const;
		void setPlayer(const Player& player);
		static LoseScene* createScene();

		
		bool init() override;

		CREATE_FUNC(LoseScene);
	};
}

#endif
