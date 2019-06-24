#include "GamePlayScene.h"
#include "PauseMenuScene.h"
#include "Blocks/Block.h"
#include "AppDelegate.h"
#include "LoseScene.h"


TetrisGame::GameMode* TetrisGame::GamePlayScene::getGameMode() const
{
	return game;
}

void TetrisGame::GamePlayScene::setGameMode(GameMode* game)
{
	this->game = game;
}

void TetrisGame::GamePlayScene::drawGrid()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	for (int i = 1; i <= MAX_ROW; i++)
	{
		auto draw = DrawNode::create();
		draw->drawLine(
			Vec2(0, i * BLOCK_SIZE),
			Vec2(BLOCK_SIZE * MAX_COL, i * BLOCK_SIZE),
			Color4F(Color3B::WHITE, 0.2f)
		);

		playArea->addChild(draw, -1);
	}

	for (int i = 0; i <= MAX_COL; i++)
	{
		auto draw = DrawNode::create();
		draw->drawLine(
			Vec2(i * BLOCK_SIZE, 0),
			Vec2(i * BLOCK_SIZE, BLOCK_SIZE * 20),
			Color4F(Color3B::WHITE, 0.2f)
		);

		playArea->addChild(draw, - 1);
	}
}

cocos2d::Scene* TetrisGame::GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

void TetrisGame::GamePlayScene::initGameMode()
{
	auto nextBlock = this->game->getNextBlock();
	nextBlockContainer->addChild(nextBlock);

	auto currentBlock = this->game->getCurrentBlock();
	playArea->addChild(currentBlock);
}

void TetrisGame::GamePlayScene::initDialog()
{
	auto windowsSize = Director::getInstance()->getVisibleSize();

	// Enter name dialog
	Size dlgSize(440, 240);
	auto pos = Vec2(windowsSize.width / 2, windowsSize.height / 2);
	float margin = 10;
	
	// layout container
	myDlg = ui::Layout::create();
	myDlg->setBackGroundImageScale9Enabled(true);
	myDlg->setBackGroundImage("ui/grey_panel.png");
	myDlg->setContentSize(dlgSize);
	myDlg->setAnchorPoint(Vec2(0.5f, 0.5f));
	myDlg->setOpacity(150);
	myDlg->setPosition(pos);
	myDlg->setTouchEnabled(true);
	myDlg->setVisible(false);
	this->Node::addChild(myDlg, 2);

	// Text field
	auto txtName = ui::TextField::create("Enter your name", "Arial", 30);
	auto txtNamePos = Vec2(dlgSize.width / 2, dlgSize.height / 2);
	txtName->setPosition(txtNamePos);
	txtName->setTextColor(Color4B::BLACK);
	myDlg->addChild(txtName);

	auto textFieldTFF = TextFieldTTF::createWithTTF("", "", 30);

	// OK button
	auto kenney_font_path = "fonts/Kenney Future.ttf";
	auto btnOK = ui::Button::create("ui/blue_button05.png");
	auto btnOK_MARGIN_TOP = 70;
	btnOK->setPosition(Vec2(txtNamePos.x, txtNamePos.y - btnOK_MARGIN_TOP));
	btnOK->setTitleLabel(Label::createWithTTF("OK", kenney_font_path, 30));
	btnOK->addClickEventListener([=](Ref*)
	{
		auto playerName = txtName->getString();
		log("Entered name: %s", playerName.c_str());

		auto scene = LoseScene::createScene();
		scene->setPlayer(Player(playerName, this->currentScore));
		Director::getInstance()->replaceScene(scene);
		
	});
	myDlg->addChild(btnOK);
}

