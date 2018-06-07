#pragma once

// Klasse for å gjøre det lettere å sende packets. 

#include <Windows.h>
#include <iostream>

class ViscaPacket
{
public:
	ViscaPacket();
	~ViscaPacket();

	void addByte(unsigned char byte); //Legger til en byte til packet
	unsigned char * getPacket();	  //Returnerer packet. Brukes ved skriving av bytes på COMport
	int getLength();			      //Returnerer lengden av packet. Brukes ved skriving av bytes på COMport

private:
	unsigned char * packet;			  //Selve pakken. Unsigned char = unsigned byte, 0-255
	int length;						  //Teller lengden av pakken. 

};



