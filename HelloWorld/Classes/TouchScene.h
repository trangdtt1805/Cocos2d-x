#ifndef __TOUCH_SCENE_H__
#define __TOUCH_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class TouchScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

	virtual bool init();

	//virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	bool onTouchBegan(Touch* touch,Event *event);
	//virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	//virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

    CREATE_FUNC(TouchScene);
};

#endif // __TOUCH_SCENE_H__
