#include "ProjectBL.h"

void ProjectBL::makeLocalDemoProject()
{
	std::string name    = "Mtest";

	Project*			p       = Project::withName( name.c_str() );
	Sprint*				s       = new Sprint;
	Defect*				d1      = new Defect;
	Defect*				d2      = new Defect;
	SprintBacklogItem*	b       = new SprintBacklogItem;

	User::withName( "Frans" );
	User::withName( "Henk" );

	p->addSprint( *s );
	s->setName( "sprint 2" );

	s->addWorkItem( *b );
	s->addWorkItem( *d1 );
	s->addWorkItem( *d2 );

	TFSTransaction::localWriteProject( name.c_str() );
}

void ProjectBL::makeRemoteDemoProject()
{
	std::string name    = "Mtest";

	Project*			p       = Project::withName( name.c_str() );
	Sprint*				s       = new Sprint;
	Defect*				d1      = new Defect;
	Defect*				d2      = new Defect;
	SprintBacklogItem*	b       = new SprintBacklogItem;

	User::withName( "Frans" );
	User::withName( "Henk" );

	p->addSprint( *s );
	s->setName( "sprint 2" );

	s->addWorkItem( *b );
	s->addWorkItem( *d1 );
	s->addWorkItem( *d2 );

	TFSTransaction::remoteWriteProject( name.c_str() );
}

void ProjectBL::readLocalProject(std::string ProjName)
{
	std::vector<Sprint*> projSprints;

	Project*			projPtr      = TFSTransaction::localReadProject( ProjName.c_str() );
	for(int i = 0; i < projPtr->sizeSprints(); i++)
	{

	}
    Sprint*				s   = projPtr->getSprint( 0 );
    SprintBacklogItem*	b   = dynamic_cast<SprintBacklogItem*>( s->getWorkItem(0) );
    Defect*				d1  = dynamic_cast<Defect*>           ( s->getWorkItem(1) );
    Defect*				d2  = dynamic_cast<Defect*>           ( s->getWorkItem(2) );
}

void ProjectBL::readRemoteProject(std::string ProjName)
{

	CString            sText;
	Sprint             *s;
	Defect             *d1, *d2;
	SprintBacklogItem  *b;

	Project            *p2      = TFSTransaction::remoteReadProject( ProjName.c_str() );
    s   = p2->getSprint( 0 );
    b   = dynamic_cast<SprintBacklogItem*>( s->getWorkItem(0) );
    d1  = dynamic_cast<Defect*>           ( s->getWorkItem(1) );
    d2  = dynamic_cast<Defect*>           ( s->getWorkItem(2) );

    sText = CString("Frans ") + CString(User::isPresent("Frans")?"exists and " : "does not exist and ") +
            CString("Henk ")  + CString(User::isPresent("Henk") ?"exists " : "does not exist");
}