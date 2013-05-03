#include "GloutonProblem.h"

GloutonProblem::GloutonProblem(int lineLength, const String* words, int wordCount, int power): Problem(lineLength, words, wordCount, power) {
}
GloutonProblem::GloutonProblem(const GloutonProblem& src): Problem(src) {
}
GloutonProblem::~GloutonProblem() {
	Problem::~Problem();
}
TList<Range>& GloutonProblem::Solve() const {
	int i = 0;
	TList<Range>* result = new TList<Range>();
	int j = 0;
	while (i < wordCount) {
		j = i;
		int length = 0;
		while (length <= lineLength && j-1 < wordCount) {
			if (j>i) length++;
			length+= words[j].getLength();
			j++;
		}
		result->AppendTail(*(new Range(i, j-2)));
		i = j-1;
	}
	return *result;
}