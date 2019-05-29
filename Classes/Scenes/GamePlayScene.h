#ifndef GAMEPLAYSCENE_H
#define GAMEPLAYSCENE_H

namespace TetrisGame {
	class GamePlayScene : TetrisGame::Scene {

	private:
		int currentScore;
		vector<int> highScore;

	public:
		void handleAction(int PlayerAction_action);

		void Init();

		void End();

		void Save();

		void setMode(int GameMode_mode);

		void Update();
	};
}

#endif
