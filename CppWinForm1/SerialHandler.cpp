#include "SerialHandler.h"
#include <Windows.h>

SerialHandler::SerialHandler()
{
	hSerial = CreateFile(L"\\\\.\\COM1", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (hSerial == INVALID_HANDLE_VALUE)
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			std::cout << "Could not find serial port, LELWUT RIPERINJOS" << std::endl;
		}
		std::cout << "FUNKET IKKE RIP" << std::endl;
		COMopened = false;
	}
	else
	{
		COMopened = true;
	}

	dcbSerialParams = { 0 };

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		std::cout << "Error getting states, top kek" << std::endl;
	}

	dcbSerialParams.BaudRate = CBR_9600;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;

	if (!SetCommState(hSerial, &dcbSerialParams))
	{
		std::cout << "Error setting states, unluckers" << std::endl;
	}

	timeouts = { 0 };

	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (!SetCommTimeouts(hSerial, &timeouts))
	{
		std::cout << "Error setting comm timouts, feelsbadman" << std::endl;
	}
}

SerialHandler::~SerialHandler()
{
	CloseHandle(hSerial);
}

void SerialHandler::sendPacket(ViscaPacket packet)
{
	DWORD bytes_written, total_bytes_written = 0;
	std::cout << "SeENNDDING!!" << std::endl;
	if (!WriteFile(hSerial, packet.getPacket(), packet.getLength(), &bytes_written, NULL))
	{
		std::cout << "Funket ikke, lelwut" << std::endl;
		CloseHandle(hSerial);
	}
}

void SerialHandler::getPanTilt(int &pan, int &tilt)
{
	DWORD bytes_read;
	std::cout << "Leser fra porten" << std::endl;

	unsigned char buffer[11];

	ReadFile(hSerial, &buffer, sizeof(buffer), &bytes_read, NULL);

	pan = (int)(((unsigned char)buffer[5]) | ((unsigned char)buffer[4] << 4) |
		((unsigned char)buffer[3] << 8) | ((unsigned char)buffer[2]) << 12);
	tilt = (int)(((unsigned char)buffer[9]) | ((unsigned char)buffer[8] << 4) |
		((unsigned char)buffer[7] << 8) | ((unsigned char)buffer[6]) << 12);
}

void SerialHandler::getZoom(int &zoom)
{
	DWORD bytes_read;
	std::cout << "Leser fra porten" << std::endl;

	unsigned char buffer[7];

	ReadFile(hSerial, &buffer, sizeof(buffer), &bytes_read, NULL);

	zoom = (int)(((unsigned char)buffer[5]) | ((unsigned char)buffer[4] << 4) |
		((unsigned char)buffer[3] << 8) | ((unsigned char)buffer[2]) << 12);

}

bool SerialHandler::getCOMopened()
{
	return COMopened;
}