//#include "ui/CocosGUI.h"
#include "TouchScene.h"
#include "MenuScene.h"


USING_NS_CC;

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
	



	////tao su kien xu ly 1 diem cham tren man hinh
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan,this);
	////this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	return true;
}


bool TouchScene::onTouchBegan(Touch *touch, Event *event)
{
	Vec2 touchLocation = touch->getLocation();//toa do cham tren man hinh

	auto heart = Sprite::create("heart.png");
	heart->setPosition(touchLocation);

	addChild(heart);

	return true;
}