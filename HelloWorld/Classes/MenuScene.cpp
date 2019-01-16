#include "MenuScene.h"
#include "LogoScene.h"
#include "ui/CocosGUI.h"
#include "PlayScene.h"
#include "cocos2d.h"
#include "SettingScene.h"
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
	if (!LayerColor::initWithColor(Color4B(242, 2172, 19, 50)))
	{
		return false;
	}
	
	auto screenSize = Director::getInstance()->getVisibleSize();


	//Label
	auto playGame = Label::createWithTTF("Hello World!", "fonts/Marker Felt.ttf", 30);
	playGame->setPosition(screenSize.width / 2, screenSize.height / 2 + 100);

	addChild(playGame);

	auto scaleBig = ScaleTo::create(1.0f, 1.2f);
	auto scaleSmall = ScaleTo::create(1.0f, 1.0f);
	auto sequenceLaybel = Sequence::create(scaleBig, scaleSmall, nullptr);
	auto repeatLaybel = RepeatForever::create(sequenceLaybel);
	playGame->runAction(repeatLaybel);

	//Play
	auto itemPlay = MenuItemFont::create("Play", [&](Ref* play) 
	{   
		auto gotoNext = CallFunc::create([]() {
			Director::getInstance()->replaceScene(PlayScene::createScene());
		});
		runAction(Sequence::create(DelayTime::create(0), gotoNext, nullptr));
	}); 

	
	auto itemSetting = MenuItemFont::create("Setting", [&](Ref* setting)
	{
		auto gotoNext = CallFunc::create([]() {
			Director::getInstance()->replaceScene(SettingScene::createScene());
		});
		runAction(Sequence::create(DelayTime::create(0), gotoNext, nullptr));
	});

	auto itemMoreGame = MenuItemFont::create("More Game", nullptr); 
	auto itemAbout = MenuItemFont::create("About", nullptr);    
	
	//set color to Menu
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


	////Creat button setting
	//auto settingButton = ui::Button::create("setting_normal.png","setting_pressed.png");
	//settingButton->addClickEventListener([&](Ref* event)
	//{
	//	log("Setting clicked");
	//});
	//settingButton->setAnchorPoint(Vec2(1, 0));
	//settingButton->setPosition(Vec2(screenSize.width - 40, 0));
	//settingButton->setScale(0.5f);
	//addChild(settingButton);


	////Creat button exit
	//auto exitButton = ui::Button::create("exit_normal.png", "exit_pressed.png");
	//exitButton->addClickEventListener([&](Ref* event)
	//{
	//	log("Exit clicked");
	//});
	//exitButton->setAnchorPoint(Vec2(1, 0));
	//exitButton->setPosition(Vec2(screenSize.width - 80, 0));
	//exitButton->setScale(0.15f);
	//addChild(exitButton);
	
	cocos2d::ParticleSystemQuad *m_emitter;
	m_emitter = ParticleSystemQuad::create("particle/particle_texture.plist");
	m_emitter->setVisible(true);
	this->addChild(m_emitter, 50);
	m_emitter->setPosition(screenSize.width / 2, screenSize.height / 2);
	m_emitter->runAction(Sequence::create(DelayTime::create(50.0), RemoveSelf::create(), NULL));

	return true;
}
