#pragma once
#include "cocos2d.h"

USING_NS_CC;

class KeyboardCode2String
{
private:
	static std::map<EventKeyboard::KeyCode, const char *> keyMap;
public:
	static const char* getName(EventKeyboard::KeyCode keyCode)
	{
		auto it = keyMap.find(keyCode);
		if (it != keyMap.end())
			return it->second;
		return "Unknown";
	}
};

std::map<EventKeyboard::KeyCode, const char*> KeyboardCode2String::keyMap = {
	{EventKeyboard::KeyCode::KEY_CAPITAL_A, "A"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_B, "B"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_C, "C"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_D, "D"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_E, "E"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_F, "F"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_G, "G"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_H, "H"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_I, "I"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_J, "J"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_K, "K"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_L, "L"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_M, "M"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_N, "N"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_O, "O"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_P, "P"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_Q, "Q"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_R, "R"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_S, "S"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_T, "T"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_U, "U"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_V, "V"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_W, "W"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_X, "X"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_Y, "Y"},
	{EventKeyboard::KeyCode::KEY_CAPITAL_Z, "Z"},

	{EventKeyboard::KeyCode::KEY_A, "a"},
	{EventKeyboard::KeyCode::KEY_B, "b"},
	{EventKeyboard::KeyCode::KEY_C, "c"},
	{EventKeyboard::KeyCode::KEY_D, "d"},
	{EventKeyboard::KeyCode::KEY_E, "e"},
	{EventKeyboard::KeyCode::KEY_F, "f"},
	{EventKeyboard::KeyCode::KEY_G, "g"},
	{EventKeyboard::KeyCode::KEY_H, "h"},
	{EventKeyboard::KeyCode::KEY_I, "i"},
	{EventKeyboard::KeyCode::KEY_J, "j"},
	{EventKeyboard::KeyCode::KEY_K, "k"},
	{EventKeyboard::KeyCode::KEY_L, "l"},
	{EventKeyboard::KeyCode::KEY_M, "m"},
	{EventKeyboard::KeyCode::KEY_N, "n"},
	{EventKeyboard::KeyCode::KEY_O, "o"},
	{EventKeyboard::KeyCode::KEY_P, "p"},
	{EventKeyboard::KeyCode::KEY_Q, "q"},
	{EventKeyboard::KeyCode::KEY_R, "r"},
	{EventKeyboard::KeyCode::KEY_S, "s"},
	{EventKeyboard::KeyCode::KEY_T, "t"},
	{EventKeyboard::KeyCode::KEY_U, "u"},
	{EventKeyboard::KeyCode::KEY_V, "v"},
	{EventKeyboard::KeyCode::KEY_W, "w"},
	{EventKeyboard::KeyCode::KEY_X, "x"},
	{EventKeyboard::KeyCode::KEY_Y, "y"},
	{EventKeyboard::KeyCode::KEY_Z, "z"},

	{EventKeyboard::KeyCode::KEY_KP_UP, "UP"},
	{EventKeyboard::KeyCode::KEY_KP_DOWN, "DOWN"},
	{EventKeyboard::KeyCode::KEY_KP_LEFT, "LEFT"},
	{EventKeyboard::KeyCode::KEY_KP_RIGHT, "RIGHT"},

	{EventKeyboard::KeyCode::KEY_DPAD_UP, "DPAD UP"},
	{EventKeyboard::KeyCode::KEY_DPAD_DOWN, "DPAD DOWN"},
	{EventKeyboard::KeyCode::KEY_DPAD_LEFT, "DPAD LEFT"},
	{EventKeyboard::KeyCode::KEY_DPAD_RIGHT, "DPAD RIGHT"},

	{EventKeyboard::KeyCode::KEY_LEFT_SHIFT, "L SHIFT"},
	{EventKeyboard::KeyCode::KEY_RIGHT_SHIFT, "R SHIFT"},
	{EventKeyboard::KeyCode::KEY_LEFT_CTRL, "L CTRL"},
	{EventKeyboard::KeyCode::KEY_RIGHT_CTRL, "R CTRL"},

};
