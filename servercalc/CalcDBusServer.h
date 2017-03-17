/*
 * CalcDBusServer.h
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#ifndef CALCDBUSSERVER_H_
#define CALCDBUSSERVER_H_

#include "ICalcServer.h"


class CalcDBusServer: public ICalcServer {

	friend class Factory;

private:

	CalcDBusServer();

public:

	virtual void Run();
};

#endif /* CALCDBUSSERVER_H_ */
