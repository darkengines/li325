#ifndef _STRING_H_
#define _STRING_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

class String {
private:
	int length;
	char* string;
public:
	String();
	String(const char*);
	String(const String&);
	~String();
	void load(const char*);
	String& operator=(const String&);
	String& operator()(const int, const int) const;
	const char* getChars() const;
	int getLength() const;
	void split(const char, int*, String**) const;
};

#endif