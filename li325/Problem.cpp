#include "Problem.h"

Problem::Problem(int lineLength, const String* words, int wordCount, int power): lineLength(lineLength), words(words), wordCount(wordCount), power(power) {
}
Problem::Problem(const Problem& src): lineLength(src.lineLength), words(src.words), wordCount(src.wordCount), power(src.power) {
}
Problem::~Problem() {
}
int Problem::badness(const Range& range) const {
	int result = lineLength - range.right + range.left;
	int i;
	for (i=range.left;i<=range.right;i++) {
		result -= words[i].getLength();
	}
	if (result < 0) {
		return 99999;
	} else {
		int tmp = result;
		int i = power-1;
		if (i) {
			while (i--) {
				result *= tmp;
			}
		}
		return result;
	}
}