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
	
	//computes the problem solution (in range [0;wordCount[)
	int result = DP(0, parents);
	int i = 0;
	//builds the printer instructions from the stored word ranges
	while (i < wordCount-1) {
		steps->AppendTail(*(new Range(i, parents[i])));
		i = parents[i]+1;
	}
	steps->AppendTail(*(new Range(i, parents[i])));
	return *steps;
}
int DynamicProblem::DP(int index, int* parents) const {
	//dp[wordcount] = 0
	if (index >= wordCount-1) {
		parents[index] = index;
		return 0;
	}
	//restricts recursions to the line capacity
	int i = index;
	int length = 0;
	while (i < wordCount && length < lineLength) {
		if (i > index) length++;
		length+= words[i].getLength();
		i++;
	}
	length = i-1-index;
	int min = -1; //means infinity
	//computes the minimum badness for each given range
	for (i = index; i <= wordCount; i++) {
		if (dp[i+1]<0) {
			dp[i+1] = DP(i+1, parents);	//solves a subproblem and stores solution in dp
		}
		int b = badness(Range(index, i));
		int c = dp[i+1];
		if (b >= 0 && c >= 0) {
			int tmp = b + c;
			if (min < 0 || tmp < min) {
				parents[index] = i; //store the line word range
				min = tmp;
			}
		}
	}
	return min;
}
