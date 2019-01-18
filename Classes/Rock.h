#pragma once

#include "MyObject.h"
#include "cocos2d.h"

using namespace cocos2d;

class Rock : public MyObject
{
private:
	int mStep;
public:
	Rock();
	Rock(Scene * scene);
	~Rock();

	virtual void Init() override;
	virtual	void Update() override;
};
