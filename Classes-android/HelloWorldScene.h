#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ParallaxNodeExtras.h"

USING_NS_CC;

typedef enum {
	KENDREASONWIN,
	KENDREASONLOSE
} EndReason;

class HelloWorld : public cocos2d::Layer
{
public:

	SpriteBatchNode *_batchNode;
	Sprite *_ship;

	ParallaxNodeExtras *_backgroundNode;
	Sprite *_spacedust1;
	Sprite *_spacedust2;
	Sprite *_planetsunrise;
	Sprite *_galaxy;
	Sprite *_spacialanomaly;
	Sprite *_spacialanomaly2;

	float _shipPointsPerSecY;

	Vector<Sprite*> _asteroids;
	Vector<Sprite*> _bloods;
	Vector<SpriteFrame *> _animFrames;

	int _nextAsteroid;
	float _nextAsteroidSpawn;

	Vector<Sprite*> _shipLasers;
	int _nextShipLaser;

	int _lives;

	double _gameOverTime;
	bool _gameOver;


    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(); 

	virtual void update(float dt);

	virtual void onAcceleration(Acceleration* acc, Event* unused_event);

	virtual void onEnter();
	bool onTouchBegan(Touch *touch, Event *event);

	float randomValueBetween(float low, float high);
	void  setInvisible(Node * node);
	float getTimeTick();

	void endScene(EndReason endReason);
	void restartTapped(Object* sender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool isHaveSaveFile();
	int getHighestHistorySorce();
	void setHighestHistorySorce();
};
#endif // __HELLOWORLD_SCENE_H__
