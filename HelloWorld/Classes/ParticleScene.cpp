#include "ui/CocosGUI.h"
#include "ParticleScene.h"
#include "TouchScene.h"
#include "cocos2d.h"

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


	cocos2d::ParticleSystemQuad *m_emitter;
	m_emitter = ParticleSystemQuad::create("particles/particle_texture.plist");
	m_emitter->setVisible(true);
	this->addChild(m_emitter, 50);
	m_emitter->setPosition(screenSize.width/2,screenSize.height/2);
	m_emitter->runAction(Sequence::create(DelayTime::create(50.0), RemoveSelf::create(), NULL));


	return true;
}

