/*
 * Relay.cpp
 *
 *  Copyright (c) 2016. All rights reserved.
 *
 *      Author: Jan Trzciński  <poljant@post.pl>
 */

#include <Arduino.h>
#include "Relay.h"

Relay::Relay() {
	pin = 0;
}

Relay::~Relay()
{

}
void Relay::begin(void)
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}

void Relay::setOn(void)
{
	digitalWrite(pin, HIGH);
}
void Relay::setOff(void)
{
	digitalWrite(pin, LOW);
}
int Relay::read(void)
{
	return digitalRead(pin);
}
void Relay::setPin(int p){
	pin = p;
}


