#ifndef __LOGO_SCENE_H__
#define __LOGO_SCENE_H__

#include "cocos2d.h"

class TouchScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    
	virtual bool init();
    

    CREATE_FUNC(TouchScene);
};

#endif // __LOGO_SCENE_H__
