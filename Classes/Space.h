#pragma once

#include "MyObject.h"
#include "define.h"
#include "Bullet.h"
#include "Rock.h"
#include <vector>
#include "cocos2d.h"

using namespace cocos2d;

class Space : public MyObject
{
private:
	std::vector<Bullet*> mBullets;
	int mFrameCount;
public:

	Space(Scene *scene);
	~Space();

	void CreatBullet(Scene * scene);

	bool OnTouchBegan(Touch *touch, Event *event);
	void OnTouchMoveTo(Touch *touch, Event *event);

	bool Collision(Rock* rock);
	bool CollisionSpacewithRock(Rock* rock);

	virtual void Init() override;
	virtual void Update() override;


};