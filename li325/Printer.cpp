#include "Printer.h"

void Printer::print(FILE* out, int lineLength, String* words, TList<Range> instructions, int power) {
	const TListItem<Range>* cursor = instructions.Head();
	int totalScore = 0;
	int j = 0;
	fprintf(out, "LINES");
	while (j<lineLength-4) {
		fprintf(out, " ");
		j++;
	}
	fprintf(out, "BADNESS\n");
	j = 0;
	while (j<lineLength+8) {
		fprintf(out, "-");
		j++;
	}
	fprintf(out, "\n");
	while (cursor) {
		const Range range = cursor->GetItem();
		int i = range.left;
		j = 0;
		int score = 0;
		if (cursor->GetNext()) {
			score = getBadness(lineLength, words, range, power);
		}
		totalScore += score;
		while (i <= range.right) {
			fprintf(out, "%s", words[i].getChars());
			j+=words[i].getLength();
			if (i < range.right) {
				fprintf(out, "_");
				j++;
			}
			i++;
			
		}
		while (j < lineLength) {
			fprintf(out, "_");
			j++;
		}
		fprintf(out, "   %5d\n", score);
		cursor = cursor->GetNext();
	}
	j = 0;
	while (j<lineLength+8) {
		fprintf(out, "-");
		j++;
	}
	fprintf(out, "\n");
	j = 0;
	fprintf(out, "TOTAL");
	while (j<lineLength-2) {
		fprintf(out, " ");
		j++;
	}
	fprintf(out, "%5d\n", totalScore);
}
int Printer::getBadness(int lineLength, String* words, Range range, int power) {
	int i = range.left;
	int j = range.right;
	int result = lineLength - j + i;
	while (i<=j) {
		result -= words[i].getLength();
		i++;
	}
	int temp = result;
	while (--power) {
		result *= temp;
	}
	return result;
}
