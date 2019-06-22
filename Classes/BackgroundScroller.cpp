#include "BackgroundScroller.h"

void BackgroundScroller::startScroll()
{
	auto goUp = MoveBy::create(_speed, Vec2(0, -_distance));
	auto goDown = goUp->reverse();
	auto seq = Sequence::create(goUp, goDown, nullptr);
	_background->runAction(RepeatForever::create(seq));
}