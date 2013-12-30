#include "WorkItemSorter.h"

WorkItemSorter::WorkItemSorter()
{
	wiv = new WorkItemVisitor();
	wiv->clearAllResults();
}

WorkItemSorter::~WorkItemSorter()
{
	delete wiv;
}

void WorkItemSorter::sort(std::vector<WorkItem*> WorkItemList)
{
	for (int i = 0; i < WorkItemList.size(); i++)
	{
		if(WorkItemList.at(i) != NULL)
		{
			WorkItemList.at(i)->accept(*wiv);
		}
	}
}

std::vector<ProductBacklogItem*> WorkItemSorter::getProductBacklogItems()
{
	return pbiResult;
}

std::vector<SprintBacklogItem*> WorkItemSorter::getSprintBacklogItems()
{
	return sbiResult;
}

std::vector<Defect*> WorkItemSorter::getDefects()
{
	return defResult;
}

void WorkItemSorter::clearAllResults()
{
	pbiResult.clear();
	sbiResult.clear();
	defResult.clear();
	wiv->clearAllResults();
}