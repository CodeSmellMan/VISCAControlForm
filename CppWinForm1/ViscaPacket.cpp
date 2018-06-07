#include "ViscaPacket.h"

ViscaPacket::ViscaPacket()
{
	packet = new unsigned char[32];
	packet[0] = '\0';
	length = 0;
}

ViscaPacket::~ViscaPacket()
{
}

void ViscaPacket::addByte(unsigned char byte)
{
	packet[length] = byte;
	packet[length + 1] = (0x00);
	length++;
}

unsigned char * ViscaPacket::getPacket()
{
	return packet;
}

int ViscaPacket::getLength()
{
	return length;
}
