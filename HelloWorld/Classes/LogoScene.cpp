#include "LogoScene.h"
#include "MenuScene.h"
#include "ui/CocosGUI.h"
#include <time.h>


USING_NS_CC;

Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}

bool LogoScene::init()
{
	/*if (!Layer::init())
	{
		return false;
	}*/

	auto screenSize = Director::getInstance()->getVisibleSize();

	if (!LayerColor::initWithColor(Color4B(255, 0, 34, 255))) {
		return false;
	}

	//Label
	auto playGame = Label::createWithSystemFont("HELLO WORLD", "Marker Felt", 28);
	playGame->setPosition(screenSize.width / 2, screenSize.height / 2 + 100);

	addChild(playGame);

	auto scaleBig = ScaleTo::create(1.0f, 2.0f);
	auto scaleSmall = ScaleTo::create(1.0f, 1.0f);
	auto sequenceLaybel = Sequence::create(scaleBig, scaleSmall, nullptr);
	auto repeatLaybel = RepeatForever::create(sequenceLaybel);
	playGame->runAction(repeatLaybel);

	auto logo = Sprite::create("mySprite.png");
	logo->setPosition(screenSize.width / 2,screenSize.height/2);

	addChild(logo);

	auto moveTo = MoveTo::create(1.0f, Vec2(100, screenSize.height / 2));
	auto moveTo1 = MoveTo::create(2.0f, Vec2(400, screenSize.height / 2));
	auto moveTo2 = MoveTo::create(1.0f, Vec2(screenSize.width / 2, screenSize.height / 2));

	auto sequence = Sequence::create(moveTo,moveTo1,moveTo2,nullptr);
	auto repeat = RepeatForever::create(sequence);

	logo->runAction(repeat);

	//loading bar
	auto loadingBarGB = Sprite::create("loadingbar_bg.png");
	loadingBarGB->setPosition(screenSize.width/2,50);
	
	addChild(loadingBarGB);

	static auto loadingbar = ui::LoadingBar::create("loadingbar_bg.png");
	loadingbar->setPercent(0);
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingbar->setPosition(loadingBarGB->getPosition());

	addChild(loadingbar);

	//update Loading Bar
	auto updateLoadingBar = CallFunc::create([]() {
		if (loadingbar->getPercent() < 100)
		{
			loadingbar->setPercent(loadingbar->getPercent() + 1);
		}
	});

	auto sequenceRunUpdateLoadingBar = Sequence::createWithTwoActions(updateLoadingBar,DelayTime::create(0.1f));
	auto repeatLoadingBar = Repeat::create(sequenceRunUpdateLoadingBar,100);
	loadingBarGB->runAction(repeatLoadingBar);
	
	
	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(MenuScene::createScene());
	});

	auto changeScene = Sequence::create(DelayTime::create(7), gotoNext, nullptr);
	runAction(changeScene);

	return true;
}

