#ifndef _DYNAMICPROBLEM_H_
#define _DYNAMICPROBLEM_H_

#include "Problem.h"

class DynamicProblem: public Problem {
public:
	DynamicProblem(int, const String*, int, int);
	DynamicProblem(const DynamicProblem&);
	~DynamicProblem();
	virtual TList<Range>& Solve() const;
protected:
	int* dp;
	int DP(int, TList<Range>) const;
};

#endif