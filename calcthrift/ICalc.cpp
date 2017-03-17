/*
 * ICalc.cpp
 *
 *  Created on: 16 de mar de 2017
 *      Author: sirineo
 */

#include "ICalc.h"

#include <boost/smart_ptr/shared_ptr.hpp>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransport.h>

#include "gen/CalcController.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace ::rpctest::thrift;

/**
 * Calc class
 */

class Calc {

public:
	Calc();

	int Sum(int a, int b);
};

// Implementation

/**
 * Calc
 */

Calc::Calc() {
}


int Calc::Sum(int a, int b) {

	int result = 0;

	boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	CalcControllerClient client(protocol);

	transport->open();

	try {

		result = client.Sum(a, b);

	} catch (...) {
	}

	transport->close();

	return result;
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
