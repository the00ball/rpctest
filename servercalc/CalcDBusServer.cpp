/*
 * CalcDBusServer.cpp
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#include "CalcDBusServer.h"

#include <dbus-c++-1/dbus-c++/connection.h>
#include <dbus-c++-1/dbus-c++/dispatcher.h>
#include <dbus-c++-1/dbus-c++/eventloop-integration.h>
#include <cstdio>

#include "CalcDBusHandler.h"

DBus::BusDispatcher dispatcher;

CalcDBusServer::CalcDBusServer() {
}

void CalcDBusServer::Run() {

	printf("Calc DBUS Server is now running...\n");
	fflush(stdout);

	DBus::default_dispatcher = &dispatcher;
	DBus::Connection bus = DBus::Connection::SessionBus();

	bus.request_name("rpctest.dbus.Calc");

	CalcDBusHandler calc(bus);

	dispatcher.enter();
}
