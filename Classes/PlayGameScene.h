#pragma once
#include "cocos2d.h"
#include "Space.h"
#include "Rock.h"
#include <vector>

//using namespace cocos2dx;

class PlayGameScene : public cocos2d::Scene
{
private:
		std::vector<Rock*> mRocks;
		Space * mSpace;
		int mFrameCount;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void update(float penta);
	void CreatRock(Scene * scene);

    CREATE_FUNC(PlayGameScene);
};
