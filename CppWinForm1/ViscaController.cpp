#include "ViscaController.h"

ViscaController::ViscaController(int camNmbr, SerialHandler *sHandler) : camNmbr(camNmbr), sHandler(sHandler),
panCurr(0), tiltCurr(0), zoomCurr(0)
{
	std::cout << "Kamera object laget med kamera nummer " << camNmbr << std::endl;
	getPanTilt(panCurr, tiltCurr);
	getZoom(zoomCurr);

	std::cout << "Kamera " << camNmbr << " har pan, tilt, zoom: " << panCurr << ", " << tiltCurr << ", " << zoomCurr << std::endl;
}

ViscaController::~ViscaController()
{

}

void ViscaController::setZoom(unsigned int zoomVal)
{
	ViscaPacket packet;

	unsigned int zoom;
	unsigned char z1, z2, z3, z4;

	unsigned char receiver, commandHeader, dataHeader, command, terminator;

	zoom = zoomVal & 0xffff;
	z1 = 0; z2 = 0; z3 = 0; z4 = 0;

	z1 = (zoom & 0xf000) >> 12;
	z2 = (zoom & 0x0f00) >> 8;
	z3 = (zoom & 0x00f0) >> 4;
	z4 = zoom & 0x000f;

	receiver = VISCA_SEND_HEADER + camNmbr;
	commandHeader = VISCA_COMMAND_HEADER;
	dataHeader = VISCA_DATA_HEADER;
	command = VISCA_ZOOM_DIRECT;
	terminator = VISCA_TERMINATOR;

	packet.addByte(receiver);
	packet.addByte(commandHeader);
	packet.addByte(dataHeader);
	packet.addByte(command);
	packet.addByte(z1);
	packet.addByte(z2);
	packet.addByte(z3);
	packet.addByte(z4);
	packet.addByte(terminator);

	sHandler->sendPacket(packet);
}

void ViscaController::setPanTilt(int pan, int tilt)
{
	int panBytes, tiltBytes;
	unsigned char p1, p2, p3, p4, t1, t2, t3, t4;
	panBytes = 0xFFFF & pan;
	tiltBytes = 0xFFFF & tilt;

	p1 = 0x0f & (panBytes >> 12);	//Delen av pakken som gir panverdien er på formen 0p1 0p2 0p3 0p4
	p2 = 0x0f & (panBytes >> 8);    //Henter ut rett del av panBytes og legger i hver sin px
	p3 = 0x0f & (panBytes >> 4);
	p4 = 0x0f & (panBytes);

	t1 = 0x0f & (tiltBytes >> 12); //Akkurat samme for tilt
	t2 = 0x0f & (tiltBytes >> 8);
	t3 = 0x0f & (tiltBytes >> 4);
	t4 = 0x0f & (tiltBytes);

	unsigned char receiver, commandHeader, dataHeader, command, terminator;
	receiver = VISCA_SEND_HEADER + camNmbr;
	commandHeader = VISCA_COMMAND_HEADER;
	dataHeader = VISCA_PAN_TILT;
	command = VISCA_ABS_POS;
	terminator = VISCA_TERMINATOR;

	ViscaPacket packet;

	packet.addByte(receiver);
	packet.addByte(commandHeader);
	packet.addByte(dataHeader);
	packet.addByte(command);
	packet.addByte(0x18);
	packet.addByte(0x14);
	packet.addByte(p1);
	packet.addByte(p2);
	packet.addByte(p3);
	packet.addByte(p4);
	packet.addByte(t1);
	packet.addByte(t2);
	packet.addByte(t3);
	packet.addByte(t4);
	packet.addByte(terminator);

	sHandler->sendPacket(packet);

}

void ViscaController::resetCamera()
{
	ViscaPacket packet;

	unsigned char receiver, commandHeader, dataHeader, command, terminator;
	receiver = VISCA_SEND_HEADER + camNmbr;
	commandHeader = VISCA_COMMAND_HEADER;
	dataHeader = VISCA_PAN_TILT;
	command = VISCA_RESET_CAMERA;
	terminator = VISCA_TERMINATOR;

	packet.addByte(receiver);
	packet.addByte(commandHeader);
	packet.addByte(dataHeader);
	packet.addByte(command);
	packet.addByte(terminator);

	sHandler->sendPacket(packet);
}

void ViscaController::autoFocus()
{
	ViscaPacket packet;

	unsigned char receiver, commandHeader, dataHeader, command1, command2, terminator;
	receiver = VISCA_SEND_HEADER + camNmbr;
	commandHeader = VISCA_COMMAND_HEADER;
	dataHeader = VISCA_DATA_HEADER;
	command1 = VISCA_AUTO_FOCUS;
	command2 = 0x01;
	terminator = VISCA_TERMINATOR;

	packet.addByte(receiver);
	packet.addByte(commandHeader);
	packet.addByte(dataHeader);
	packet.addByte(command1);
	packet.addByte(command2);
	packet.addByte(terminator);

	sHandler->sendPacket(packet);

}

void ViscaController::getPanTilt(int &pan, int &tilt)
{
	ViscaPacket packet;

	unsigned char receiver, inquiryHeader, command1, command2, terminator;
	receiver = VISCA_SEND_HEADER + camNmbr;
	inquiryHeader = VISCA_INQUIERY_HEADER;
	command1 = VISCA_PAN_TILT;
	command2 = VISCA_PAN_TILT_POS;
	terminator = VISCA_TERMINATOR;

	packet.addByte(receiver);
	packet.addByte(inquiryHeader);
	packet.addByte(command1);
	packet.addByte(command2);
	packet.addByte(terminator);

	sHandler->sendPacket(packet);
	sHandler->getPanTilt(pan, tilt);
}

void ViscaController::getZoom(int &zoom)
{
	ViscaPacket packet;

	unsigned char receiver, inquiryHeader, command1, command2, terminator;
	receiver = VISCA_SEND_HEADER + camNmbr;
	inquiryHeader = VISCA_INQUIERY_HEADER;
	command1 = VISCA_DATA_HEADER;
	command2 = VISCA_ZOOM_DIRECT;
	terminator = VISCA_TERMINATOR;

	packet.addByte(receiver);
	packet.addByte(inquiryHeader);
	packet.addByte(command1);
	packet.addByte(command2);
	packet.addByte(terminator);

	sHandler->sendPacket(packet);
	sHandler->getZoom(zoom);
}

void ViscaController::setAddress()
{
	ViscaPacket packet;

	unsigned char receiver, commandHeader, dataHeader, terminator;
	receiver = VISCA_BROADCAST;
	commandHeader = 0x30;
	dataHeader = 0x01;
	terminator = VISCA_TERMINATOR;

	packet.addByte(receiver);
	packet.addByte(commandHeader);
	packet.addByte(dataHeader);
	packet.addByte(terminator);

	sHandler->sendPacket(packet);
}

