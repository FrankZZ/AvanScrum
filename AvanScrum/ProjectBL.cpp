#include "ProjectBL.h"
#include "TFS\Project.h"
#include "TFS\Sprint.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\TFSTransaction.h"
#include "TFS\User.h"
#include "TFS\Status.h"
#include "TFS\StatusType.h"

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
		std::string name = "Project Groep E";

        Project*                    p               = Project::withName( name.c_str() );
        Sprint*                     s1              = new Sprint;
        Sprint*                     s2              = new Sprint;
        Sprint*                     s3              = new Sprint;
        User*                       Frank           = User::withName( "Frank" );
        User*                       Maurits         = User::withName( "Maurits" );
        User*                       Bram            = User::withName( "Bram" );
        User*                       Jim             = User::withName( "Jim" );
        User*                       WillemJan		= User::withName( "Willem-Jan" );
        SprintBacklogItem*			b1              = new SprintBacklogItem;
        SprintBacklogItem*			b2              = new SprintBacklogItem;
        SprintBacklogItem*			b3              = new SprintBacklogItem;
        SprintBacklogItem*			b4              = new SprintBacklogItem;
        SprintBacklogItem*			b5              = new SprintBacklogItem;
        SprintBacklogItem*			b6              = new SprintBacklogItem;
        SprintBacklogItem*			b7              = new SprintBacklogItem;
        Defect*                     d1              = new Defect;
        Defect*                     d2              = new Defect;
		StatusType*					st_ToDo			= StatusType::withName("ToDo");
		StatusType*					st_Doing		= StatusType::withName("Doing");
		StatusType*					st_Verify		= StatusType::withName("ToVerify");
		Status*						s_ToDo			= new Status;
		Status*						s_Doing			= new Status;
		Status*						s_Verify		= new Status;

        #pragma region Gegevens WorkItems
        b1->setTitle( "WorkItem1" );
        b2->setTitle( "WorkItem2" );
        b3->setTitle( "WorkItem3" );
        b4->setTitle( "WorkItem4" );
        b5->setTitle( "WorkItem5" );
        b6->setTitle( "WorkItem6" );
        b7->setTitle( "WorkItem7" );
        d1->setTitle( "Defect1" );
        d2->setTitle( "Defect2" );
        b1->setWorkItemNumber(1001);
        b2->setWorkItemNumber(1002);
        b3->setWorkItemNumber(1003);
        b4->setWorkItemNumber(1004);
        b5->setWorkItemNumber(1005);
        b6->setWorkItemNumber(1006);
        b7->setWorkItemNumber(1007);
        d1->setWorkItemNumber(2001);
        d2->setWorkItemNumber(2002);
        b1->setUser(WillemJan);
        b2->setUser(Frank);
        b3->setUser(Bram);
        b4->setUser(Maurits);
        b5->setUser(Jim);
        b6->setUser(Frank);
        b7->setUser(Jim);
        d1->setUser(Maurits);
        d2->setUser(Frank);
        b1->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b2->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b3->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b4->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b5->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b6->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b7->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        d1->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        d2->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b1->setRemainingWork(20.0);
        b2->setRemainingWork(30.0);
        b3->setRemainingWork(22.0);
        b4->setRemainingWork(11.0);
        b5->setRemainingWork(26.0);
        b6->setRemainingWork(68.0);
        b7->setRemainingWork(8.0);
		s_ToDo->setStatusType(*st_ToDo);
		s_Doing->setStatusType(*st_Doing);
		s_Verify->setStatusType(*st_Verify);
		b1->addStatus(*s_ToDo);
		b2->addStatus(*s_Doing);
		b3->addStatus(*s_ToDo);
		b4->addStatus(*s_ToDo);
		b5->addStatus(*s_Doing);
		b6->addStatus(*s_Doing);
		b7->addStatus(*s_Verify);
        #pragma endregion

	s1->setName( "Sprint 1" );
        s2->setName( "Sprint 2" );
        s3->setName( "Sprint 3" );

        s1->addWorkItem( *b1 );
        s1->addWorkItem( *b2 );
	s1->addWorkItem( *d1 );
	s1->addWorkItem( *d2 );
        s2->addWorkItem( *b3 );
        s2->addWorkItem( *b4 );
        s2->addWorkItem( *b5 );
        s3->addWorkItem( *b6 );
        s3->addWorkItem( *b7 );
	
        #pragma region SprintDates
        s1->setBeginDay(11);
        s1->setBeginMonth(11);
        s1->setBeginYear(2013);
        s1->setEndDay(24);
        s1->setEndMonth(11);
        s1->setEndYear(2013);

        s2->setBeginDay(25);
        s2->setBeginMonth(11);
        s2->setBeginYear(2013);
        s2->setEndDay(8);
        s2->setEndMonth(12);
        s2->setEndYear(2013);
        
        s3->setBeginDay(9);
        s3->setBeginMonth(12);
        s3->setBeginYear(2013);
        s3->setEndDay(22);
        s3->setEndMonth(12);
        s3->setEndYear(2013);
        #pragma endregion

        p->addSprint( *s1 );
        p->addSprint( *s2 );
        p->addSprint( *s3 );
	TFSTransaction::localWriteProject( name.c_str() );
}

