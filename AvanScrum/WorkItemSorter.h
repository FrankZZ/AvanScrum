#ifndef WorkItemSorter_h
#define WorkItemSorter_h

#include "TFS\WorkItem.h"
#include "TFS\ProductBacklogItem.h"
#include "TFS\SprintBacklogItem.h"
#include "WorkItemVisitor.h"

class WorkItemSorter
{
private:
	WorkItemVisitor* wiv;

public:
	WorkItemSorter();
	~WorkItemSorter();
	void sort(std::vector<WorkItem*>);
	std::vector<ProductBacklogItem*> getProductBacklogItems();
	std::vector<SprintBacklogItem*> getSprintBacklogItems();
	std::vector<Defect*> getDefects();
};

#endif