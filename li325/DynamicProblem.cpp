#include "DynamicProblem.h"

DynamicProblem::DynamicProblem(int lineLength, const String* words, int wordCount, const int power): Problem(lineLength, words, wordCount, power) {
	dp = new int[wordCount+1];
	dp[wordCount] = 0;
	while (wordCount--) {
		dp[wordCount] = -1;
	}
}
DynamicProblem::DynamicProblem(const DynamicProblem& src): Problem(src) {
}
DynamicProblem::~DynamicProblem() {
	Problem::~Problem();
}
TList<Range>& DynamicProblem::Solve() const {
	TList<Range>* steps = new TList<Range>();
	int result = DP(0, *steps);
	return *steps;
}
int DynamicProblem::DP(int index, TList<Range> steps) const {
	int min = 9999999;
	int argmin;
	int tmp = 0;
	if (index >= wordCount-1) {
		return 0;
	}
	for (int i = index+1; i < wordCount; i++) {
		tmp = badness(Range(index, i))+DP(i, steps);
		if (tmp < min) {
			argmin = i;
			min = tmp;
		}
	}
	steps.AppendTail(*(new Range(index, argmin)));
	return min;
}