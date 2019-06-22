#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class BackgroundScroller
{
private :
	Sprite* _background;
	float _speed = 0;
	float _distance = 0;
public:
	BackgroundScroller(Sprite* sprite, float speed, float distance)
		: _background(sprite),
		  _speed(speed),
		  _distance(distance)
	{
	}
	
	void startScroll();
};

