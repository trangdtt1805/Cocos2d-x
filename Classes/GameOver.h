#pragma once

#include "cocos2d.h"


using namespace cocos2d;

class GameOver : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameOver);
};
