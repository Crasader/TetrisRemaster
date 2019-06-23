#include "SettingScene.h"
#include "KeyboardCode2String.h"
#include "AudioEngine.h"
#include "ui/UIText.h"
#include "GamePlayScene.h"
#include "AppDelegate.h"
#include "BackgroundScroller.h"

cocos2d::Scene* TetrisGame::SettingScene::createScene()
{
	return SettingScene::create();
}

void TetrisGame::SettingScene::initBackbutton(Size VISIBLE_SIZE)
{
	// back button
	const auto btn_Margin = 75.f;
	auto btnBack = ui::Button::create("ui/exitRight.png");
	btnBack->setPosition(Vec2(VISIBLE_SIZE.width - btn_Margin, 0 + btn_Margin));
	btnBack->addClickEventListener([=](Ref*)
	{
		auto menuClick_SFX_Path = "sfx/click5.ogg";
		experimental::AudioEngine::play2d(menuClick_SFX_Path);
		Director::getInstance()->popScene();
	});
	this->Node::addChild(btnBack);
}

void TetrisGame::SettingScene::initBackground()
{
	// Galaxy background
	auto galaxy_bg = Sprite::create("creator/ui/Space-Background-Tiled.png");
	galaxy_bg->setPosition(Vec2(507, 1330));
	this->Node::addChild(galaxy_bg, -1); // Tree In-order travel, <0 is left tree, >=0 is right tree 


	auto bg_size = galaxy_bg->getContentSize();
	BackgroundScroller bg_scroller(galaxy_bg, 10, bg_size.height / 2);
	bg_scroller.startScroll();
}

void TetrisGame::SettingScene::initListView(const char* kenney_font_path, Size VISIBLE_SIZE)
{
	controlInfoMap = &AppDelegate::controlInfoMap;

	// list view item widget
	auto itemSize = Size(500.f, 40.f);
	itemSize = Size(VISIBLE_SIZE.width/2, 40.f);

	// input control list view
	auto gameControlLstVw = ui::ListView::create();
	gameControlLstVw->setContentSize(Size(itemSize.width, VISIBLE_SIZE.height / 2));
	gameControlLstVw->setPosition(Vec2(VISIBLE_SIZE.width / 2 - itemSize.width / 2, 0));
	gameControlLstVw->setItemsMargin(30);

	this->addChild(gameControlLstVw);


	gameControlLstVw->setInnerContainerSize(Size(itemSize.width, itemSize.height * (*controlInfoMap).size()));
	// add data

	for (auto&& pair : *controlInfoMap)
	{
		// draw ui
		auto itemLstVw = ui::Layout::create();
		itemLstVw->setLayoutType(ui::Layout::Type::RELATIVE);
		itemLstVw->setContentSize(itemSize);

		ui::RelativeLayoutParameter* rp_LeftCenter = ui::RelativeLayoutParameter::create();
		rp_LeftCenter->setAlign(ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_CENTER_VERTICAL);

		auto lblDescription = ui::Text::create(TetrisGame::getActionName(pair.first), kenney_font_path, 40);
		lblDescription->setLayoutParameter(rp_LeftCenter);

		auto MARGIN = 10.f;

		ui::RelativeLayoutParameter* rp_RightCenter = ui::RelativeLayoutParameter::create();
		rp_RightCenter->setAlign(ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_CENTER_VERTICAL);

		auto btnChangeControl = ui::Button::create("ui/blue_button05.png");
		btnChangeControl->setTitleLabel(Label::createWithTTF(KeyboardCode2String::getName(pair.second),
		                                                     "fonts/Kenney Future Narrow.ttf", 30));
		btnChangeControl->setLayoutParameter(rp_RightCenter);


		// begin modifying, Keyboard event start listen  
		btnChangeControl->addClickEventListener([=](Ref*)
		{
			btnChangeControl->setTitleText("???");
			pairAction_Key = &pair;
			pressedButton = btnChangeControl;
		});

		itemLstVw->addChild(lblDescription);
		itemLstVw->addChild(btnChangeControl);

		gameControlLstVw->pushBackCustomItem(itemLstVw);
	}
}

bool TetrisGame::SettingScene::init()
{
	if (!Scene::init())
		return false;

	auto kenney_font_path = "fonts/Kenney Future.ttf";

	// label
	auto labelSetting = Label::createWithTTF("Setting", kenney_font_path, 60);
	labelSetting->setPosition(517, 695);
	this->addChild(labelSetting);

	auto labelControl = Label::createWithTTF("Control", kenney_font_path, 40);
	labelControl->setPosition(141, 450);
	this->addChild(labelControl);


	auto VISIBLE_SIZE = Director::getInstance()->getVisibleSize();

	initListView(kenney_font_path, VISIBLE_SIZE);

	initBackground();

	initBackbutton(VISIBLE_SIZE);

	// Keyboard handle
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(SettingScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void TetrisGame::SettingScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* e)
{
	const char* keyName = KeyboardCode2String::getName(keyCode);
	log("Key %s was pressed! Value is %d", keyName, unsigned short(keyCode));


	// only process if the button associate with has clicked
	if (pressedButton != nullptr)
	{
		log("Modifying action: %s", getActionName(pairAction_Key->first));

		// check if any `PlayerAction` key associated with this `keyCode` value
		bool isKeyCodeHasAssociated = false;
		for (auto&& pair : *controlInfoMap)
		{
			if (pair.second == keyCode)
			{
				isKeyCodeHasAssociated = true;
				//pair.second = EventKeyboard::KeyCode::KEY_NONE;
			}
		}


		if (! isKeyCodeHasAssociated)
		{
			// update new key code
			(*controlInfoMap)[pairAction_Key->first] = keyCode;
			pressedButton->setTitleText(keyName);
		}
		else
		{
			// restore previous key code
			pressedButton->setTitleText(KeyboardCode2String::getName((*controlInfoMap)[pairAction_Key->first]));
		}

		pressedButton = nullptr;


		// debug
		log("Control key updated:");
		for (auto pair : *controlInfoMap)
		{
			log("%s : %s", getActionName(pair.first),
			    KeyboardCode2String::getName(pair.second));
		}
	}
}
