#pragma once
#include "cocos2d.h"
#include "ui/UIButton.h"
#include "ui/UIListView.h"
#include "PlayerAction.h"

USING_NS_CC;

namespace TetrisGame
{
	class SettingScene : cocos2d::Scene
	{
	private:
		ui::Button* pressedButton = nullptr;
		
		std::map<PlayerAction, EventKeyboard::KeyCode>* 
			controlInfoMap = nullptr;		// hold reference from AppDelegate
		
		std::map<PlayerAction, EventKeyboard::KeyCode>::value_type const *
			pairAction_Key = nullptr;		// hold reference of clicked item in list view
		
		void initBackbutton(Size VISIBLE_SIZE);
		void initBackground();
		void initListView(const char* kenney_font_path,
			Size VISIBLE_SIZE);
	public:
		static cocos2d::Scene* createScene();

		bool init() override;
		void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* e);
		CREATE_FUNC(SettingScene);
	};
}
