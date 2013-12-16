#ifndef user_h
#define user_h
#include "TFS/User.h"

class user
{
public:
	user(void);
	~user(void);

	User::ItemStorage::iterator	getAllUsers();
};

#endif