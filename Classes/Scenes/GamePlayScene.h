#ifndef GAMEPLAYSCENE_H
#define GAMEPLAYSCENE_H
#include <vector>
#include "cocos2d.h"
#include "PuzzleMode.h"
#include "SurvivalMode.h"
#include "define.h"
#include "PlayerAction.h"
#include "ui/UILayout.h"

USING_NS_CC;

namespace TetrisGame {
	enum GAME_MODE {
		PUZZLE = 1,
		SURVIVAL = 2
	};

	class GamePlayScene : public cocos2d::Scene {
	private:
		std::map<PlayerAction, EventKeyboard::KeyCode> *key = nullptr;
		int currentScore;
		std::vector<int> highScore;
		GameMode *game = nullptr;
	public:
		GameMode* getGameMode() const;
		void setGameMode(GameMode* game);
	private:
		Label* txtBest = nullptr;
		Label* txtCurrent = nullptr;
		Node* nextBlockContainer = nullptr;	// use this Node as container to add custom Node inherited from Block: TBlock, OBlock,...
		Node* playArea = nullptr;	// play area container
		ui::Layout* myDlg = nullptr;	// enter name dialog
		
		void drawGrid();
		void addPauseButton();
		void initGameMode();
		void initDialog();
		void drawPlayArea();
		void drawUI();
		void showDialog();		// call this when game over to show up enter name dialog
		void onKeyPressed(EventKeyboard::KeyCode keycode, Event* e);
	public:
		static cocos2d::Scene* createScene();

		virtual bool init();
		CREATE_FUNC(GamePlayScene);


		~GamePlayScene()
		{
			if (this->game != nullptr)
			{
				delete this->game;
				this->game = nullptr;
			}
		}
		void End();

		void Save();

		void setMode(GAME_MODE);

		void update(float delta) override;
	};
}

#endif
