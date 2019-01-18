#include "Rock.h"
#include "MyObject.h"

#include "cocos2d.h"

using namespace cocos2d;

Rock::Rock(){}

Rock::Rock(cocos2d::Scene * scene) : MyObject()
{
	mSprite = Sprite::create("rock.png");
	mSprite->setScale(0.5f);
	scene->addChild(mSprite);
}

Rock::~Rock(){}

void Rock::Init()
{
	float randomRock = rand() % 461 + 20;
	mSprite->setPosition(randomRock, 750);
	mStep = 5;
	SetAlive(false);
}

void Rock::Update()
{
	if (this->IsAlive())
	{
		mSprite->setPosition(GetPosition() - Vec2(0, mStep));
		if (GetPosition().y < - mSprite->getContentSize().height)
		{
			this->SetAlive(false);
		}
	}
	else
	{
		int rand = RandomHelper::random_int(10, 490);
		this->SetPosition(rand, 750);
	}
}
