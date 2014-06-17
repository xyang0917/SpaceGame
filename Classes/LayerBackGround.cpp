#include "LayerBackGround.h"
#include "Util.h"


bool LayerBackGround::init()
{
	LayerBack::init();

	// ±³¾°Í¼Æ¬
	auto* sprite = Sprite::create("Image/background.png");
	sprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	sprite->setScale(2.0f);
	addChild(sprite, EN_ORDER_BACKGROUND, EN_TAG_BACKGROUND);

	_menu->setZOrder(EN_ORDER_BACK_MENU);

	return true;
}
