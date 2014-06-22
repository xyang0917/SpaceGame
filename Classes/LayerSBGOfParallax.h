#ifndef __LSBGPARALLAX_H__
#define __LSBGPARALLAX_H__

#include "Util.h"
#include "LayerBackGround.h"
#include "ParallaxNodeExtras.h"

class LayerSBGOfParallax : public Layer
{
public:
	CREATE_FUNC(LayerSBGOfParallax);
	enum{ EN_ORDER_BACKGROUND, EN_ORDER_BACK_MENU };
	enum{ EN_TAG_BACKGROUND };
	bool init();

	//子类要继承这个背景层，而且子类里面也需要
	//shceduleUpdate();   void update(float dt);
	//在父类中实现后，在子类中实现会当机！所以只能这样了，
	//在子类中来调用父类的这个函数。
	void updateCallByChild(float dt);

	ParallaxNodeExtras *_backgroundNode;
	Sprite *_spacedust1;
	Sprite *_spacedust2;
	Sprite *_planetsunrise;
	Sprite *_galaxy;
	Sprite *_spacialanomaly;
	Sprite *_spacialanomaly2;
};
#endif

