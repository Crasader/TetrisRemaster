#include "LoseScene.h"
#include "StartMenuScene.h"

ui::Button* TetrisGame::LoseScene::btnRestart = nullptr;
ui::Button* TetrisGame::LoseScene::btnHighScore = nullptr;
ui::Button* TetrisGame::LoseScene::btnMainMenu = nullptr;
ui::Button* TetrisGame::LoseScene::btnQuit = nullptr;
Label* TetrisGame::LoseScene::txtScore = nullptr;
Label* TetrisGame::LoseScene::txtTime = nullptr;

void TetrisGame::LoseScene::handleButtonsClick()
{
	auto menuClick_SFX_Path = "sfx/click5.ogg";

	btnRestart->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	btnHighScore->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	btnMainMenu->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		auto scene = StartMenuScene::createScene();

		Director::getInstance()->popToRootScene();
		Director::getInstance()->replaceScene(scene);
	});

	btnQuit->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		Director::getInstance()->end();
	});
}

cocos2d::Scene* TetrisGame::LoseScene::createScene()
{
	creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("creator/scenes/LoseMenu.ccreator");
	reader->setup();
	Scene* scene = reader->getSceneGraph();

	btnRestart = dynamic_cast<ui::Button*>(scene->getChildByName("btnRestart"));
	btnHighScore = dynamic_cast<ui::Button*>(scene->getChildByName("btnHighScore"));
	btnMainMenu = dynamic_cast<ui::Button*>(scene->getChildByName("btnMainMenu"));
	btnQuit = dynamic_cast<ui::Button*>(scene->getChildByName("btnQuit"));
	txtScore = dynamic_cast<Label*>(scene->getChildByName("txtScore"));
	txtTime = dynamic_cast<Label*>(scene->getChildByName("txtTime"));
	auto *galaxy_bg = dynamic_cast<Sprite*>(scene->getChildByName("galaxy-bg"));
	
	txtScore->setString("1000");
	txtTime->setString("01:59");

	// add background scoller to this scene
	auto bg_size = galaxy_bg->getContentSize();
	BackgroundScroller bg_scroller(galaxy_bg, 10, bg_size.height / 2);
	bg_scroller.startScroll();

	// click event
	handleButtonsClick();

	return scene;
}

bool TetrisGame::LoseScene::init()
{
	return true;
}
