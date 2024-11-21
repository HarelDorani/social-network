#pragma once
#include "User.h"
#include <iostream>
#include <string>
#include "DeviceList.h"
#include "Device.h"

#define NEW_LINE '\n'

//this class includes the pages fields and methods
class Page
{
public:
	void init();
	std::string getPosts()const;
	std::string getStatus()const;
	void clearPage();
	void setStatus(std::string status);
	void addLineToPosts(std::string new_line);
private:
	std::string _status;
	std::string _lines;
};