#ifndef _TOOLS_H_
#define  _TOOLS_H_

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "iconv.h"
#endif

float heronsformula(float x1,float y1,float x2,float y2,float x3,float y3);

bool triangleContainPoint(float x1,float y1,float x2,float y2,float x3,float y3,float px,float py);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//�ַ�ת����ʹcocos2d-x��win32ƽ̨֧��������ʾ
int GBKToUTF8(std::string &gbkStr,const char* toCode,const char* formCode);
#endif

#endif //_TOOLS_H_