#include "LoseScene.h"
#include "StartMenuScene.h"
#include "HighScoreScene.h"


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
		std::vector<Player> players;
		players.push_back(player);
		auto scene = HighScoreScene::create(players);
		Director::getInstance()->pushScene(scene);
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

void TetrisGame::LoseScene::updateUI()
{
	yourScoreLabel->setString(StringUtils::format("%s's score:", player.getName().c_str()));
	txtScore->setString(StringUtils::format("%d", player.getScore()));
}

Player TetrisGame::LoseScene::getPlayer() const
{
	return player;
}

void TetrisGame::LoseScene::setPlayer(const Player& player)
{
	this->player = player;
	updateUI();
}

TetrisGame::LoseScene* TetrisGame::LoseScene::createScene()
{
	return LoseScene::create();
}

void TetrisGame::LoseScene::initBackGround()
{
	// add background scoller to this scene
	auto galaxy_bg = Sprite::create("creator/ui/Space-Background-Tiled.png");
	galaxy_bg->setPosition(Vec2(507, 1330));
	this->Node::addChild(galaxy_bg, -1); // Tree In-order travel, <0 is left tree, >=0 is right tree 

	auto bg_size = galaxy_bg->getContentSize();
	BackgroundScroller bg_scroller(galaxy_bg, 10, bg_size.height / 2);
	bg_scroller.startScroll();
}

void TetrisGame::LoseScene::initLabel(const char* kenney_font_path)
{
	yourScoreLabel = Label::createWithTTF("Your Score:", kenney_font_path, 80);
	yourScoreLabel->setPosition(369, 694);
	this->Node::addChild(yourScoreLabel);

	auto labelTime = Label::createWithTTF("Time: ", kenney_font_path, 60);
	labelTime->setPosition(393, 575);
	this->Node::addChild(labelTime);

	txtScore = Label::createWithTTF("1000", kenney_font_path, 80);
	txtScore->setTextColor(Color4B(Color3B(24, 240, 27)));
	txtScore->setPosition(829, 694);
	this->Node::addChild(txtScore);

	txtTime = Label::createWithTTF("01:59", kenney_font_path, 60);
	txtTime->setTextColor(Color4B(Color3B(240, 112, 27)));
	txtTime->setPosition(633, 574);
	this->Node::addChild(txtTime);
}

void TetrisGame::LoseScene::initMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto MENU_MARGIN_BOTTOM = 70;
	auto BUTTON_SPACING = 50;

	auto menu = ui::Layout::create();
	menu->setPosition(Vec2(visibleSize.width / 2, MENU_MARGIN_BOTTOM));
	menu->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	this->addChild(menu);

	auto btnNormalPath = "ui/blue_button04.png";
	auto btnSelectedPath = "ui/yellow_button05.png";
	auto KenneyFutureNarrow = "fonts/Kenney Future Narrow.ttf";
	
	auto TOTAL_BUTTON = 4;
	ui::Button** buttons[] = { &btnRestart, &btnHighScore, &btnMainMenu, &btnQuit };

	for (int i = 0; i < TOTAL_BUTTON; ++i)
	{
		int reverseIndex = TOTAL_BUTTON - i - 1;
		*buttons[reverseIndex] = ui::Button::create(btnNormalPath, btnSelectedPath);
		auto btnSize = Size(240,60);
		(*buttons[reverseIndex])->setContentSize(btnSize);
		(*buttons[reverseIndex])->setScale9Enabled(true);
		(*buttons[reverseIndex])->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		(*buttons[reverseIndex])->setPosition(Vec2(0, i * (BUTTON_SPACING + btnSize.height)));
		(*buttons[reverseIndex])->setTitleLabel(Label::createWithTTF("", KenneyFutureNarrow, 35));
		menu->addChild((*buttons[reverseIndex]));
	}

	btnRestart->setTitleText("Restart");
	btnHighScore->setTitleText("High Score");
	btnMainMenu->setTitleText("Main Menu");
	btnQuit->setTitleText("Quit");
}

bool TetrisGame::LoseScene::init()
{
	if (!Scene::init())
		return false;

	auto kenney_font_path = "fonts/Kenney Future.ttf";

	initLabel(kenney_font_path);

	initMenu();

	initBackGround();

	// click event
	handleButtonsClick();
	
	return true;
}
