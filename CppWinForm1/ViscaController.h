#pragma once

// Klasse for styring av kamera. Objekt tar inn kameranummeret (1-7) og en peker til et serialHandler objekt.

#include <Windows.h>
#include <iostream>
#include "viscaCommandConstants.h"
#include "ViscaPacket.h"
#include "SerialHandler.h"

class ViscaController {
private:
	int camNmbr;				//Kameranummeret, 1-7
	SerialHandler *sHandler;	//SerialHandler-objekt peker	

public:
	ViscaController(int camNmbr, SerialHandler *sHandler);
	~ViscaController();

	int panCurr;				//Kameraets n�v�rende pan-verdi. 0-816
	int tiltCurr;				//kameraets n�v�rende tilt-verdi. 0-212
	int zoomCurr;				//Kameraets n�v�rende zoom-verdi. 0-2857

	void setPanTilt(int pan, int tilt);  //Setter kameraet til gitt pan og tilt verdi
	void setZoom(unsigned int zoomVal);	 //Setter kameraet til gitt zoom verdi

	void resetCamera();					 //Resetter kamera til n�ytral posisjon. Pan = 408, tilt = 106, zoom = 0
	void autoFocus();

	void getPanTilt(int &pan, int &tilt); //Sp�r kamera om hvilken pan og tilt det har. Setter panCurr og tiltCurr
	void getZoom(int &zoom);			  //Sp�r kamera om hvilken zoom det har. Setter zoomCurr

	void setAddress();					  //Broadcast hvor kameraene i daisy-chain sender videre sin addresse+1


};
