#include <stdlib.h>
#include "String.h"
#include "GloutonProblem.h"
#include "DynamicProblem.h"
#include "Printer.h"

int main(int argc, char** argv) {
	
	FILE* file = fopen("out.txt", "w");
	
	String a;
	a.load("sample.txt");
	String* words;
	int length = 0;

	a.split(' ', &length, &words);
	GloutonProblem gpb1(20, words, length, 1);
	GloutonProblem gpb2(20, words, length, 2);
	GloutonProblem gpb3(20, words, length, 3);
	DynamicProblem dpb1(20, words, length, 1);
	DynamicProblem dpb2(20, words, length, 2);
	DynamicProblem dpb3(20, words, length, 3);
	
	fprintf(file, "Glouton Problem - W=20 Power=1\n\n");
	TList<Range> solution = gpb1.Solve();
	Printer::print(file, 20, words, solution, 1);
	fprintf(file, "\n");

	fprintf(file, "Glouton Problem - W=20 Power=2\n\n");
	solution = gpb2.Solve();
	Printer::print(file, 20, words, solution, 2);
	fprintf(file, "\n");

	fprintf(file, "Glouton Problem - W=20 Power=3\n\n");
	solution = gpb3.Solve();
	Printer::print(file, 20, words, solution, 3);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem - W=20 Power=1\n\n");
	solution = dpb1.Solve();
	Printer::print(file, 20, words, solution, 1);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem - W=20 Power=2\n\n");
	solution = dpb2.Solve();
	Printer::print(file, 20, words, solution, 2);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem - W=20 Power=3\n\n");
	solution = dpb3.Solve();
	Printer::print(file, 20, words, solution, 3);
	fprintf(file, "\n");

	fclose(file);
	getchar();
	return 0;
}