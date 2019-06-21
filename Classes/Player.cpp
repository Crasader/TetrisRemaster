#include "Player.h"

std::string Player::getName() const
{
	return name;
}

void Player::setName(const std::string& name)
{
	this->name = name;
}

int Player::getScore() const
{
	return score;
}

void Player::setScore(int score)
{
	this->score = score;
}

Player::Player()
{
	name = "";
	score = 0;
}
