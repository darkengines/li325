#ifndef _GLOUTONPROBLEM_H_
#define _GLOUTONPROBLEM_H_

#include "Problem.h"

class GloutonProblem: public Problem {
public:
	GloutonProblem(int, const String*, int, int);
	GloutonProblem(const GloutonProblem&);
	~GloutonProblem();
	virtual TList<Range>& Solve() const;
};

#endif