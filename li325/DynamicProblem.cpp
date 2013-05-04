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
	int* parents = new int[wordCount];
	TList<Range>* steps = new TList<Range>();
	int result = DP(0, parents);
	int i = 0;
	while (i < wordCount-1) {
		steps->AppendTail(*(new Range(i, parents[i]-1)));
		i = parents[i];
	}
	steps->AppendTail(*(new Range(i, parents[i]-1)));
	return *steps;
}
int DynamicProblem::DP(int index, int* parents) const {
	int argmin;
	int tmp = 0;
	if (index >= wordCount-1) {
		parents[index] = index+1;
		return 0;
	}
	int i = index;
	int length = 0;
	while (i < wordCount && length < lineLength) {
		if (i > index) length++;
		length+= words[i].getLength();
		i++;
	}
	length = i-1-index;
	argmin = index;
	int min = badness(Range(index, index));
	for (int i = index+1; i <= index+length; i++) {
		if (dp[i+1]<0) {
			dp[i+1] = DP(i+1, parents);			
		}
		
		tmp = badness(Range(index, i))+ dp[i+1] ;
		if (tmp < min) {
			argmin = i;
			min = tmp;
		}
	}
	parents[index] = argmin + 1;
	return min;
}