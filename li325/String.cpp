#include "String.h"

String::String() {
	string = 0;
	length = 0;
}

String::String(const char* string) {
	if (string) {
		length = strlen(string);
		if (length) {
			this->string = new char[length+1];
			memcpy(this->string, string, length+1);
		}
	} else {
		length = 0;
		this->string = 0;
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
String& String::operator()(const int start, const int end) const {
	int l = end-start+2;
	char* str = new char[l];
	str[l-1] = '\0';
	memcpy(str, string+start, l-1);
	return *(new String(str));
}
const char* String::getChars() const {
	return string;
}
int String::getLength() const {
	return length;
}
void String::split(const char c, int* itemCount, String** items) const {
	if (length) {
		*itemCount = 0;
		int i = length;
		while (i>0) {
			while (i-- && string[i] == c);
			int end = i;
			while (i-- && string[i] != c);
			(*itemCount)++;
		}
		i = length;
		int j = *itemCount;
		*items = new String[*itemCount];
		while (i>0) {
			while (i-- && string[i] == c);
			int end = i;
			while (i-- && string[i] != c);
			int start = i+1;
			(*items)[--j] = (*this)(start, end);
		}
	} else {
		*itemCount = 0;
		items = 0;
	}
}
void String::load(const char* src) {
	if (string) {
		delete[] string;
		string = 0;
	}
	char c;
	FILE* file = fopen(src, "r");
	if (file) {
		int count = 1;
		while ((c = fgetc(file)) != EOF && c != '\n') {
			count++;
		}
		if (count > 1) {
			length = count-1;
			fseek(file, 0, SEEK_SET);

			string = new char[count];
			string[count-1] = '\0';
			int count = 0;
			while ((c=fgetc(file)) != EOF && c != '\n') {
				string[count] = c;
				count++;
			}
		} else {
			length = 0;
		}
	}
}
