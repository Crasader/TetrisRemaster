#include "StartMenuScene.h"
#include "AppDelegate.h"
#include "SettingScene.h"
#include "HighScoreScene.h"

ui::Button* TetrisGame::StartMenuScene::btnNewGame = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnContinue = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnAbout = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnSetting = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnHighScore = nullptr;
ui::Button* TetrisGame::StartMenuScene::btnQuit = nullptr;
ui::CheckBox* TetrisGame::StartMenuScene::tglMusic = nullptr;

void TetrisGame::StartMenuScene::handleButtonsClick()
{
	auto menuClick_SFX_Path = "sfx/click5.ogg";
	btnNewGame->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		auto scene = ChooseModeScene::createScene();
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
		auto scene = SettingScene::createScene();
		Director::getInstance()->pushScene(scene);
	});

	btnHighScore->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);

		auto players = std::vector<Player>({
			{Player("Ninh", 50)},
			{Player("Phu", 100)},
			{Player("Thanos", 58)}
		});

		auto scene = HighScoreScene::create(players);
		Director::getInstance()->pushScene(scene);
	});

	// sfx when click
	btnQuit->addClickEventListener([=](Ref*)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		Director::getInstance()->end();
	});

	tglMusic->addEventListener([=](Ref* ref, ui::CheckBox::EventType e)
	{
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		if (e == ui::CheckBox::EventType::SELECTED)
		{
			experimental::AudioEngine::setVolume(
				AppDelegate::getBackgroundMusicId(), 1.0f);
		}
		else
		{
			experimental::AudioEngine::setVolume(
				AppDelegate::getBackgroundMusicId(), 0.0f);
		}
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

	tglMusic = ui::CheckBox::create("ui/audioOff.png", "ui/audioOn.png");
	tglMusic->setPosition(Vec2(292.f, 63.f));
	tglMusic->setSelected(true);
	scene->addChild(tglMusic);


	auto* galaxy_bg = dynamic_cast<Sprite*>(scene->getChildByName("galaxy-bg"));

	// add background scoller to this scene
	auto bg_size = galaxy_bg->getContentSize();
	BackgroundScroller bg_scroller(galaxy_bg, 10, bg_size.height / 2);
	bg_scroller.startScroll();


	// click event
	handleButtonsClick();

	return scene;
}

bool TetrisGame::StartMenuScene::init()
{
	return true;
}
