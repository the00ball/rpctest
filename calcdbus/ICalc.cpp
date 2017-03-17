/*
 * ICalc.cpp
 *
 *  Created on: 16 de mar de 2017
 *      Author: sirineo
 */

#include "ICalc.h"

#include <dbus-c++-1/dbus-c++/connection.h>
#include <dbus-c++-1/dbus-c++/dispatcher.h>
#include <dbus-c++-1/dbus-c++/eventloop-integration.h>
#include <dbus-c++-1/dbus-c++/introspection.h>
#include <dbus-c++-1/dbus-c++/object.h>

#include "gen/CalcProxy.h"

/**
 * Calc class
 */

class Calc {

public:
	Calc();

	int Sum(int a, int b);
};


/**
 * CalcProxy Class
 */

class CalcProxy : public ::rpctest::dbus::Calc_proxy,
				  public DBus::IntrospectableProxy,
				  public DBus::ObjectProxy {

public:
	CalcProxy(DBus::Connection &connection, const char *path, const char *name):
		DBus::ObjectProxy(connection, path, name) {
	}
};

// Implementation

/**
 * Calc
 */

static DBus::BusDispatcher dispatcher;

Calc::Calc() {
	DBus::default_dispatcher = &dispatcher;
}

int Calc::Sum(int a, int b) {

	DBus::Connection bus = DBus::Connection::SessionBus();

	CalcProxy calc(bus, "/rpctest/dbus/Calc", "rpctest.dbus.Calc");

	return calc.Sum(a, b);
}

/**
 * ICalc
 */

ICalc::ICalc() : pimpl(new Calc()) {
}

ICalc::~ICalc() {
}

int ICalc::Sum(int a, int b) {
	return pimpl->Sum(a, b);
}
