#ifndef _GAMELEVEL_H_
#define _GAMELEVEL_H_

#include "LayerBack.h"
//#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include "Util.h"

enum{
	LEVEL_ONE = 1, 
	LEVEL_TWO,  
	LEVEL_THREE,    
};

class CGameLevel : public LayerBack
{
public:
    virtual bool init();  
	CREATE_FUNC(CGameLevel);

private:
	/**	选择关卡的回调函数	*/
	void setLevelMode(Object* pSender);

	/**	开始按钮的回调函数	*/
	void setLevelStart(Object* pSender);

	/**	返回按钮的回调函数	*/
	void back(Object* pSender);

	ParticleSun* m_pSun;		//太阳特效

	int g_iGameLevel = 1;
	Size size = winSize;
	Sprite* _pSprite;   //背景精灵
};

#endif
