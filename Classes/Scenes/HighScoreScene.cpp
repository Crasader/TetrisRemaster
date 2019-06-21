#include "HighScoreScene.h"

HighScoreScene* HighScoreScene::create(std::vector<Player> players)
{
	HighScoreScene* pRet = new(std::nothrow) HighScoreScene();
	pRet->dataSource = players;
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}


void HighScoreScene::initListView(Size VISIBLE_SIZE, const char* kenney_font_path)
{
	// list view item widget
	auto itemSize = Size(500.f, 40.f);


	// input control list view
	auto highScoreLstVw = ui::ListView::create();
	highScoreLstVw->setContentSize(Size(itemSize.width, VISIBLE_SIZE.height / 2));
	highScoreLstVw->setPosition(Vec2(VISIBLE_SIZE.width / 2 - itemSize.width / 2, 0));
	highScoreLstVw->setItemsMargin(30);
	//gameControlLstVw->setUserData(&controlInfo);

	this->Node::addChild(highScoreLstVw);


	highScoreLstVw->setInnerContainerSize(Size(itemSize.width, itemSize.height * dataSource.size()));
	// add data
	for (auto player : dataSource)
	{
		auto itemLstVw = ui::Layout::create();
		itemLstVw->setLayoutType(ui::Layout::Type::RELATIVE);
		itemLstVw->setContentSize(itemSize);


		ui::RelativeLayoutParameter* rp_LeftCenter = ui::RelativeLayoutParameter::create();
		rp_LeftCenter->setAlign(ui::RelativeLayoutParameter::RelativeAlign::PARENT_LEFT_CENTER_VERTICAL);

		auto lblName = ui::Text::create(player.getName(), kenney_font_path, 40);
		lblName->setLayoutParameter(rp_LeftCenter);

		auto MARGIN = 10.f;


		ui::RelativeLayoutParameter* rp_RightCenter = ui::RelativeLayoutParameter::create();
		rp_RightCenter->setAlign(ui::RelativeLayoutParameter::RelativeAlign::PARENT_RIGHT_CENTER_VERTICAL);

		auto lblScore = ui::Text::create(StringUtils::format("%d", player.getScore()), kenney_font_path, 40);
		lblScore->setLayoutParameter(rp_RightCenter);


		itemLstVw->addChild(lblName);
		itemLstVw->addChild(lblScore);

		highScoreLstVw->pushBackCustomItem(itemLstVw);
	}
}

void HighScoreScene::initBackButton(Size VISIBLE_SIZE)
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

void HighScoreScene::initTitle(const char* kenney_font_path)
{
	// scene title
	auto labelTitle = Label::createWithTTF("High Score", kenney_font_path, 60);
	labelTitle->setPosition(517, 695);
	this->Node::addChild(labelTitle);
}

void HighScoreScene::initBackground()
{
	// Galaxy background
	auto galaxy_bg = Sprite::create("creator/ui/Space-Background-Tiled.png");
	galaxy_bg->setPosition(Vec2(507, 1330));
	this->Node::addChild(galaxy_bg, -1); // Tree In-order travel, <0 is left tree, >=0 is right tree 
}

bool HighScoreScene::init()
{
	if (!Scene::init())
		return false;

	auto VISIBLE_SIZE = Director::getInstance()->getVisibleSize();

	auto kenney_font_path = "fonts/Kenney Future.ttf";

	// data for list view, pass it in HighScoreScene::create(player)
	

	initTitle(kenney_font_path);


	initBackButton(VISIBLE_SIZE);


	initListView(VISIBLE_SIZE, kenney_font_path);


	initBackground();

	return true;
}
