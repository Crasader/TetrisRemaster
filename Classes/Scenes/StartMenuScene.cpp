#include "StartMenuScene.h"

ui::Button* TetrisGame::StartMenuScene::btnNewGame = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnContinue = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnAbout = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnSetting = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnHighScore = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnQuit = nullptr;

void TetrisGame::StartMenuScene::handleButtonsClick()
{
	auto menuClick_SFX_Path = "sfx/click5.ogg";
	btnNewGame->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		auto scene = ChooseModeScene::create();
		Director::getInstance()->pushScene(scene);
	});

	btnContinue->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	btnAbout->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	btnSetting->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	btnHighScore->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	// sfx when click
	btnQuit->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		Director::getInstance()->end();
	});
}

cocos2d::Scene * TetrisGame::StartMenuScene::createScene()
{
	creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("creator/scenes/StartMenu.ccreator");

	// will create the needed sprite sheets + design resolution
	reader->setup();

	// get the scene graph
	Scene* scene = reader->getSceneGraph();

	btnNewGame = dynamic_cast<ui::Button*>(scene->getChildByName("btnNewGame"));
	btnContinue = dynamic_cast<ui::Button*>(scene->getChildByName("btnContinue"));
	btnAbout = dynamic_cast<ui::Button*>(scene->getChildByName("btnAbout"));
	btnSetting = dynamic_cast<ui::Button*>(scene->getChildByName("btnSetting"));
	btnHighScore = dynamic_cast<ui::Button*>(scene->getChildByName("btnHighScore"));
	btnQuit = dynamic_cast<ui::Button*>(scene->getChildByName("btnQuit"));
	
	auto *galaxy_bg = dynamic_cast<Sprite*>(scene->getChildByName("galaxy-bg"));
	

	// add background scoller to this scene
	BackgroundScroller bg_scroller(scene, galaxy_bg, 100, 1330, 0);
	bg_scroller.startScroll();


	// click event
	handleButtonsClick();

	return scene;
}

bool TetrisGame::StartMenuScene::init()
{
	return true;
}
