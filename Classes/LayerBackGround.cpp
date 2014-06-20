#include "LayerBackGround.h"

LayerBackGround* LayerBackGround::create(const char* bgFileName)
{
	LayerBackGround *pRet = new LayerBackGround(); 
	if (pRet && pRet->init(bgFileName))
	{ 
		pRet->autorelease();
		return pRet;
	} 
	else 
	{ 
		delete pRet;
		pRet = NULL;
		return NULL;
	} 
}

bool LayerBackGround::init(const char* bgFileName)
{
	Layer::init();

	// ±³¾°Í¼Æ¬
	auto* sprite = Sprite::create(bgFileName);
	sprite->setPosition(ccp(winSize.width / 2, winSize.height / 2)); 
	addChild(sprite);

	_bg = sprite;

	return true;
}

LayerBackButton* LayerBackButton::create(const ccMenuCallback& callback)
{
	LayerBackButton *pRet = new LayerBackButton();
	if (pRet && pRet->init(callback))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool LayerBackButton::init(const ccMenuCallback& callback)
{
	Layer::init();

	Menu* menu = Menu::create();
	addChild(menu);
	_menu = menu;

	MenuItemImage* item = MenuItemImage::create("btn_back_normal.png", "btn_back_press.png", callback);
	menu->addChild(item);

	item->setAnchorPoint(ccp(1, 0));
	item->setPosition(winSize.width / 2, -winSize.height / 2);

	return true;
}