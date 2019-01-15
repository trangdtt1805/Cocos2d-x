#include "ui/CocosGUI.h"
#include "SettingScene.h"
#include "MenuScene.h"
#include "cocos2d.h"


USING_NS_CC;

Sprite *heart;

Scene* SettingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingScene::create();
	scene->addChild(layer);
	return scene;
}


bool SettingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();


	heart = Sprite::create("heart.png");
	heart->setPosition(Vec2(0, 0));
	addChild(heart);

	//tao su kien
	auto listener = EventListenerTouchOneByOne::create(); 
	listener->onTouchBegan = CC_CALLBACK_2(SettingScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SettingScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SettingScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

////function onTouchBegan
//bool TouchScene::onTouchBegan(Touch *touch, Event *event)
//{
//	Vec2 touchLocation = touch->getLocation();//toa do cham tren man hinh
//
//	auto heart = Sprite::create("heart.png");
//	heart->setPosition(touchLocation);
//	addChild(heart); 
//
//	return true;
//}

bool SettingScene::onTouchBegan(Touch* touch, Event  *event)
{
	Vec2 touchLocation = touch->getLocation();

	//heart->setPosition(touchLocation);
	auto actionMoveTo = MoveTo::create(2, touchLocation);
	heart->runAction(actionMoveTo);

	return true;
}
void SettingScene::onTouchMoved(Touch* touch, Event  *event) {
	Vec2 touchLocation = touch->getLocation();

	heart->setPosition(touchLocation);
}
void SettingScene::onTouchEnded(Touch* touch, Event  *event) { 
	heart->setPosition(Vec2(0,0));
}