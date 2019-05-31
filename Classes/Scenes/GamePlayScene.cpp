#include "GamePlayScene.h"

USING_NS_CC;

void TetrisGame::GamePlayScene::handleAction(int PlayerAction_action) {
	// TODO - implement GamePlayScene::handleAction
	throw "Not yet implemented";
}

void TetrisGame::GamePlayScene::drawGrid()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	for (int i = 1; i <= MAX_ROW; i++)
	{
		auto draw = DrawNode::create();
		draw->drawLine(
			Vec2(0, i*BLOCK_SIZE),
			Vec2(BLOCK_SIZE * MAX_COL, i * BLOCK_SIZE),
			Color4F(Color3B::WHITE, 0.2)
		);

		this->addChild(draw);
	}

	for (int i = 0; i <= MAX_COL; i++)
	{
		auto draw = DrawNode::create();
		draw->drawLine(
			Vec2(i * BLOCK_SIZE, 0), 
			Vec2(i * BLOCK_SIZE, BLOCK_SIZE * 20), 
			Color4F(Color3B::WHITE, 0.2)
		);

		this->addChild(draw);
	}
}

cocos2d::Scene * TetrisGame::GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool TetrisGame::GamePlayScene::init() {
	// TODO - implement GamePlayScene::Init
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	// init grid
	drawGrid();

	return true;
}

void TetrisGame::GamePlayScene::End() {
	// TODO - implement GamePlayScene::End
	throw "Not yet implemented";
}

void TetrisGame::GamePlayScene::Save() {
	// TODO - implement GamePlayScene::Save
	throw "Not yet implemented";
}

void TetrisGame::GamePlayScene::setMode(GAME_MODE gameMode) {
	// TODO - implement GamePlayScene::setMode
	switch (gameMode)
	{
		case GAME_MODE::PUZZLE:
			this->game = new PuzzleMode();
			break;

		case GAME_MODE::SURVIVAL:
			this->game = new SurvivalMode();
			break;

		default:;
	}
}

void TetrisGame::GamePlayScene::Update() {
	// TODO - implement GamePlayScene::Update
	throw "Not yet implemented";
}

void TetrisGame::GamePlayScene::update(float delta)
{
}
