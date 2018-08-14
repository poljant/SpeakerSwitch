/*
 * Relay.h
 *
 *   Copyright (c) 2016. All rights reserved.
 *
 *      Author: Jan Trzciński  <poljant@post.pl>
 *
 *      Klasa Relay umożliwia obsługę i kontrolę pracy przkaźnika
 *      podłączonego do określonego pinu.
 * 		Klasa RF2260 umożliwia nadawanie kodów dla układu z serii 2260.i podobnych.
 *      Układ ten stosowany jest w tanich i popularnych wyłacznikach 220V.
 *      Częstotliwość nadawania to 433MHz  lub 896MHz.
 *      Do uruchomienia układu potrzebny jest nadajnik RF na 433MHz lub 866MHz
 */

#ifndef RELAY_H_
#define RELAY_H_

class Relay {
	int pin;
public:
	Relay();
	virtual ~Relay();
	void setPin(int);
	void begin();
	void setOn();
	void setOff();
	int read();
};
#endif /* RELAY_H_ */
