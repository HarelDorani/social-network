#pragma once

#include <string>
#include <iostream>

///////////////////////////////////////////////////////////
/*									    //
	Those definitions are used for tests,               //
	you can add your own, but please do not delete any. //
*/									    //
enum DeviceType { PHONE, PC, LAPTOP, TABLET };		    //
										//
#define UbuntuOS "UbuntuLinux"                            //						
#define RedHatOS "RedHatLinux"				    //
#define MacOS "MacOS"						    //
#define IOS "IOS"							    //
#define WINDOWS7 "Windows7"                               //
#define WINDOWS10 "Windows10"                             //
#define WINDOWS11 "Windows11"                             //
#define ANDROID "Android"                                 //
										//
/// ///////////////////////////////////////////////////////

/*
* this class include a device filds and function
*/
class Device
{
public :
	std::string getOS()const;
	bool isActive()const;
	void activate();
	void deactivate();
	Device* init(unsigned int id, DeviceType type, std::string os);
	unsigned int getID()const;
	DeviceType getType()const;

private:
	unsigned int _id;
	DeviceType _type;
	bool _active;
	std::string _os;
};