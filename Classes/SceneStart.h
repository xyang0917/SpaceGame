#ifndef __SCENE_START_H__
#define __SCENE_START_H__

#include "LayerBackGround.h"

/*
	开场场景：需要具备背景，所以从LayerBackGround派生
*/
class SceneStart : public LayerBackGround
{
public:
	CREATE_FUNC(SceneStart);
	bool init();

	void enter(Object*);
	void exit(Object*);
	void about(Object*);	

	CCParticleSun* m_pMeteorolite;	//陨石特效
	void move(float dt);
};


#endif