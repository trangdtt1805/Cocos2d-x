#include "PlayGameScene.h"
#include "Rock.h"
#include "Space.h"
#include "GameOver.h"
#include "SimpleAudioEngine.h"
#include "Cocos2d.h"

using namespace cocos2d;

USING_NS_CC;

Scene* PlayGameScene::createScene()
{
    return PlayGameScene::create();
}

bool PlayGameScene::init()
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
	
	 mSpace = new Space(this);
	 mSpace->Init();
	 
	 CreatRock(this);
	this->scheduleUpdate();

	mFrameCount = 0;
	return true;
}

void PlayGameScene::update(float)
{
	mSpace->Update();
	for (int i = 0; i < 50; i++)
	{
		mRocks.at(i)->Update();
	}
	mFrameCount++;
	if (mFrameCount % 4 == 0)
	{
		for (int i = 0; i < 50; i++)
		{
			if (!mRocks.at(i)->IsAlive()) {
				if (!mRocks.at(i)->IsAlive()) {
					mRocks.at(i)->SetAlive(true);
				}
				break;
			}
		}
	}
	for (int i = 0; i < mRocks.size(); i++)
	{
		if (mRocks.at(i)->IsAlive())
		{
			if (mSpace->Collision(mRocks.at(i)))
			{
				mRocks.at(i)->SetAlive(false);
			}
			if (mSpace->CollisionSpacewithRock(mRocks.at(i)))
			{
				mRocks.at(i)->SetAlive(false);
				CCLOG("Die");
				//Director::getInstance()->replaceScene(GameOver::createScene());

			}
		}
	}
}

void PlayGameScene::CreatRock(Scene * scene)
{
	for (int i = 0; i < 50; i++)
	{
		Rock *r = new Rock(scene);
		r->Init();
		mRocks.push_back(r);
	}
}
