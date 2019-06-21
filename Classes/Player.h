#pragma once
#include <string>

class Player
{
private:
	std::string name;
	int score;
public:
	std::string getName() const;
	void setName(const std::string& name);
	int getScore() const;
	void setScore(int score);

	Player(const std::string& name, int score)
		: name(name),
		  score(score)
	{
	}

	// time_t time;
	// time_t date;
	Player();
};

