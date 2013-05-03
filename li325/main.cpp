#include <stdlib.h>
#include "String.h"
#include "GloutonProblem.h"
#include "DynamicProblem.h"
#include "Printer.h"

int main(int argc, char** argv) {
	String a;
	a.load("sample_short.txt");
	String* words;
	int length = 0;

	a.split(' ', &length, &words);

	DynamicProblem gpb(50, words, length, 3);
	TList<Range> solution = gpb.Solve();

	const TListItem<Range>* cursor = solution.GetFirst();
	FILE* file = fopen("out.txt", "w");
	Printer::print(stdout, 50, words, solution, 3);
	fclose(file);
	getchar();
	getchar();
	return 0;
}