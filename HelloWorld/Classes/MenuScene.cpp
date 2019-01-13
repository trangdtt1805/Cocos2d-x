#include "MenuScene.h"
#include "LogoScene.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

Scene* MenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();


	//Label
	auto playGame = Label::createWithSystemFont("Hello World!", "Marker Felt", 28);
	playGame->setPosition(screenSize.width / 2, screenSize.height / 2 + 100);

	addChild(playGame);

	auto scaleBig = ScaleTo::create(3.0f, 1.5f);
	auto sequenceLaybel = Sequence::create(scaleBig, nullptr);
	auto repeatLaybel = RepeatForever::create(sequenceLaybel);
	playGame->runAction(repeatLaybel);


	//Menu
	/*auto closeItem = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		[](Ref* sender) {
		exit(0);
	});

	closeItem->setAnchorPoint(Vec2(1, 1)); 
	closeItem->setPosition(800, 480);

	auto myMenu = Menu::create(closeItem, nullptr); 
	myMenu->setPosition(0, 0); 
	addChild(myMenu);*/

	auto itemPlay = MenuItemFont::create("Play", nullptr); 
	auto itemSetting = MenuItemFont::create("Setting", nullptr); 
	auto itemMoreGame = MenuItemFont::create("More Game", nullptr); 
	auto itemAbout = MenuItemFont::create("About", nullptr);    
	
	itemPlay->setPosition(screenSize.width / 2, 200);
	itemPlay->setColor(Color3B::RED);
	itemSetting->setPosition(screenSize.width / 2, 150);
	itemSetting->setColor(Color3B::YELLOW);
	itemMoreGame->setPosition(screenSize.width / 2, 100);
	itemMoreGame->setColor(Color3B::BLUE);
	itemAbout->setPosition(screenSize.width / 2, 50);
	itemAbout->setColor(Color3B::WHITE);
	
	auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoreGame, itemAbout, nullptr); 
	menuLabel->setPosition(0, 0); 
	addChild(menuLabel);


	//button
	auto ratingButton = ui::Button::create("rating_normal.png", "rating_pressed.png");
	ratingButton->addClickEventListener([&](Ref* event)
	{
		log("Rating clicked");
	});

	ratingButton->setAnchorPoint(Vec2(1, 0));
	ratingButton->setPosition(Vec2(screenSize.width, 0));
	ratingButton->setScale(0.5f);
	addChild(ratingButton);

	//Creat button setting
	auto settingButton = ui::Button::create("setting_normal.png","setting_pressed.png");
	settingButton->addClickEventListener([&](Ref* event)
	{
		log("Setting clicked");
	});
	settingButton->setAnchorPoint(Vec2(1, 0));
	settingButton->setPosition(Vec2(screenSize.width - 40, 0));
	settingButton->setScale(0.5f);
	addChild(settingButton);

	//Creat button exit
	auto exitButton = ui::Button::create("exit_normal.png", "exit_pressed.png");
	exitButton->addClickEventListener([&](Ref* event)
	{
		log("Exit clicked");
	});
	exitButton->setAnchorPoint(Vec2(1, 0));
	exitButton->setPosition(Vec2(screenSize.width - 80, 0));
	exitButton->setScale(0.15f);
	addChild(exitButton);


	////Creat Checkbox
	//static auto checkbox = ui::CheckBox::create("checkbox_normal.png",
	//	"checkbox_pressed.png", "checkbox_checked.png",
	//	"checkbox_normal_disable.png", "checkbox_checked_disable.png");
	//checkbox->setSelected(true);
	//checkbox->addClickEventListener([&](Ref* event) {
	//	log("CheckBox state: %d", checkbox->isSelected());
	//	CCLOG("ab");
	//});
	//checkbox->setPosition(Vec2(screenSize.width - 220, 50));
	//checkbox->setEnabled(true);
	//addChild(checkbox);
	return true;
}

