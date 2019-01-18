#include "Space.h"
#include "Bullet.h"
#include "cocos2d.h"
#include "Rock.h"
#include <vector>
#include "ui/CocosGUI.h"

using namespace cocos2d;

Space::Space(Scene *scene)
{
	mSprite = Sprite::create("spaceship.png");
	mSprite->setPosition(Director::getInstance()->getVisibleSize().width/2,mSprite->getContentSize().height);
	mSprite->setScale(0.5f);
	scene->addChild(mSprite);
	Space::CreatBullet(scene);
	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = [=](Touch *touch, Event *event)
	{
		if (mSprite->getBoundingBox().containsPoint(mSprite->getParent()->convertToNodeSpace(touch->getLocation())))
		{
			Vec2 touchLocation = touch->getLocation();
			auto actionMove = MoveTo::create(0, touchLocation);
			mSprite->runAction(actionMove);
			return true;
		}
		return false;
	};
	
	touchListener->onTouchMoved = [=](Touch *touch, Event *event)
	{
		if (mSprite->getBoundingBox().containsPoint(mSprite->getParent()->convertToNodeSpace(touch->getLocation())))
		{
			Vec2 touchLocation = touch->getLocation();
			mSprite->setPosition(touchLocation);
		}
		return false;
	};
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,mSprite);
}

Space::~Space(){}

bool Space::OnTouchBegan(Touch *touch, Event *event)
{
	return true;
}

void Space::OnTouchMoveTo(Touch *touch, Event *event)
{
	Vec2 touchLocation = touch->getLocation();
	mSprite->setPosition(touchLocation);
}

void Space::Init()
{
	mFrameCount = 0;
}

void Space::Update() 
{
	for (int i = 0; i < 50; i++)
	{
		if (!mBullets.at(i)->IsAlive()) 
		{
			mBullets.at(i)->SetPosition(GetPosition().x, GetPosition().y);
		}
		mBullets.at(i)->Update();
	}

	mFrameCount++;
	if (mFrameCount % 4 == 0)
	{
		for (int i = 0; i < 50; i++)
		{
			if (!mBullets.at(i)->IsAlive()) {
				if (!mBullets.at(i)->IsAlive()) {
					CCLOG("yyy");
					mBullets.at(i)->SetAlive(true);
				}
				break;
			}
		}
	}
}

void Space::CreatBullet(Scene * scene)
{
	for (int i = 0; i < 50; i++)
	{
		Bullet *b = new Bullet(scene);
		b->Init();
		mBullets.push_back(b);
	}
}

bool Space::Collision(Rock* rock)
{
	for (int i = 0; i < mBullets.size(); i++)
	{
		if (mBullets.at(i)->IsAlive())
		{
			auto rectRock = rock->GetRect();
			auto rectBull = mBullets.at(i)->GetRect();
			if (rectBull.intersectsRect(rectRock)) 
			{
				return true;
			}
		}
	}
	return false;
}

bool Space::CollisionSpacewithRock(Rock* rock)
{
	auto rectRock = rock->GetRect();
	auto recSpace = GetRect();
	if (recSpace.intersectsRect(rectRock))
	{
		return true;
	}
	return false;
}