/*
 * CalcThriftHandler.cpp
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#include "CalcThriftHandler.h"

#include <ICalc.h>
#include <cstdio>

CalcThriftHandler::CalcThriftHandler() : mCalc(new ICalc()) {
}

CalcThriftHandler::~CalcThriftHandler(){
}

int32_t CalcThriftHandler::Sum(const int32_t a, const int32_t b) {

	printf("Thrift Calc Handler running...\n");
	fflush(stdout);

	return mCalc->Sum(a, b);

}