// code for making a remote demo project
// not much changes are done; we won't be rewarded for this part of the code
void ProjectBL::makeRemoteDemoProject()
{
	/*std::string name    = "Mtest";

	Project*			p       = Project::withName( name.c_str() );
	Sprint*				s       = new Sprint;
	Defect*				d1      = new Defect;
	Defect*				d2      = new Defect;
	SprintBacklogItem*	b       = new SprintBacklogItem;

	User::withName( "Frans" );
	User::withName( "Henk" );

	s->setName( "sprint 2" );

	s->addWorkItem( *b );
	s->addWorkItem( *d1 );
	s->addWorkItem( *d2 );
	
	p->addSprint( *s );*/

	
		std::string name = "Project Groep E";

        Project*                    p               = Project::withName( name.c_str() );
        Sprint*                     s1              = new Sprint;
        Sprint*                     s2              = new Sprint;
        Sprint*                     s3              = new Sprint;
        User*                       Frank           = User::withName( "Frank" );
        User*                       Maurits         = User::withName( "Maurits" );
        User*                       Bram            = User::withName( "Bram" );
        User*                       Jim             = User::withName( "Jim" );
        User*                       WillemJan		= User::withName( "Willem-Jan" );
        SprintBacklogItem*			b1              = new SprintBacklogItem;
        SprintBacklogItem*			b2              = new SprintBacklogItem;
        SprintBacklogItem*			b3              = new SprintBacklogItem;
        SprintBacklogItem*			b4              = new SprintBacklogItem;
        SprintBacklogItem*			b5              = new SprintBacklogItem;
        SprintBacklogItem*			b6              = new SprintBacklogItem;
        SprintBacklogItem*			b7              = new SprintBacklogItem;
        Defect*                     d1              = new Defect;
        Defect*                     d2              = new Defect;
		StatusType*					st_ToDo			= StatusType::withName("ToDo");
		StatusType*					st_Doing		= StatusType::withName("Doing");
		StatusType*					st_Verify		= StatusType::withName("ToVerify");
		Status*						s_ToDo			= new Status;
		Status*						s_Doing			= new Status;
		Status*						s_Verify		= new Status;

        #pragma region Gegevens WorkItems
        b1->setTitle( "WorkItem1" );
        b2->setTitle( "WorkItem2" );
        b3->setTitle( "WorkItem3" );
        b4->setTitle( "WorkItem4" );
        b5->setTitle( "WorkItem5" );
        b6->setTitle( "WorkItem6" );
        b7->setTitle( "WorkItem7" );
        d1->setTitle( "Defect1" );
        d2->setTitle( "Defect2" );
        b1->setWorkItemNumber(1001);
        b2->setWorkItemNumber(1002);
        b3->setWorkItemNumber(1003);
        b4->setWorkItemNumber(1004);
        b5->setWorkItemNumber(1005);
        b6->setWorkItemNumber(1006);
        b7->setWorkItemNumber(1007);
        d1->setWorkItemNumber(2001);
        d2->setWorkItemNumber(2002);
        b1->setUser(WillemJan);
        b2->setUser(Frank);
        b3->setUser(Bram);
        b4->setUser(Maurits);
        b5->setUser(Jim);
        b6->setUser(Frank);
        b7->setUser(Jim);
        d1->setUser(Maurits);
        d2->setUser(Frank);
        b1->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b2->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b3->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b4->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b5->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b6->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b7->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        d1->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        d2->setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam posuere lacus turpis. Donec non fermentum metus. Proin ullamcorper eros et risus semper, quis convallis lorem fringilla. Etiam vel magna diam. Ut nec aliquam orci, at dapibus diam. Morbi dignissim ullamcorper turpis a posuere.");
        b1->setRemainingWork(20.0);
        b2->setRemainingWork(30.0);
        b3->setRemainingWork(22.0);
        b4->setRemainingWork(11.0);
        b5->setRemainingWork(26.0);
        b6->setRemainingWork(68.0);
        b7->setRemainingWork(8.0);
		s_ToDo->setStatusType(*st_ToDo);
		s_Doing->setStatusType(*st_Doing);
		s_Verify->setStatusType(*st_Verify);
		b1->addStatus(*s_ToDo);
		b2->addStatus(*s_Doing);
		b3->addStatus(*s_ToDo);
		b4->addStatus(*s_ToDo);
		b5->addStatus(*s_Doing);
		b6->addStatus(*s_Doing);
		b7->addStatus(*s_Verify);
        #pragma endregion

        s1->setName( "Sprint 1" );
        s2->setName( "Sprint 2" );
        s3->setName( "Sprint 3" );

        s1->addWorkItem( *b1 );
        s1->addWorkItem( *b2 );
        s1->addWorkItem( *d1 );
        s1->addWorkItem( *d2 );
        s2->addWorkItem( *b3 );
        s2->addWorkItem( *b4 );
        s2->addWorkItem( *b5 );
        s3->addWorkItem( *b6 );
        s3->addWorkItem( *b7 );

        #pragma region SprintDates
        s1->setBeginDay(11);
        s1->setBeginMonth(11);
        s1->setBeginYear(2013);
        s1->setEndDay(24);
        s1->setEndMonth(11);
        s1->setEndYear(2013);

        s2->setBeginDay(25);
        s2->setBeginMonth(11);
        s2->setBeginYear(2013);
        s2->setEndDay(8);
        s2->setEndMonth(12);
        s2->setEndYear(2013);
        
        s3->setBeginDay(9);
        s3->setBeginMonth(12);
        s3->setBeginYear(2013);
        s3->setEndDay(22);
        s3->setEndMonth(12);
        s3->setEndYear(2013);
        #pragma endregion

        p->addSprint( *s1 );
        p->addSprint( *s2 );
        p->addSprint( *s3 );

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