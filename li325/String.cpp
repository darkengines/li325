#include "String.h"

String::String(const char* string = 0) {
	length = strlen(string);
	if (length) {
		this->string = new char[length+1];
		memcpy(this->string, string, length+1);
	}
}
String::String(const String& src) {
	length = src.length;
	if (length) {
		string = new char[length+1];
		memcpy(string, src.string, length+1);
	} else {
		string = 0;
	}
}
String::~String() {
	if (string) {
		delete[] string;
		string = 0;
	}
}
String& String::operator=(const String& src) {
	if (string) {
		delete[] string;
	}
	if (src.length) {
		length = src.length;
		string = new char[length+1];
		memcpy(string, src.string, length+1);
	} else {
		string = 0;
		length = 0;
	}
	return *this;
}
const char* String::getChars() const {
	return string;
}
int String::getLength() const {
	return length;
}
String* String::split(const char c) const {

	return 0;
}