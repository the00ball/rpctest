/*
 * CalcDBUSServer.h
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#ifndef CALCDBUSIMPL_H_
#define CALCDBUSIMPL_H_

#include <dbus-c++-1/dbus-c++/connection.h>
#include <dbus-c++-1/dbus-c++/introspection.h>
#include <dbus-c++-1/dbus-c++/object.h>
#include <cstdint>
#include <memory>

#include "dbus/CalcAdaptor.h"

class ICalc;



class CalcDBusHandler: public rpctest::dbus::Calc_adaptor,
					   public DBus::IntrospectableAdaptor,
				       public DBus::ObjectAdaptor {

	friend class CalcDBusServer;

private:

	std::unique_ptr<ICalc> mCalc;

	CalcDBusHandler(DBus::Connection& connection);

public:

	~CalcDBusHandler();

	virtual int32_t Sum(const int32_t& a, const int32_t& b);
};

#endif /* CALCDBUSIMPL_H_ */
