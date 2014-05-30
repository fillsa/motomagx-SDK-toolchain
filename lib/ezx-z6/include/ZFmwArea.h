#ifndef __ZFMWAREA_H_
#define __ZFMWAREA_H_

class ZFmwItem;

/* Size: UNKNOWN */

class ZFmwArea
{
    unsigned int data[0];

public:
	ZFmwArea(int);
	~ZFmwArea();

	void append(ZFmwItem const*);
	void at() const;
	void at(unsigned int);
	void clear();
	void count() const;
	void current() const;
	void first();
	void getFirst() const;
	void getLast() const;
	void insert(unsigned int, ZFmwItem const*);
	void isEmpty() const;
	void last();
	void next();
	void prepend(ZFmwItem const*);
	void prev();
	void remove(ZFmwItem const*);
	void remove(unsigned int);
	void setItems(char const*, ...);
	void vsetItems(char const*, void*&);
};

#endif
