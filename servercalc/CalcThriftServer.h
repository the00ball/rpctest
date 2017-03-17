/*
 * CalcThriftServer.h
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#ifndef THRIFT_CALCTHRIFTSERVER_H_
#define THRIFT_CALCTHRIFTSERVER_H_

#include "ICalcServer.h"

class CalcThriftServer: public ICalcServer {

	friend class Factory;

private:

	CalcThriftServer();

public:

	virtual void Run();

};

#endif /* THRIFT_CALCTHRIFTSERVER_H_ */
