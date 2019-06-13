#ifndef DEFINE_H
#define DEFINE_H
#include "Blocks/Block.h"

#define CREATE_FUNC_BLOCK(__BLOCK_TYPE__) \
static __BLOCK_TYPE__* create(Block::COLOR color = Block::COLOR::GREEN) \
{ \
    __BLOCK_TYPE__ *pRet = new(std::nothrow) __BLOCK_TYPE__(color); \
    if (pRet && pRet->init()) \
    { \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = nullptr; \
        return nullptr; \
    } \
}

namespace TetrisGame {
	const int BLOCK_SIZE = 48;

	const int MAX_COL = 12;
	const int MAX_ROW = 16;

	const int PADDING_LEFT = BLOCK_SIZE;
}

#endif // !DEFINE_H
