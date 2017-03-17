/*
 * CalcThriftHandler.h
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#ifndef THRIFT_CALCTHRIFTHANDLER_H_
#define THRIFT_CALCTHRIFTHANDLER_H_

#include <cstdint>
#include <memory>

#include "thrift/CalcController.h"

class ICalc;

class CalcThriftHandler: public virtual rpctest::thrift::CalcControllerIf {

	friend class CalcThriftServer;

private:
	std::unique_ptr<ICalc> mCalc;

	CalcThriftHandler();

public:

	~CalcThriftHandler();

	virtual int32_t Sum(const int32_t a, const int32_t b);
};

#endif /* THRIFT_CALCTHRIFTHANDLER_H_ */
