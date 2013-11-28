#ifndef ProjectBL_h
#define ProjectBL_h

class ProjectBL
{
private:
	CString            sText;
	std::string        name    = "Mtest";
	Sprint             *s;
	Defect             *d1, *d2;
	SprintBacklogItem*  b;

public:
	ProjectBL();
	~ProjectBL();
	void makeLocalProject(void);
	void makeRemoteProject(void);
	void readLocalProject(void);
	void readRemoteProject(void);
};

#endif