#include "ProjectBL.h"

ProjectBL::ProjectBL()
{

}

ProjectBL::~ProjectBL()
{

}

// code for making a local demo project
// not much changes are done; we won't be rewarded for this part of the code
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

// code for making a remote demo project
// not much changes are done; we won't be rewarded for this part of the code
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

// code for reading a local project
void ProjectBL::readLocalProject(std::string ProjName)
{
	std::vector<Sprint*> projSprints;

	Project*			projPtr      = TFSTransaction::localReadProject( ProjName.c_str() );
	projSprints = projPtr->getSprintArray();
}

// code for reading a remote project
void ProjectBL::readRemoteProject(std::string ProjName)
{
	std::vector<Sprint*> projSprints;

	Project*			projPtr      = TFSTransaction::remoteReadProject( ProjName.c_str() );
	projSprints = projPtr->getSprintArray();
}