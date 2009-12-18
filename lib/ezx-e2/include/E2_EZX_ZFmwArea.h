//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZFmwArea 下面凡是以？开头的注释都是猜测的用途，没有经过测试

// _ZN8ZFmwAreaC4Ei
// _ZN8ZFmwAreaD4Ev

#ifndef _E2_EZX_ZFMWAREA_H
#define _E2_EZX_ZFMWAREA_H

#include <E2_EZX_ZFmwItem.h>

class ZFmwArea
{
public:
	ZFmwArea(int);
	~ZFmwArea();
	
	void append(ZFmwItem const*);
	const int at(); 
	void at(unsigned);
	void clear();
	const int count();
	const int current();
	void first();
	const int getFirst();
	const int getLast();
	void insert(unsigned, ZFmwItem const*);
	const int isEmpty();
	void last();
	void next();
	void prepend(ZFmwItem const*);
	void prev();
	void remove(ZFmwItem const*);
	void remove(unsigned);
	void setItems(char const*, ...);
	void vsetItems(char const*, void*&);
};

#endif
