#ifndef _Calculator_H_
#define _Calculator_H_

#include <iostream>
#include <math.h>
#include <cstdlib>  // Pour exit()
#include "Calculator.h"

using namespace std;

unsigned int Calculator::factorielle(unsigned int a) {
	int fact = 1;
	int i = a;
	while (i > 1) {
		fact *= i;
		i--;
	}
	return fact;
}

int Calculator::add(int a, int b) {
	return a + b;
}

int Calculator::sub(int a, int b) {
	return a - b;
}


double Calculator::div(double a, double b){
	if (b==0)
	{
		cerr << "Error: Division by 0 not possible" << std::endl;
		exit(255); // quitte avec le code erreur 255
	}else if (a == 0)
	{
		return 0;
	}
	return a/b;
}


#endif
