#pragma once
#include "cocos2d.h"
#include "ui/UIListView.h"
#include "ui/UIText.h"
#include "ui/UIButton.h"
#include "Player.h"
#include "AudioEngine.h"

USING_NS_CC;

class HighScoreScene :
	public Scene
{
private:
	void initListView(Size VISIBLE_SIZE, const char* kenney_font_path);
	void initBackButton(Size VISIBLE_SIZE);
	void initTitle(const char* kenney_font_path);
	void initBackground();
	std::vector<Player> dataSource;
public:
	
	bool init() override;
	// CREATE_FUNC(HighScoreScene);
	static HighScoreScene* create(std::vector<Player> players);
};
