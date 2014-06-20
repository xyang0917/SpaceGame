#ifndef __UTIL_H__
#define __UTIL_H__

#include "cocos2d.h"
USING_NS_CC;

#define winSize Director::getInstance()->getWinSize()

class Util
{
public:
	static Scene* scene(Layer* layer)
	{
		Scene* scene = Scene::create();
		scene->addChild(layer);
		return scene;
	}

	static void replaceScene(Layer* layer)
	{
		Scene* scene = Scene::create();
		scene->addChild(layer);
		Director::getInstance()->replaceScene(scene);
	}

	static int GetPlaneID(){
		return CCUserDefault::sharedUserDefault()->getIntegerForKey("PlaneID");
	}
	static void SetPlaneID(int id){
		CCUserDefault::sharedUserDefault()->setIntegerForKey("PlaneID", id);
	}
};

#endif