#ifndef __LayerScrollBackGround_H__
#define __LayerScrollBackGround_H__

#include "Util.h"

class LayerScrollBackGround : public Layer
{
public:
	CREATE_FUNC(LayerScrollBackGround);
	enum{ EN_ORDER_BACKGROUND, EN_ORDER_BACK_MENU };
	enum{ EN_TAG_BACKGROUND };
	bool init();
};
#endif

