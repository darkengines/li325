#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "String.h"
#include "Range.h"
#include "TList.h"
#include <stdio.h>

class Printer {
public:
	static void print(FILE*, int, String*, TList<Range>, int);
	static int getRangeScore(int, String*, Range, int power);
};

#endif