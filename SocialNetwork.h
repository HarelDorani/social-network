#pragma once

#include "Device.h"
#include "DeviceList.h"
#include "Page.h"
#include "Profile.h"
#include "User.h"
#include <iostream>
#include "UserList.h"
#include <string>
#include "ProfileList.h"

//this class includes the social networkfields and methods
class SocialNetwork
{
public:
	//methods
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName();
	int getMinAge();
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices();
private:
	//fields
	std::string _networkName;
	int _minAge;
	ProfileList* _profiles;
};