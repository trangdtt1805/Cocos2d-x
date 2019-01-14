#include "ui/CocosGUI.h"
#include "TouchScene.h"


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

	
	return true;
}

