#ifndef __SCENE_GAME_H__
#define __SCENE_GAME_H__

#include "LayerSBGOfParallax.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#define KNUMASTEROIDS 15  //创建星球的数量
#define KNUMLASERS 5      //创建激光的数量

class SceneGame : public LayerSBGOfParallax
{
public:
	CREATE_FUNC(SceneGame);
	virtual bool init();
	void back(Object*);
	virtual void update(float dt);
	virtual bool onTouchBegan(Touch *touch, Event *event);
	virtual void onAcceleration(Acceleration* acc, Event* unused_event);  //重力感应

	enum {EN_BACKGROUND_ZORDER=-1,EN_HERO_ZORDER=10};

	Sprite* _ship;
	Vector<Sprite*> _asteroids;   //储存创建的星球
	int _nextAsteroid;
	float _nextAsteroidSpawn;     //指示下一个陨石出现的时间点。我们会在update循环中一直检测这个变量的值。
	Vector<Sprite*> _shipLasers;  //储存创建的激光
	int _nextShipLaser;

	float _shipPointsPerSecY;

	void createHero();			//创建英雄
	void createGrainStar();     //使用粒子系统创建星星
	void InitAsteroid();		//初始化星球
	void InitShipLasers();		//初始化激光
	void initAudio();			//加载游戏中需要用到的音乐

	float getTimeTick();
	void setInvisible(Node * node);
	float randomValueBetween(float low, float high);
};

#endif