#ifndef __LAYERBACK_H__
#define __LAYERBACK_H__

#include "Util.h"

/* 具有返回按钮的层，但是这个返回按钮没有处理函数 */
class LayerBack : public Layer
{
public:
	bool init();
	CREATE_FUNC(LayerBack)

	Menu* _menu;
	MenuItem* _menuItem;
};

#endif