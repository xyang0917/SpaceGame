#include "LayerBack.h"
#include "Util.h"

bool LayerBack::init()
{
	Layer::init();
	
	auto item = MenuItemImage::create("btn_back_normal.png", "btn_back_press.png");
	auto menu = Menu::create();
	menu->addChild(item);
	addChild(menu);

	auto itemSize = item->getContentSize();
	item->setPosition(ccp(winSize.width/2-itemSize.width/2, -winSize.height/2+itemSize.height/2));

	_menu = menu;
	_menuItem = item;

	return true;
}