#include "MyObject.h"
#include "Bullet.h"
#include "define.h"
#include "cocos2d.h"

using namespace std;

Bullet::Bullet() {}

Bullet::Bullet(cocos2d::Scene * scene) : MyObject()
{
	mSprite = Sprite::create("bullet.png");
	scene->addChild(mSprite);
}

Bullet::~Bullet() {}

void Bullet::Init()
{
	mStep = 5;
	SetAlive(false);
}

void Bullet::Update()
{
	if (this->IsAlive())
	{
		mSprite->setPosition(GetPosition() + Vec2(0, mStep));
		if (GetPosition().y > SCREEN_H + mSprite->getContentSize().height)
		{
			this->SetAlive(false);
		}
	}
}