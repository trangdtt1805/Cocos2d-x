#pragma once 

#include "cocos2d.h"

class LogoScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    
	virtual bool init();
    

    CREATE_FUNC(LogoScene);
};
