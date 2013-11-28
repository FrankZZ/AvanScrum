#include "ProjectBL.h"

#include <atlstr.h>

#include "TFS\Project.h"
#include "TFS\Sprint.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\TFSTransaction.h"
#include "TFS\User.h"

void ProjectBL::makeLocalProject()
{
	name    = "Mtest";

	Project            *p;

	p       = Project::withName( name.c_str() );
	s       = new Sprint;
	d1      = new Defect;
	d2      = new Defect;
	b       = new SprintBacklogItem;

	User::withName( "Frans" );
	User::withName( "Henk" );

	p->addSprint( *s );
	s->setName( "sprint 2" );

	s->addWorkItem( *b );
	s->addWorkItem( *d1 );
	s->addWorkItem( *d2 );

	TFSTransaction::localWriteProject( name.c_str() );
}

void ProjectBL::makeRemoteProject()
{
	name    = "Mtest";

	Project            *p;

	p       = Project::withName( name.c_str() );
	s       = new Sprint;
	d1      = new Defect;
	d2      = new Defect;
	b       = new SprintBacklogItem;

	User::withName( "Frans" );
	User::withName( "Henk" );

	p->addSprint( *s );
	s->setName( "sprint 2" );

	s->addWorkItem( *b );
	s->addWorkItem( *d1 );
	s->addWorkItem( *d2 );

	TFSTransaction::remoteWriteProject( name.c_str() );
}

void ProjectBL::readLocalProject()
{
	Project            *p2      = TFSTransaction::localReadProject( name.c_str() );
    s   = p2->getSprint( 0 );
    b   = dynamic_cast<SprintBacklogItem*>( s->getWorkItem(0) );
    d1  = dynamic_cast<Defect*>           ( s->getWorkItem(1) );
    d2  = dynamic_cast<Defect*>           ( s->getWorkItem(2) );

    sText = CString("Frans ") + CString(User::isPresent("Frans")?"exists and " : "does not exist and ") +
            CString("Henk ")  + CString(User::isPresent("Henk") ?"exists " : "does not exist");
}

void ProjectBL::readRemoteProject()
{
	Project            *p2      = TFSTransaction::remoteReadProject( name.c_str() );
    s   = p2->getSprint( 0 );
    b   = dynamic_cast<SprintBacklogItem*>( s->getWorkItem(0) );
    d1  = dynamic_cast<Defect*>           ( s->getWorkItem(1) );
    d2  = dynamic_cast<Defect*>           ( s->getWorkItem(2) );

    sText = CString("Frans ") + CString(User::isPresent("Frans")?"exists and " : "does not exist and ") +
            CString("Henk ")  + CString(User::isPresent("Henk") ?"exists " : "does not exist");
}