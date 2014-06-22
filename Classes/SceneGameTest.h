#ifndef _SCENEGAMETEST_H_
#define _SCENEGAMETEST_H_

#include "Util.h"

class SceneGameTest : public Layer
{
public:
	bool init();
	CREATE_FUNC(SceneGameTest);

	Sprite* _light;
	void removefromparent(Node* node);
};

#endif

