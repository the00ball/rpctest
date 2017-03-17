/*
 * CalcDBUSServer.cpp
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#include "CalcDBusHandler.h"

#include <ICalc.h>
#include <cstdio>

CalcDBusHandler::CalcDBusHandler(DBus::Connection& connection) :
	DBus::ObjectAdaptor(connection, "/rpctest/dbus/Calc") {
	mCalc = std::unique_ptr<ICalc>(new ICalc);
}

CalcDBusHandler::~CalcDBusHandler() {
}


int32_t CalcDBusHandler::Sum(const int32_t& a, const int32_t& b) {
	printf("DBUS Calc Handler running...\n");
	fflush(stdout);
	return mCalc->Sum(a, b);
}
