#include "SceneAbount.h"
#include "SceneStart.h"

bool SceneAbout::init()
{
	LayerBackGround::init();

	auto dict = Dictionary::createWithContentsOfFile("about.xml");

	const char* format = "people%d";
	char key[64];
	const int fontSize = 48;
	for (int i = 0; i < dict->allKeys()->count(); i++)
	{
		sprintf(key, format, i + 1);
		const String* obj = dict->valueForKey(key);
		auto label = LabelTTF::create(obj->_string.c_str(), "Arial", fontSize);
		addChild(label);
		label->setPosition(ccp(50, winSize.height - (i+1)*fontSize));
		label->setAnchorPoint(ccp(0, .5));
		label->setColor(ccRED);
	}

	this->_menuItem->setTarget(this, menu_selector(SceneAbout::back));

	return true;
}

void SceneAbout::back(Object*)
{
	SceneStart* layer = SceneStart::create();
	auto scene = Util::scene(layer);
	Director::getInstance()->replaceScene(scene);
}