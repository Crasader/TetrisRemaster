#include "PauseMenuScene.h"
#include "StartMenuScene.h"

ui::Button* TetrisGame::PauseMenuScene::btnResume = nullptr;
ui::Button* TetrisGame::PauseMenuScene::btnSave = nullptr;
ui::Button* TetrisGame::PauseMenuScene::btnRestart = nullptr;
ui::Button* TetrisGame::PauseMenuScene::btnMainMenu = nullptr;

void TetrisGame::PauseMenuScene::handleButtonsClick()
{
	auto menuClick_SFX_Path = "sfx/click5.ogg";
	btnResume->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		Director::getInstance()->popScene();
	});

	btnSave->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
	});

	btnRestart->addClickEventListener([=](Ref*)
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
}

cocos2d::Scene* TetrisGame::PauseMenuScene::createScene()
{
	creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("creator/scenes/PauseMenu.ccreator");
	reader->setup();
	Scene* scene = reader->getSceneGraph();

	btnResume = dynamic_cast<ui::Button*>(scene->getChildByName("btnResume"));
	btnSave = dynamic_cast<ui::Button*>(scene->getChildByName("btnSave"));
	btnRestart = dynamic_cast<ui::Button*>(scene->getChildByName("btnRestart"));
	btnMainMenu = dynamic_cast<ui::Button*>(scene->getChildByName("btnMainMenu"));

	auto *galaxy_bg = dynamic_cast<Sprite*>(scene->getChildByName("galaxy-bg"));

	// add background scoller to this scene
	BackgroundScroller bg_scroller(scene, galaxy_bg, 100, 1330, 0);
	bg_scroller.startScroll();

	// click event
	handleButtonsClick();

	return scene;
}

bool TetrisGame::PauseMenuScene::init()
{
	return true;
}
