#ifndef __LAYERBACKGROUND_H__
#define __LAYERBACKGROUND_H__

#include "LayerBack.h"

/* 提供静止背景和返回按钮的层 */
class LayerBackGround : public LayerBack
{
public:
	enum{ EN_ORDER_BACKGROUND , EN_ORDER_BACK_MENU};
	enum{ EN_TAG_BACKGROUND };

	bool init();
	CREATE_FUNC(LayerBackGround)
};

#endif

