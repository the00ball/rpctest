/*
 * CalcServerFactory.h
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "ICalcServer.h"

enum class ServerType {
	dbus,
	thrift
};

class Factory {

public:
	static ICalcServer* CreateCalcServer(ServerType type);
};

#endif /* FACTORY_H_ */
