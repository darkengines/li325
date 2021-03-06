#include <stdlib.h>
#include "String.h"
#include "GloutonProblem.h"
#include "DynamicProblem.h"
#include "Printer.h"

int main(int argc, char** argv) {
	
	char* inputFilename = argv[1];
	char* outputFilename = argv[2];
	
	String text;
	
	//Loading input text
	text.load(inputFilename);
	
	String* words;
	int length = 0;
	
	//Spliting input text in word array
	text.split(' ', &length, &words);
	
	//Setting problems
	GloutonProblem gpb1(20, words, length, 1);
	GloutonProblem gpb2(20, words, length, 2);
	GloutonProblem gpb3(20, words, length, 3);
	
	DynamicProblem dpb1(20, words, length, 1);
	DynamicProblem dpb2(20, words, length, 2);
	DynamicProblem dpb3(20, words, length, 3);
	
	GloutonProblem gpb4(50, words, length, 1);
	GloutonProblem gpb5(50, words, length, 2);
	GloutonProblem gpb6(50, words, length, 3);
	
	DynamicProblem dpb4(50, words, length, 1);
	DynamicProblem dpb5(50, words, length, 2);
	DynamicProblem dpb6(50, words, length, 3);
	
	FILE* file = fopen(outputFilename, "w");
	
	//Solving problems and display results
	fprintf(file, "Glouton Problem W=20 Power=1\n\n");
	TList<Range> solution = gpb1.Solve();
	Printer::print(file, 20, words, solution, 1);
	fprintf(file, "\n");

	fprintf(file, "Glouton Problem W=20 Power=2\n\n");
	solution = gpb2.Solve();
	Printer::print(file, 20, words, solution, 2);
	fprintf(file, "\n");

	fprintf(file, "Glouton Problem W=20 Power=3\n\n");
	solution = gpb3.Solve();
	Printer::print(file, 20, words, solution, 3);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem W=20 Power=1\n\n");
	solution = dpb1.Solve();
	Printer::print(file, 20, words, solution, 1);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem W=20 Power=2\n\n");
	solution = dpb2.Solve();
	Printer::print(file, 20, words, solution, 2);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem W=20 Power=3\n\n");
	solution = dpb3.Solve();
	Printer::print(file, 20, words, solution, 3);
	fprintf(file, "\n");
	
	fprintf(file, "Glouton Problem W=50 Power=1\n\n");
	solution = gpb4.Solve();
	Printer::print(file, 50, words, solution, 1);
	fprintf(file, "\n");

	fprintf(file, "Glouton Problem W=50 Power=2\n\n");
	solution = gpb5.Solve();
	Printer::print(file, 50, words, solution, 2);
	fprintf(file, "\n");

	fprintf(file, "Glouton Problem W=50 Power=3\n\n");
	solution = gpb6.Solve();
	Printer::print(file, 50, words, solution, 3);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem W=50 Power=1\n\n");
	solution = dpb4.Solve();
	Printer::print(file, 50, words, solution, 1);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem W=50 Power=2\n\n");
	solution = dpb5.Solve();
	Printer::print(file, 50, words, solution, 2);
	fprintf(file, "\n");

	fprintf(file, "Dynamic Problem W=50 Power=3\n\n");
	solution = dpb6.Solve();
	Printer::print(file, 50, words, solution, 3);
	fprintf(file, "\n");

	fclose(file);
	return 0;
}
