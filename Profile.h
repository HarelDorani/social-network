#pragma once
#include "Device.h"
#include "DeviceList.h"
#include "Page.h"
#include "Profile.h"
#include "User.h"
#include <iostream>
#include "UserList.h"
#include <string>


//this class includes the profile fields and methods
class Profile
{
public:
	void init(User owner);
	void clear();
	User getOwner()const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage()const;
	std::string getFriends()const;
	std::string getFriendsWithSameNameLength()const;
	void changeAllWordsInStatus(std::string word);
	void changeWordInStatus(std::string word_to_replace, std::string new_word)const;
private:
	User _owner;
	Page _page;
	UserList* _friends;
};