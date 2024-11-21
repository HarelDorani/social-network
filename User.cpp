#include "User.h"
#include <iostream>
#include <string>
#include "DeviceList.h"
#include "Device.h"

//function to initialize user
void User::init(unsigned int id, std::string username, unsigned int age)
{
    //set the user fields as requested and init if needed
    this->_id = id;
    this->_userName = username;
    this->_age = age;
    _devices.init();
}

//function to clear user
void User::clear()
{
    //set all fields to nothing
    this->_devices.clear();
    this->_id = 0;
    this->_userName = "";
    this->_age = 0;
}

//function to get the user id
unsigned int User::getID()const
{
    //return the id
    return _id;
}

//function to get the user name
std::string User::getUserName()const
{
    //return the user name
    return _userName;
}

//functio  to get the user age
unsigned int User::getAge()const
{
    //return the users age
    return _age;
}

//function  to get the users devices
DevicesList& User::getDevices()
{
    //return the devices
    return _devices;
}

//funcrtion to add devices
void User::addDevice(Device newDevice)
{
    //use the add() function from the device list
    this->_devices.add(newDevice);
}

//check if devices orr on
bool User::checkIfDevicesAreOn()const
{
    //get the devices list
    DeviceNode* curr = this->_devices.get_first();
    //run through the devices
    while (curr)
    {
        //check if device is off
        if (!curr->get_data().isActive())
        {
            //return false if off
            return false;
        }
        //move to the next device
        curr = curr->get_next();
    }
    //return true if all devices are on
    return true;
}
