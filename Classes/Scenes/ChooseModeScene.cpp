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
		auto scene = GamePlayScene::create();
		scene->setMode(GAME_MODE::SURVIVAL);

		Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(scene);
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

void TetrisGame::ChooseModeScene::initDifficultRadioButton(Scene* scene, Size SCREEN_SIZE)
{
	const char * buttonsTitle[] = { "Easy", "Medium", "Hard" };
	int TOTAL_BUTTON = 3;
	auto SPACE_BETWEEN = 200;
	// difficult radio group

	// create radio group
	auto RADIO_GROUP_MARGIN_BOTTOM = 200;
	auto GROUP_SIZE = Size((TOTAL_BUTTON - 1)* SPACE_BETWEEN, 70);
	auto difficultRadioGroup = ui::RadioButtonGroup::create();
	difficultRadioGroup->setContentSize(GROUP_SIZE);
	difficultRadioGroup->setColor(Color3B::WHITE);
	difficultRadioGroup->setPosition(Vec2(SCREEN_SIZE.width / 2, RADIO_GROUP_MARGIN_BOTTOM));
	scene->Node::addChild(difficultRadioGroup, 2);


	// Create the radio buttons
	for (int i = 0; i < TOTAL_BUTTON; ++i)
	{
		auto radioButton = ui::RadioButton::create("ui/grey_circle.png", "ui/blue_tick.png");
		auto posX = i * SPACE_BETWEEN;
		radioButton->setPosition(Vec2(posX, GROUP_SIZE.height / 2));
		difficultRadioGroup->addRadioButton(radioButton);
		difficultRadioGroup->addChild(radioButton);

		// label
		auto LABEL_MARGIN_TOP = 75;
		auto label = ui::Text::create(buttonsTitle[i], "fonts/Kenney Future.ttf", 30);
		label->setPosition(Vec2(posX, radioButton->getPosition().y - LABEL_MARGIN_TOP));
		difficultRadioGroup->addChild(label);
	}


	// Event handle
	difficultRadioGroup->addEventListener([=](
		Ref* sender, int index, ui::RadioButtonGroup::EventType e )
	{
		log("Difficult selected index: %d", index);
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
	auto bg_size = galaxy_bg->getContentSize();
	BackgroundScroller bg_scroller(galaxy_bg, 10, bg_size.height / 2);
	bg_scroller.startScroll();

	// click event
	handleButtonsClick();


	auto SCREEN_SIZE = Director::getInstance()->getVisibleSize();
	initDifficultRadioButton(scene, SCREEN_SIZE);

	return scene;
}

bool TetrisGame::ChooseModeScene::init()
{
	return true;
}
