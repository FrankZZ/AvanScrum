#include "setUser.h"
#include "TFS/User.h"


setUser::setUser(void)
{
}


setUser::~setUser(void)
{
}

User::ItemStorage::iterator setUser::getAllUsers()
{
	User::ItemStorage::iterator iUser;

	for ( iUser = User::begin(); iUser != User::end(); ++iUser )
	{
		
		int counter = 2;
		
		std::string sName = iUser->first;
	
	}

	return iUser;
}