#pragma once

#include "DeviceList.h"
#include <iostream>
#include <string>

//a class to user fields and methods
class User
{
public:
    //methods
    void init(unsigned int id, std::string username, unsigned int age);
    void clear();
    unsigned int getID()const;
    std::string getUserName()const;
    unsigned int getAge()const;
    DevicesList& getDevices(); 
    void addDevice(Device newDevice);
    bool checkIfDevicesAreOn()const;

private:
    //fields
    unsigned int _id;
    std::string _userName;
    unsigned int _age;
    DevicesList _devices;
};
