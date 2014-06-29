#include "tools.h"

float heronsformula(float x1,float y1,float x2,float y2,float x3,float y3)
{
	float a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	float b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	float c=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
	float s=(a+b+c)/2;

	return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool triangleContainPoint(float x1,float y1,float x2,float y2,float x3,float y3,float px,float py)
{
	float s1=heronsformula(x1,y1,x2,y2,px,py);
	float s2=heronsformula(x2,y2,x3,y3,px,py);
	float s3=heronsformula(x3,y3,x1,y1,px,py);
	float s=heronsformula(x1,y1,x2,y2,x3,y3);

	return abs(s-(s1+s2+s3))<0.001f;
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//�ַ�ת����ʹcocos2d-x��win32ƽ̨֧��������ʾ
int GBKToUTF8(std::string &gbkStr,const char* toCode,const char* formCode)
{
	iconv_t iconvH;
	iconvH = iconv_open(formCode,toCode);
	if(iconvH == 0)
	{
		return -1;
	}

	const char* strChar = gbkStr.c_str();
	const char** pin = &strChar;

	size_t strLength = gbkStr.length();
	char* outbuf = (char*)malloc(strLength*4);
	char* pBuff = outbuf;
	memset(outbuf,0,strLength*4);
	size_t outLength = strLength*4;
	if(-1 == iconv(iconvH,pin,&strLength,&outbuf,&outLength))
	{
		iconv_close(iconvH);
		return -1;
	}

	gbkStr = pBuff;
	iconv_close(iconvH);
	return 0;
}
#endif