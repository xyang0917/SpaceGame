#include "SceneAbount.h"
#include "SceneStart.h"
#include "LayerBackGround.h"

bool SceneAbout::init()
{
	Layer::init();

	LayerBackGround* bgLayer = LayerBackGround::create("Image/background1.png");
	addChild(bgLayer);

	LayerBackButton* backLayer = LayerBackButton::create([](Ref*){
		Util::replaceScene(SceneStart::create());
	});
	addChild(backLayer);

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
		label->setColor(Color3B(255,255,255));
	}

	return true;
}