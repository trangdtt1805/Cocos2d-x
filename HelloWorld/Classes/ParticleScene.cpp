#include "ui/CocosGUI.h"
#include "ParticleScene.h"

USING_NS_CC;

Scene* ParticleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ParticleScene::create();
	scene->addChild(layer);
	return scene;
}


bool ParticleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();

	

	return true;
}

