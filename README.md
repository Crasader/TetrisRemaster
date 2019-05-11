# INSTALL DEPENDENCIES
- Install cocos2d-x.
> $ `git submodule update --init`
- After download cocos2d-x, install cocos2d-x's dependencies
> $ `cd cocos2d`

> cocos2d $ `python download-deps.py`
- Finally:
> cocos2d $ `git submodule update --init`
# HOW TO BUILD
Note: Run this command first time only, then you can build directly in VS project.
> $ `cocos compile -p win32`