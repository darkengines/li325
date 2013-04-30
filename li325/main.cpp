#include <stdlib.h>
#include "String.h"

int main(int argc, char** argv) {
	String a;
	a.load("sample.txt");
	printf("%s\n", a.getChars());
	String* split = 0;
	int splitLength = 0;
	a.split(' ',&splitLength, &split);
	return 0;
}