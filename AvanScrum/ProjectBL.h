#ifndef ProjectBL_h
#define ProjectBL_h
#include <atlstr.h>
#include <string>
#include "TFS\Project.h"
#include "TFS\Sprint.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\TFSTransaction.h"
#include "TFS\User.h"

class ProjectBL
{
private:
	CString            sText;
	std::string        name;
	Sprint             *s;
	Defect             *d1, *d2;
	SprintBacklogItem  *b;

public:
	ProjectBL();
	~ProjectBL();
	void makeLocalProject(void);
	void makeRemoteProject(void);
	void readLocalProject(void);
	void readRemoteProject(void);
};

#endif