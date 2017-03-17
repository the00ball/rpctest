/*
 * CalcThriftServer.cpp
 *
 *  Created on: 14 de mar de 2017
 *      Author: sirineo
 */

#include "CalcThriftServer.h"

#include <boost/smart_ptr/shared_ptr.hpp>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>
#include <cstdio>

#include "CalcThriftHandler.h"
#include "thrift/CalcController.h"


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::rpctest::thrift;


CalcThriftServer::CalcThriftServer() {


}

void CalcThriftServer::Run() {

	printf("Calc Thrift Server is now running...\n");
	fflush(stdout);

	int port = 9090;

	shared_ptr<CalcThriftHandler> handler(new CalcThriftHandler());
	shared_ptr<TProcessor> processor(new CalcControllerProcessor(handler));
	shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
	shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
	server.serve();

}
