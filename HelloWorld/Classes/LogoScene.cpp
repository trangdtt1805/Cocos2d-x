#include "LogoScene.h"
#include "MenuScene.h"
#include <time.h>


USING_NS_CC;

Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}

bool LogoScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();

	/*auto background = Sprite::create("splash_back.png");
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(0,0);
	
	addChild(background);*/

	auto logo = Sprite::create("mySprite.png");
	logo->setPosition(screenSize.width / 2,screenSize.height/2);

	addChild(logo);

	auto scaleBy = ScaleBy::create(1.0f,2.0f);
	auto scaleTo = ScaleTo::create(1.0f, 1.0f);
	auto moveTo = MoveTo::create(1.0f, Vec2(100, screenSize.height / 2));
	auto moveTo1 = MoveTo::create(2.0f, Vec2(400, screenSize.height / 2));
	auto moveTo2 = MoveTo::create(1.0f, Vec2(screenSize.width / 2, screenSize.height / 2));

	auto sequence = Sequence::create(scaleBy,scaleTo,moveTo,moveTo1,moveTo2,nullptr);
	auto repeat = RepeatForever::create(sequence);

	logo->runAction(repeat);
	
	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(MenuScene::createScene());
	});

	auto changeScene = Sequence::create(DelayTime::create(7), gotoNext, nullptr);
	runAction(changeScene);

	return true;
}

