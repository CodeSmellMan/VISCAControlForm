#pragma once

//Klasse for �pning av serial port, sending og mottak av bytes

#include <Windows.h>
#include "ViscaPacket.h"
class SerialHandler
{
public:
	SerialHandler();
	~SerialHandler();

	void sendPacket(ViscaPacket packet);    //Skriver "packet" til serial porten
	void getPanTilt(int &pan, int &tilt);	//Leser det som kommer p� serial porten, tar utgangspunkt i inquiery om pan og tilt posisjon
	void getZoom(int &zoom);				//Leser det som kommer p� serial porten, tar utgangspunkt i inquiery om zoom
	bool getCOMopened();
	int getConnectedCameras();

private:
	HANDLE hSerial;
	DCB dcbSerialParams;
	COMMTIMEOUTS timeouts;

	bool COMopened;

};

