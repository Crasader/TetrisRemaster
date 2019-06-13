#include "GamePlayScene.h"
#include "PauseMenuScene.h"
#include "Blocks/Block.h"
#include "Blocks/TBlock.h"


void TetrisGame::GamePlayScene::handleAction(int PlayerAction_action)
{
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
			Vec2(0, i * BLOCK_SIZE),
			Vec2(BLOCK_SIZE * MAX_COL, i * BLOCK_SIZE),
			Color4F(Color3B::WHITE, 0.2)
		);

		playArea->addChild(draw,-1);
	}

	for (int i = 0; i <= MAX_COL; i++)
	{
		auto draw = DrawNode::create();
		draw->drawLine(
			Vec2(i * BLOCK_SIZE, 0),
			Vec2(i * BLOCK_SIZE, BLOCK_SIZE * 20),
			Color4F(Color3B::WHITE, 0.2)
		);

		playArea->addChild(draw, - 1);
	}
}

cocos2d::Scene* TetrisGame::GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool TetrisGame::GamePlayScene::init()
{
	// TODO - implement GamePlayScene::Init
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();


	drawPlayArea();

	drawUI();

	// Test Custom Node: TBlock
	auto tBlock = TBlock::create(Block::COLOR::RED);
	tBlock->setAnchorPoint(Vec2(0.5f,0.5f));
	nextBlockContainer->addChild(tBlock);


	// another test: default 0,0 position on playArea
	auto tBlock2 = TBlock::create(Block::COLOR::GREEN);
	playArea->addChild(tBlock2);

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
	// TODO - implement GamePlayScene::setMode
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
}

void TetrisGame::GamePlayScene::Update()
{
	// TODO - implement GamePlayScene::Update
	throw "Not yet implemented";
}

void TetrisGame::GamePlayScene::update(float delta)
{
}

void TetrisGame::GamePlayScene::drawPlayArea()
{
	// init playArea container node
	playArea = Node::create();
	playArea->setAnchorPoint(Vec2(0.f,0.f));
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

void TetrisGame::GamePlayScene::addPauseButton()
{
	auto menuClick_SFX_Path = "sfx/click5.ogg";
	auto kenney_font_path = "fonts/Kenney Future.ttf";

	auto pauseButton = ui::Button::create();
	pauseButton->setZoomScale(0.15);
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
