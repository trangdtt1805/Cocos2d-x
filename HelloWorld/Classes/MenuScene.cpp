#include "MenuScene.h"
#include "LogoScene.h"


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
	auto playGame = Label::createWithSystemFont("Play Game","Arial",16);
	playGame->setPosition(screenSize.width/2,screenSize.height/2 + 100);
	
	addChild(playGame);

	auto scaleBig = ScaleTo::create(1.0f,2.0f);
	auto scaleSmall = ScaleTo::create(1.0f, 1.0f);
	auto sequence = Sequence::create(scaleBig,scaleSmall,nullptr);
	auto repeat = RepeatForever::create(sequence);
	playGame->runAction(repeat);

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






	return true;
}

