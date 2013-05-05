/////////////////////////////////////////////
//	A class simulating the printer
/////////////////////////////////////////////

#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "String.h"
#include "Range.h"
#include "TList.h"
#include <stdio.h>

class Printer {
public:
	//prints the given words in the given file using the given instructions
	static void print(FILE*, int, String*, TList<Range>, int);
	//computes the given range line badness with the given power
	static int getBadness(int, String*, Range, int power);
};

#endif
