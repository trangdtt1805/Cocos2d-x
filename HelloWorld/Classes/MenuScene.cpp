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
	itemSetting->setPosition(screenSize.width / 2, 150);
	itemMoreGame->setPosition(screenSize.width / 2, 100);
	itemAbout->setPosition(screenSize.width / 2, 50);
	
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
	addChild(ratingButton);


	return true;
}

