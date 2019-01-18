#include "GameOver.h"
#include "SimpleAudioEngine.h"
#include "PlayGameScene.h"
#include "Cocos2d.h"

using namespace cocos2d;

USING_NS_CC;

Scene* GameOver::createScene()
{
    return GameOver::create();
}

bool GameOver::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();

	//background
	auto background = Sprite::create("background.png");
	background->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(background);

	//label
	auto myLabel = Label::createWithTTF("Game Over", "Marker Felt.ttf", 24);
	myLabel->setPosition(screenSize.width/2,screenSize.height/2);


	return true;
}