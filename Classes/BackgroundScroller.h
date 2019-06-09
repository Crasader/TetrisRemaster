#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class BackgroundScroller
{
private :
	Scene* _scene;
	Sprite* _background;
	float _speed;
	float _maxY;
	float _minY;

public:

	BackgroundScroller(Scene* scene, 
		Sprite* sprite, 
		float speed, 
		float max_y,
		float min_y)
		: _speed(speed),
		  _maxY(max_y),
		  _minY(min_y)
	{
		this->_scene = scene;
		this->_background = sprite;
	}

	void startScroll();

	void TickMe(float delta);
};

