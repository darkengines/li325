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
}
TList<Range>& DynamicProblem::Solve() const {
	int* parents = new int[wordCount];
	TList<Range>* steps = new TList<Range>();
	int result = DP(0, parents);
	int i = 0;
	while (i < wordCount-1) {
		steps->AppendTail(*(new Range(i, parents[i])));
		i = parents[i]+1;
	}
	steps->AppendTail(*(new Range(i, parents[i])));
	return *steps;
}
int DynamicProblem::DP(int index, int* parents) const {
	if (index >= wordCount-1) {
		parents[index] = index;
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
	int min = -1;
	for (i = index; i <= wordCount; i++) {
		if (dp[i+1]<0) {
			dp[i+1] = DP(i+1, parents);	
		}
		int b = badness(Range(index, i));
		int c = dp[i+1];
		if (b >= 0 && c >= 0) {
			int tmp = b + c;
			if (min < 0 || tmp < min) {
				parents[index] = i;
				min = tmp;
			}
		}
	}
	return min;
}
