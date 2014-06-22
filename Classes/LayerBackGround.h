#ifndef __LAYERBACKGROUND_H__
#define __LAYERBACKGROUND_H__

#include "Util.h"

/* 2014/6/20 12:50修改   创建静止背景层的类*/
/*可以根据不同的背景图片创建不同的背景*/

class LayerBackGround : public Layer
{
public:
	bool init(const char* bgFileName);
	static LayerBackGround* create(const char* bgFileName);

	Sprite* _bg;
};

/* 2014/6/20 13:00修改   创建返回按钮类*/
/*可以提供返回按钮的消息消息响应函数*/
class LayerBackButton : public Layer
{
public:
	static LayerBackButton* create(const ccMenuCallback& callback);
	bool init(const ccMenuCallback& callback);
	Menu* _menu;
};
#endif

