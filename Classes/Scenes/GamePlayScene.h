#ifndef GAMEPLAYSCENE_H
#define GAMEPLAYSCENE_H
#include <vector>
#include "cocos2d.h"
#include "PuzzleMode.h"
#include "SurvivalMode.h"
#include "define.h"

USING_NS_CC;

namespace TetrisGame {
	enum GAME_MODE {
		PUZZLE = 1,
		SURVIVAL = 2
	};

	class GamePlayScene : public cocos2d::Scene {

	private:
		int currentScore;
		std::vector<int> highScore;
		GameMode *game = nullptr;
		Label* txtBest = nullptr;
		Label* txtCurrent = nullptr;
		Node* nextBlockContainer = nullptr;	// use this Node as container to add custom Node inherited from Block: TBlock, OBlock,...
		Node* playArea = nullptr;	// play area container
		
		void drawGrid();
		void addPauseButton();
		void initGameMode();
		void drawPlayArea();
		void drawUI();
	public:

		static cocos2d::Scene* createScene();

		virtual bool init();
		CREATE_FUNC(GamePlayScene);

		void handleAction(int PlayerAction_action);


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

		void Update();

		void update(float delta) override;
	};
}

#endif
