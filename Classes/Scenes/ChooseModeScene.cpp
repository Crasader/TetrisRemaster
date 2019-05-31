#include "ChooseModeScene.h"

USING_NS_CC;

void TetrisGame::ChooseModeScene::onClickPuzzleMenuItem(cocos2d::Ref *)
{
	auto scene = GamePlayScene::create();
	scene->setMode(GAME_MODE::PUZZLE);

	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void TetrisGame::ChooseModeScene::onClickSurvivalMenuItem(cocos2d::Ref *)
{
}

void TetrisGame::ChooseModeScene::onClickBackMenuItem(cocos2d::Ref *)
{
	Director::getInstance()->popScene();
}

cocos2d::Scene * TetrisGame::ChooseModeScene::createScene()
{
	//auto scene = Scene::create();
	//auto layer = ChooseModeScene::create();
	//scene->addChild(layer);

	return ChooseModeScene::create();
}

bool TetrisGame::ChooseModeScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	// Mode menu
	auto puzzleMenuItem = MenuItemFont::create("Puzzle", CC_CALLBACK_1(ChooseModeScene::onClickPuzzleMenuItem, this));
	auto survivalMenuItem = MenuItemFont::create("Survival", CC_CALLBACK_1(ChooseModeScene::onClickSurvivalMenuItem, this));
	auto backMenuItem = MenuItemFont::create("Back", CC_CALLBACK_1(ChooseModeScene::onClickBackMenuItem, this));

	puzzleMenuItem->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 10) * 5));
	survivalMenuItem->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 10) * 4));
	backMenuItem->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 10) * 2));

	auto menu = Menu::create(puzzleMenuItem, survivalMenuItem, backMenuItem, nullptr);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);

	return true;
}
