#include "user.h"
#include "TFS/User.h"


user::user(void)
{
}


user::~user(void)
{
}

User::ItemStorage::iterator user::getAllUsers()
{
	User::ItemStorage::iterator iUser;

	for ( iUser = User::begin(); iUser != User::end(); ++iUser )
	{
		
		int counter = 2;
		
		std::string sName = iUser->first;
	
	}

	return iUser;
}