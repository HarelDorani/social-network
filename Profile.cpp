#include "Profile.h"

//this function initialize the users profile
void Profile::init(User owner)
{
	//set the fields
	this->_owner = owner;
	this->_friends = new UserList();
	//initialize the fields
	this->_friends->init();
	this->_page.init();
}

//this function clears the profile
void Profile::clear()
{
	//clears the profile
	//this->_owner.clear(); this cleared outomaticly
	this->_friends->clear();
	delete this->_friends;
	this->_page.clearPage();
}

//function to get the owner
User Profile::getOwner()const
{
	//return the owner
	return _owner;
}


// function to set the status
void Profile::setStatus(std::string new_status)
{
	//set the status using page class
	this->_page.setStatus(new_status);
}

//function to add post
void Profile::addPostToProfilePage(std::string post)
{
	//add post using page class
	this->_page.addLineToPosts(post);
}

//this function adds friend to the profile
void Profile::addFriend(User friend_to_add)
{
	//add profile using the userList class
	this->_friends->add(friend_to_add);
}


//function tho get the page
std::string Profile::getPage() const 
{
	//a seperator between the status and the posts
	const std::string separator = "\n*******************\n*******************";
	std::string fullPage = "";

	std::string status = this->_page.getStatus();//status
	std::string posts = this->_page.getPosts();//posts

	//make sure the posts does not empty
	if (posts.size() > 0)
	{
		posts += NEW_LINE;
	}
	//add all to one string
	fullPage = "Status: " + status + separator + NEW_LINE + posts;
	return fullPage;
}


//function to get the friends list
std::string Profile::getFriends() const 
{
	std::string friends = "";
	UserNode* curr;
	//make sure there is friends
	if (this->_friends == nullptr || this->_friends->get_first() == nullptr)
	{
		return "";
	}
		
	curr = this->_friends->get_first();
	
	//run through the friends
	while (curr)
	{
		//put the friends name in the string
		friends += curr->get_data().getUserName() + ",";
		curr = curr->get_next();
	}

	//make sure there is friends
	if (!friends.empty())
	{
		//cancel the last ','
		friends.pop_back();
	}
	return friends;//return the string
}


//function to get friends with the same name
std::string Profile::getFriendsWithSameNameLength() const 
{
	std::string friends = "";
	int userSize = 0;
	UserNode* curr;

	//mske sure there is friends
	if (this->_friends == nullptr || this->_friends->get_first() == nullptr)
	{
		return "";
	}
	//get the users name length		
	userSize = this->_owner.getUserName().size();
	curr = this->_friends->get_first();//get the frist friend

	//run through the friends list
	while (curr)
	{
		//check if the user name has the same length as the friend
		if (curr->get_data().getUserName().size() == userSize) 
		{
			//add the friend name to the string
			friends += curr->get_data().getUserName() + ",";
		}
		//move to the next friend
		curr = curr->get_next();
	}

	//mske sure there is friends
	if (!friends.empty())
	{
		//cancel the ','
		friends.pop_back();
	}
	return friends;//return the string
}

void Profile::changeWordInStatus(std::string word_to_replace, std::string new_word)const
{
	
}

void Profile::changeAllWordsInStatus(std::string word)
{
	
}
