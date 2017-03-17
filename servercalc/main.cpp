#include "Factory.h"

int main(int argc, char** argv) {

	ServerType type = ( argc > 1 ) ? ServerType::thrift : ServerType::dbus;

	ICalcServer* calcServer = Factory::CreateCalcServer(type);

	try	{
		calcServer->Run();
	} catch (...) {
	}

	delete calcServer;

	return 0;
}
