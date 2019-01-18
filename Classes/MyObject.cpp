#include "MyObject.h"
#include "cocos2d.h"

using namespace cocos2d;

USING_NS_CC;

MyObject::MyObject(){}

MyObject::~MyObject() {}

void MyObject::SetPosition(float x,float y)
{
	mSprite->setPosition(Vec2(x,y));
}

Vec2 MyObject::GetPosition()
{
	return mSprite->getPosition();
}

MyObject::MyObject(Scene * scene){}

void MyObject::SetAlive(bool Alive)
{
	mAlive = Alive;
	mSprite->setVisible(mAlive);
}

bool MyObject::IsAlive()
{
	return mAlive;
}

Rect MyObject::GetRect()
{
	return mSprite->getBoundingBox();
}



