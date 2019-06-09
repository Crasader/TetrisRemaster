#include "ChooseModeScene.h"

ui::Button* TetrisGame::ChooseModeScene::btnSurvival = nullptr;
ui::Button* TetrisGame::ChooseModeScene::btnPuzzle = nullptr;
ui::Button* TetrisGame::ChooseModeScene::btnTimeRacing = nullptr;
ui::Button* TetrisGame::ChooseModeScene::btnBack = nullptr;

void TetrisGame::ChooseModeScene::handleButtonsClick()
{
	auto menuClick_SFX_Path = "sfx/click5.ogg";
	btnSurvival->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	btnPuzzle->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);

		auto scene = GamePlayScene::create();
		scene->setMode(GAME_MODE::PUZZLE);

		Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(scene);
	});

	btnTimeRacing->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	btnBack->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		Director::getInstance()->popScene();
	});
}

cocos2d::Scene * TetrisGame::ChooseModeScene::createScene()
{
	creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("creator/scenes/ChooseMode.ccreator");
	reader->setup();
	Scene* scene = reader->getSceneGraph();

	btnSurvival = dynamic_cast<ui::Button*>(scene->getChildByName("btnSurvival"));
	btnPuzzle = dynamic_cast<ui::Button*>(scene->getChildByName("btnPuzzle"));
	btnTimeRacing = dynamic_cast<ui::Button*>(scene->getChildByName("btnTimeRacing"));
	btnBack = dynamic_cast<ui::Button*>(scene->getChildByName("btnBack"));

	auto *galaxy_bg = dynamic_cast<Sprite*>(scene->getChildByName("galaxy-bg"));

	// add background scoller to this scene
	BackgroundScroller bg_scroller(scene, galaxy_bg, 100, 1330, 0);
	bg_scroller.startScroll();

	// click event
	handleButtonsClick();

	return scene;
}

bool TetrisGame::ChooseModeScene::init()
{
	return true;
}
