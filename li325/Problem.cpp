#include "Problem.h"

Problem::Problem(const int lineLength, const String* words, const int wordCount, const int power): lineLength(lineLength), words(words), wordCount(wordCount), power(power) {
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
	return result;
}