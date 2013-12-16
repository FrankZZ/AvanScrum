#ifndef aUser_h
#define aUser_h
#include "TFS/User.h"

class aUser
{
public:
	aUser(void);
	~aUser(void);

	User::ItemStorage::iterator	getAllUsers();
};

#endif