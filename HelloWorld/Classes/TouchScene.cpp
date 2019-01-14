#include "ui/CocosGUI.h"
#include "TouchScene.h"
#include "MenuScene.h"
#include "cocos2d.h"


USING_NS_CC;

Sprite *heart;

Scene* TouchScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TouchScene::create();
	scene->addChild(layer);
	return scene;
}


bool TouchScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();


	heart = Sprite::create("heart.png");
	heart->setPosition(Vec2(0,0));
	addChild(heart);

	//tao su kien xu ly 1 diem cham tren man hinh
	/*auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan,this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);*/


	//tao su kien
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);

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

bool TouchScene::onTouchBegan(Touch* touch, Event  *event) 
{
	Vec2 touchLocation = touch->getLocation();

	//heart->setPosition(touchLocation);
	auto actionMoveTo = MoveTo::create(2,touchLocation);
	heart->runAction(actionMoveTo);

	return true; 
} 
void TouchScene::onTouchMoved(Touch* touch, Event  *event) {
} 
void TouchScene::onTouchEnded(Touch* touch, Event  *event) { }