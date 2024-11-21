#include "SocialNetwork.h"

//function to initialize the network
void SocialNetwork::init(std::string networkName, int minAge)
{
	//set the fileds as requested 
	this->_minAge = minAge;
	this->_networkName = networkName;
	//initialize the profile list
	this->_profiles = new ProfileList();
	this->_profiles->init();
}

//function to clear the network
void SocialNetwork::clear()
{
	//set the fields to nothing and delete the profiles
	this->_minAge = 0;
	this->_networkName = "";
	delete this->_profiles;
}

//function to get the network name
std::string SocialNetwork::getNetworkName()
{
	//return the network name
	return this->_networkName;
}

int SocialNetwork::getMinAge()
{
	return this->_minAge;
}


//this function will add a profile to the social network
bool SocialNetwork::addProfile(Profile profile_to_add)
{
	//get the first profile
	ProfileNode* first = this->_profiles->get_first();
	ProfileNode* curr = first;
	//make sure the new profile is nor below the minimum age
	if (profile_to_add.getOwner().getAge() < this->_minAge)
	{
		return false;//return false
	}
	//in  case of the first profile
	if (curr == nullptr)
	{
		//add the new profile
		ProfileNode* new_node = new ProfileNode;
		new_node->init(profile_to_add);
		this->_profiles->set_first(new_node);
		return true;
	}

	//go to the last profile
	while (curr->get_next())
	{
		curr = curr->get_next();
	}
	//add the new profile to the end of the list
	ProfileNode* new_node = new ProfileNode;
	new_node->init(profile_to_add);
	curr->set_next(new_node);

	return true;//return true
}


//this function will return a  string with all the windows devices in the network
std::string SocialNetwork::getWindowsDevices()
{
	ProfileNode* curr = this->_profiles->get_first();
	std::string winDevices = "";
	DeviceNode* currDevice;

	//run through the profilies
	while (curr)
	{
		//get the current profile devices
		DevicesList& devices = curr->get_data().getOwner().getDevices();
		currDevice = devices.get_first();
		//run through the devices
		while (currDevice)
		{
			//get the current device operation system
			std::string os = currDevice->get_data().getOS();

			//check if the os in belong to windows
			if (os == WINDOWS7 || os == WINDOWS10 || os == WINDOWS11)
			{
				//add the device id and os to the  string
				winDevices += '[';
				winDevices += std::to_string(currDevice->get_data().getID());
				winDevices += ", ";
				winDevices += os;
				winDevices += "], ";
			}
			currDevice = currDevice->get_next();
		}
		curr = curr->get_next();
	}

	//make sure the string is not empty
	if (!winDevices.empty())
	{
		winDevices.pop_back(); //remove last space
		winDevices.pop_back(); //remove last comma
	}

	return winDevices;
}