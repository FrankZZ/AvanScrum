#pragma once
#include "ui_avanscrum.h"
#include "TFS\Project.h"
#include "TFS\Sprint.h"
#include "TFS\Defect.h"
#include "TFS\SprintBacklogItem.h"
#include "TFS\ProductBacklogItem.h"
#include "TFS\TFSTransaction.h"
#include "TFS\User.h"
#include "TFS\Status.h"
#include "TFS\StatusType.h"
#include "TFS\RemainingWorkHistory.h"

class moveServerItems
{
public:
	moveServerItems(void);
	~moveServerItems(void);
	void moveWorkItemForward(WorkItem*);
	void moveSprintBacklogItemForward(SprintBacklogItem*);
	void moveDefectItemForward(Defect*);
	void moveProductBacklogItemForward(ProductBacklogItem*);

	void moveWorkItemBack(WorkItem*);
	void moveSprintBacklogItemBack(SprintBacklogItem*);
	void moveDefectItemBack(Defect*);
	void moveProductBacklogItemBack(ProductBacklogItem*);

	Status* getNextStatus(Status* s);
};

