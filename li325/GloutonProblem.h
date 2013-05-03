#ifndef _GLOUTONPROBLEM_H_
#define _GLOUTONPROBLEM_H_

#include "Problem.h"

class GloutonProblem: public Problem {
public:
	GloutonProblem(const int, const String*, const int, const int);
	GloutonProblem(const GloutonProblem&);
	~GloutonProblem();
	virtual TList<Range>& Solve() const;
};

#endif