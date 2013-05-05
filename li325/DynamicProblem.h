/////////////////////////////////////////////
//	The problem DP version
//  inspired from http://www.youtube.com/watch?v=ENyox7kNKeY
//  MIT 6.006 Introduction to Algorithms, Fall 2011
//  Erik Demaine
/////////////////////////////////////////////

#ifndef _DYNAMICPROBLEM_H_
#define _DYNAMICPROBLEM_H_

#include "Problem.h"

class DynamicProblem: public Problem {
public:
	DynamicProblem(int, const String*, int, int);
	DynamicProblem(const DynamicProblem&);
	~DynamicProblem();
	//computes DP(0)
	virtual TList<Range>& Solve() const;
protected:
	//the optimal structure
	//dp[wordCount] = 0
	//dp[i] = min(badness(i, j) + dp[j+1]) with j in [i+1;wordCount]
	//the range [i+1;wordCount] is reduced to the maximum word count that can be printed on the line
	int* dp;
	//the recusive function filling the optimal structure dp
	//first argument: the word index
	//second argument: the parent pointer, containing the word indices
	int DP(int, int*) const;
};

#endif
