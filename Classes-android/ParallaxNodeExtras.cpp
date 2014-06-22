#include "ParallaxNodeExtras.h"

// Hack to access CCPointObject (which is not a public class)

class PointObject : Object
{
public:
	static PointObject * create(Point ratio, Point offset)
	{
		PointObject *ret = new PointObject();
		ret->initWithPoint(ratio, offset);
		ret->autorelease();
		return ret;
	}

	bool initWithPoint(Point ratio, Point offset)
	{
		_ratio = ratio;
		_offset = offset;
		_child = nullptr;
		return true;
	}

	inline const Point& getRatio() const { return _ratio; };
	inline void setRatio(const Point& ratio) { _ratio = ratio; };

	inline const Point& getOffset() const { return _offset; };
	inline void setOffset(const Point& offset) { _offset = offset; };

	inline Node* getChild() const { return _child; };
	inline void setChild(Node* child) { _child = child; };

private:
	Point _ratio;
	Point _offset;
	Node *_child; // weak ref
};

// Need to provide our own constructor
ParallaxNodeExtras::ParallaxNodeExtras() {
	ParallaxNode::create(); // call parent constructor
}

ParallaxNodeExtras* ParallaxNodeExtras::node() {
	return new ParallaxNodeExtras();
}

void ParallaxNodeExtras::incrementOffset(CCPoint offset, CCNode* node)
{
	for (unsigned int i = 0; i < _parallaxArray->num; i++)
	{
		PointObject *point = (PointObject*)_parallaxArray->arr[i];
		Node* curNode = point->getChild();
		//if (curNode->isEqual(node)) 
		if (curNode == node)
		{
			point->setOffset(point->getOffset()+offset);
			break;
		}
	}
}