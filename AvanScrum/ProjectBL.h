#ifndef ProjectBL_h
#define ProjectBL_h
#include <atlstr.h>
#include <string>
#include <vector>

class ProjectBL
{
private:

public:
	ProjectBL();
	~ProjectBL();
	void makeLocalDemoProject(void);
	void makeRemoteDemoProject(void);
	void readLocalProject(std::string);
	void readRemoteProject(std::string);
	void saveRemoteProject(std::string);
	//void saveLocalSBI(std::string, int, int, std::string, std::string, const char*, int, int, int);
	void saveLocalSBI(SprintBacklogItem*);
};

#endif