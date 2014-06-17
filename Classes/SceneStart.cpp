#include "SceneStart.h"
#include "SceneAbount.h"
#include "SceneGame.h"
#include "GameLevel.h"

bool SceneStart::init()
{
	LayerBackGround::init();

	// 菜单
	auto itemStart = CCMenuItemImage::create("btn1_normal.png", "btn1_push.png");
	auto itemAbout = CCMenuItemImage::create("btn2_normal.png", "btn2_push.png");
	auto itemExit = CCMenuItemImage::create("btn3_normal.png", "btn3_push.png");
	itemStart->setScale(0.5f);
	itemAbout->setScale(0.5f);
	itemExit->setScale(0.5f);
	CCMenu* menu = CCMenu::create(itemStart, itemAbout, itemExit, NULL);
	addChild(menu,3);
	menu->alignItemsVertically();

	// 加按钮的处理函数
	itemStart->setTarget(this, menu_selector(SceneStart::enter));
	itemAbout->setTarget(this, menu_selector(SceneStart::about));
	itemExit->setTarget(this, menu_selector(SceneStart::exit));

	_menu->setVisible(false);

	//陨石掉落特效
	m_pMeteorolite = CCParticleSun::create();
	m_pMeteorolite->setTexture(CCTextureCache::sharedTextureCache()->addImage("Image/Fire.png"));
	this->addChild(m_pMeteorolite, 1);
	move(0);
	this->schedule(schedule_selector(SceneStart::move), 3.0f);

	auto ptCenter = ccp(winSize.width / 2, winSize.height / 2);
	auto ptMove = ccp(200, 0);

	//星星闪烁的特效，效果不是很好啊！！！！
	auto pStar1 = Sprite::create("Image/Star.png");
	pStar1->setPosition(ccpAdd(ptCenter,ccp(-250,0)));
	this->addChild(pStar1, 1);

	ActionInterval* actionFade1 = FadeOut::create(2.5f);
	ActionInterval* actionFadeBack1 = actionFade1->reverse();
	ActionInterval* seq1 = (ActionInterval*)Sequence::create(actionFade1, actionFadeBack1, NULL);
	RepeatForever* pRepeatForever1 = RepeatForever::create(seq1);

	pStar1->runAction(pRepeatForever1);

	auto pStar2 = Sprite::create("Image/Star.png");
	pStar2->setPosition(ccpAdd(ptCenter, ccp(250, 0)));
	this->addChild(pStar2, 1);

	ActionInterval* actionFade2 = FadeOut::create(2.5f);
	ActionInterval* actionFadeBack2 = actionFade2->reverse();
	ActionInterval* seq2 = (ActionInterval*)Sequence::create(actionFade2, actionFadeBack2, NULL);
	RepeatForever* pRepeatForever2 = RepeatForever::create(seq2);

	pStar2->runAction(pRepeatForever2);

	//创建2个飞机图标
	auto pPlane1 = Sprite::create("Image/ShipIcon.png");
	pPlane1->setPosition(ccpAdd(ptCenter, ccp(-200,0)));
	this->addChild(pPlane1, 2);

	auto pPlane2 = Sprite::create("Image/ShipIcon.png");
	pPlane2->setPosition(ccpAdd(ptCenter, ccp(200, 0)));
	this->addChild(pPlane2, 2);

	return true;
}

void SceneStart::enter(CCObject*)
{
	auto scene = Util::scene(CGameLevel::create());
	Director::getInstance()->replaceScene(scene);
}

void SceneStart::about(CCObject*)
{
	auto scene = Util::scene(SceneAbout::create());
	Director::getInstance()->replaceScene(scene);
}

void SceneStart::exit(CCObject*)
{
	Director::getInstance()->end();
}

void SceneStart::move(float dt)
{
	int x = -40;
	int y = rand() % ((int)(winSize.width + winSize.height) / 2) + winSize.height / 2;
	m_pMeteorolite->setPosition(ccp(x, y));
	m_pMeteorolite->runAction(MoveBy::create(3, ccp(winSize.width + 40, -winSize.height - 40)));
}