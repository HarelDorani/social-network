#include "Page.h"

//this function initialize the page
void Page::init()
{
	//set the status and posts to nothing
	this->_status = "";
	this->_lines = "";
}

//function to get the posts
std::string Page::getPosts()const
{
	//return the posts
	return _lines;
}

//function to get the status
std::string Page::getStatus()const
{
	//return the status
	return _status;
}

//this function is to clear the page
void Page::clearPage()
{
	//set the status and posts to nothing
	this->_status = "";
	this->_lines = "";
}

//this function is to set the status
void Page::setStatus(std::string status)
{
	//return the status
	this->_status = status;
}

//this function is to add a new post
void Page::addLineToPosts(std::string new_line)
{
	//make sure the posts is not empty to add \n
	if (this->_lines.size() > 0)
	{
		this->_lines += NEW_LINE;
	}
	//add the new line
	this->_lines += new_line;
}