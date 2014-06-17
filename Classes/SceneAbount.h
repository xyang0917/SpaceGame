#ifndef __SCENE_ABOUT_H__
#define __SCENE_ABOUT_H__

#include "LayerBackGround.h"

class SceneAbout : public LayerBackGround
{
public:
	CREATE_FUNC(SceneAbout);

	bool init();
	void back(Object*);
};

#endif