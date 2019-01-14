#ifndef __TOUCH_SCENE_H__
#define __TOUCH_SCENE_H__

#include "cocos2d.h"

class ParticleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

	virtual bool init();

    CREATE_FUNC(ParticleScene);
};

#endif // __TOUCH_SCENE_H__
