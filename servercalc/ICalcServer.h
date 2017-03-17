/*
 * ICalcServer.h
 *
 *  Created on: 16 de mar de 2017
 *      Author: sirineo
 */

#ifndef ICALCSERVER_H_
#define ICALCSERVER_H_

class ICalcServer {
public:
	virtual ~ICalcServer() { };

	virtual void Run() = 0;
};

#endif /* ICALCSERVER_H_ */
