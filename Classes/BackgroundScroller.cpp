#include "BackgroundScroller.h"

void BackgroundScroller::startScroll()
{
	_scene->schedule([
		_maxY = _maxY,
		_minY = _minY,
		_speed = _speed,
		_background = _background](float delta)
	{
		static auto direction = 1;
	
		auto position = _background->getPosition();
		
		if (position.y >= _maxY || position.y <= _minY)
			direction *= -1;
		
		position.y += (direction * _speed * delta);
		
		_background->setPosition(position);
	}, "BG_Scroller");
}