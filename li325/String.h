#ifndef _STRING_H_
#define _STRING_H_

#include <stdlib.h>
#include <string.h>

class String {
private:
	int length;
	char* string;
public:
	String(const char*);
	String(const String&);
	~String();
	String& operator=(const String&);
	const char* getChars() const;
	int getLength() const;
	String* split(const char) const;
};

#endif