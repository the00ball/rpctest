#include <ICalc.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;


int main(int argc, char** argv) {

	int firstNumber = 0;
	int secondNumber = 0;
	int result;

	if (argc >= 3) {
		firstNumber = atoi(argv[1]);
		secondNumber = atoi(argv[2]);
	}

	unique_ptr<ICalc> pCalc(new ICalc);

	try {
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		result = pCalc->Sum(firstNumber, secondNumber);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>( t2 - t1 ).count();
		printf("(%d + %d) = %d in %lu microseconds\n", firstNumber, secondNumber, result, duration);
	} catch (...) {
		printf("Calc is unavailable\n");
	}

	return 0;
}
