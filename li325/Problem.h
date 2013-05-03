#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "String.h"
#include "Range.h"
#include "TList.h"

class Problem {
protected:
	const int lineLength;
	const String* words;
	const int power;
	const int wordCount;
	int badness(const Range&) const;
public:
	Problem(int, const String*, int,  int);
	Problem(const Problem&);
	~Problem();
	virtual TList<Range>& Solve() const = 0;
};

#endif