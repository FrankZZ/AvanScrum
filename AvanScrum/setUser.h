#ifndef setUser_h
#define setUser_h
#include "TFS/User.h"

class setUser
{
public:
	setUser(void);
	~setUser(void);

	User::ItemStorage::iterator	getAllUsers();
};

#endif