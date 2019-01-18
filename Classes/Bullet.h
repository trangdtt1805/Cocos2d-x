#pragma once

#include "MyObject.h"
#include "cocos2d.h"

using namespace cocos2d;

class Bullet : public MyObject
{
private:
	int mStep;
public:
	Bullet();
	Bullet(Scene * scene);
	~Bullet();

	virtual void Init() override;
	virtual	void Update() override;

};
