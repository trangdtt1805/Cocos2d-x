#pragma once
#include "cocos2d.h"

using namespace cocos2d;


class  MyObject
{
protected:
	cocos2d::Sprite *mSprite;
	bool mAlive;

public:

	MyObject();

	MyObject(Scene * scene);
	virtual ~MyObject();

	void SetPosition(float x,float y);
	Vec2 GetPosition();
	void SetAlive(bool mIsAlive);
	bool IsAlive();//set live or die
	Rect GetRect();

	virtual void Init() = 0;
	virtual void Update() = 0;

};

