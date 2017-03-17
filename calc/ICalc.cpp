/*
 * ICalc.cpp
 *
 *  Created on: 16 de mar de 2017
 *      Author: sirineo
 */

#include "ICalc.h"

/**
 * Calc class
 */

class Calc {

public:
	Calc();

	int Sum(int a, int b);
};

// Implementation

Calc::Calc() {

}

int Calc::Sum(int a, int b) {
	return a + b;
}

ICalc::ICalc() : pimpl(new Calc()) {
}

ICalc::~ICalc() {
}

int ICalc::Sum(int a, int b) {
	return pimpl->Sum(a, b);
}
