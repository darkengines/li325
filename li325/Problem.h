/////////////////////////////////////////////
//	The problem base class    
/////////////////////////////////////////////

#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "String.h"
#include "Range.h"
#include "TList.h"

class Problem {
protected:
	//the lines capacity
	const int lineLength;
	const String* words;
	//used in line badness computation
	const int power;
	const int wordCount;
	//given a word range, returns the line badness
	int badness(const Range&) const;
public:
	Problem(int, const String*, int,  int);
	Problem(const Problem&);
	
	//solves the problem, returns an instruction list for the printer
	virtual TList<Range>& Solve() const = 0;
};

#endif
