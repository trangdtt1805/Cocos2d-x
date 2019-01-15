#pragma once 
#include "cocos2d.h"


class SettingScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event  *event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event  *event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event  *event);


	CREATE_FUNC(SettingScene);
};

