#include "ui/CocosGUI.h"
#include "TouchScene.h"
#include <iostream>

using namespace std;


USING_NS_CC;

Scene* TouchScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TouchScene::create();
	scene->addChild(layer);
	return scene;
}


bool TouchScene::onTouchBegan(Touch* touch, Event *event) {
	return true;
}
void TouchScene::onTouchMoved(Touch* touch, Event* event) {}

void TouchScene::onTouchEnded(Touch* touch, Event* event) {}



bool TouchScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();

	
	auto heart = Sprite::create("heart.png");
	heart->setPosition(screenSize.width,screenSize.height);
	addChild(heart);

	/*auto listener = EventListenerTouchOneByone::create();
	listener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan, this); 
	listener->onTouchMoved = CC_CALLBACK_2(TouchScene::onTouchMoved, this); 
	listener->onTouchEnded = CC_CALLBACK_2(TouchScene::onTouchEnded, this); 
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
*/
	return true;
}