bool TetrisGame::GamePlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	this->key = &AppDelegate::controlInfoMap;
	auto visibleSize = Director::getInstance()->getVisibleSize();

	drawPlayArea();

	drawUI();

	initDialog();

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(GamePlayScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void TetrisGame::GamePlayScene::End()
{
	// TODO - implement GamePlayScene::End
	throw "Not yet implemented";
}

void TetrisGame::GamePlayScene::Save()
{
	// TODO - implement GamePlayScene::Save
	throw "Not yet implemented";
}

void TetrisGame::GamePlayScene::setMode(GAME_MODE gameMode)
{
	switch (gameMode)
	{
	case GAME_MODE::PUZZLE:
		this->game = new PuzzleMode();
		break;

	case GAME_MODE::SURVIVAL:
		this->game = new SurvivalMode();
		break;

	default: ;
	}
	initGameMode();
	this->scheduleUpdate();
}

void TetrisGame::GamePlayScene::update(float delta)
{
	if (this->game->isLose())
	{
		this->showDialog();
		this->unscheduleUpdate();
		return;
	}

	static float count_second = 0;
	count_second += delta;
	// not lose yet, still playable
	if (count_second >= this->game->getSpeed())
	{
		if (this->game->canMoveDown())
		{
			this->game->moveBlockDown();
		}
		else
		{
			game->updateCurrentBlock(playArea);
			nextBlockContainer->addChild(game->getNextBlock());
			playArea->addChild(game->getCurrentBlock());
		}
		count_second = 0;
	}

	// update score
	txtCurrent->setString(StringUtils::format("%d", currentScore));
}

void TetrisGame::GamePlayScene::drawPlayArea()
{
	// init playArea container node
	playArea = Node::create();
	playArea->setAnchorPoint(Vec2(0.f, 0.f));
	playArea->setPosition(Vec2(PADDING_LEFT, 0));
	playArea->setContentSize(Size(BLOCK_SIZE * MAX_COL, 768));

	// playArea background sprite
	auto bg_white = Sprite::create("white.png");
	bg_white->setAnchorPoint(Vec2(0, 0));
	bg_white->setContentSize(Size(BLOCK_SIZE * MAX_COL, 768));
	bg_white->setOpacity(39);

	playArea->addChild(bg_white, -2);

	// playArea grid
	drawGrid();

	this->addChild(playArea);
}

void TetrisGame::GamePlayScene::drawUI()
{
	auto kenney_font_path = "fonts/Kenney Future.ttf";
	// pause button
	addPauseButton();

	// label
	auto labelBest = Label::createWithTTF("Best", kenney_font_path, 30);
	labelBest->setPosition(723, 468);
	this->addChild(labelBest);

	auto labelCurrent = Label::createWithTTF("Current", kenney_font_path, 30);
	labelCurrent->setPosition(760, 417);
	this->addChild(labelCurrent);

	auto labelNext = Label::createWithTTF("Next", kenney_font_path, 40);
	labelNext->setPosition(806, 272);
	this->addChild(labelNext);


	// Editable label
	txtBest = Label::createWithTTF("3000", kenney_font_path, 30);
	txtBest->setPosition(903, 468);
	txtBest->setColor(Color3B(199, 20, 20));
	this->addChild(txtBest);

	txtCurrent = Label::createWithTTF("300", kenney_font_path, 30);
	txtCurrent->setPosition(915, 417);
	txtCurrent->setColor(Color3B(247, 136, 15));
	this->addChild(txtCurrent);


	// Next block container init
	nextBlockContainer = Node::create();
	nextBlockContainer->setPosition(Vec2(804.f, 123.f));
	nextBlockContainer->setContentSize(Size(200.f, 200.f));

	auto block_container_bg = Sprite::create("white.png");
	block_container_bg->setContentSize(Size(200.f, 200.f));
	block_container_bg->setOpacity(59);
	nextBlockContainer->addChild(block_container_bg, -1);
	this->addChild(nextBlockContainer);


	// Galaxy background
	auto galaxy_bg = Sprite::create("creator/ui/Space-Background-Tiled.png");
	galaxy_bg->setPosition(Vec2(507, 1330));
	this->addChild(galaxy_bg, -1); // Tree In-order travel, <0 is left tree, >=0 is right tree 
}

void TetrisGame::GamePlayScene::showDialog()
{
	myDlg->setVisible(true);
	myDlg->setScale(0);
	myDlg->runAction(ScaleTo::create(0.5, 1.0));
}

void TetrisGame::GamePlayScene::onKeyPressed(EventKeyboard::KeyCode keycode, Event* e)
{
	if (this->game->isLose())
	{
		return;
	}

	if (keycode == (*key)[MoveLeft])
	{
		if (this->game->canMoveLeft())
		{
			this->game->moveBlockByLeft();
		}
	}
	else if (keycode == (*key)[MoveRight])
	{
		if (this->game->canMoveRight())
		{
			this->game->moveBlockByRight();
		}
	}
	else if (keycode == (*key)[Rotate90])
	{
		if (this->game->isRotatable())
		{
		this->game->rotateBlock();
		}
	}
}

void TetrisGame::GamePlayScene::addPauseButton()
{
	auto menuClick_SFX_Path = "sfx/click5.ogg";
	auto kenney_font_path = "fonts/Kenney Future.ttf";

	auto pauseButton = ui::Button::create();
	pauseButton->setZoomScale(0.15f);
	pauseButton->setPressedActionEnabled(true);
	pauseButton->setPosition(Vec2(807, 635));
	pauseButton->setTitleText("Pause");
	pauseButton->setTitleFontName(kenney_font_path);
	pauseButton->setTitleFontSize(40);
	pauseButton->addClickEventListener([=](Ref*)
	{
		cocos2d::experimental::AudioEngine::play2d(menuClick_SFX_Path);
		auto scene = PauseMenuScene::createScene();
		Director::getInstance()->pushScene(scene);
	});

	this->addChild(pauseButton);
}
