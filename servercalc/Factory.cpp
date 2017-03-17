/*
 * CalcServerFactory.cpp
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#include "Factory.h"

#include "CalcDBusServer.h"
#include "CalcThriftServer.h"

ICalcServer* Factory::CreateCalcServer(ServerType type) {

	ICalcServer* server = 0;

	switch(type) {
		case ServerType::dbus: server = new CalcDBusServer(); break;
		case ServerType::thrift: server = new CalcThriftServer(); break;
	}

	return server;
}
