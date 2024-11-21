#include "Device.h"

//function to get the device operation system
std::string Device::getOS()const
{
	//return the operation system of the device
	return _os;
}

//function to find if the device is activate or not
bool Device::isActive()const
{
	//return wether the device is active or not
	return _active;
}

//function to activate the device
void Device::activate()
{
	//put true in "active" to activate the device
	_active = true;
}

//function to deactivate the device
void Device::deactivate()
{
	//put false in "active" to deactivate the device
	_active = false;
}

//function to get the device ID
unsigned int Device::getID()const
{
	//return the device id
	return _id;
}

//function to get the device type
DeviceType Device::getType()const 
{
	//return the device type
	return _type;
}

//function to initialize a device
Device* Device::init(unsigned int id, DeviceType type, std::string os)
{
	//initialize the device fields
	this->_id = id;
	this->_type = type;
	this->_os = os;
	//activate the device
	this->activate();
	//return the device
	return this;
}