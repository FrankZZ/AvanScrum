#include "WorkItemSorter.h"

WorkItemSorter::WorkItemSorter()
{
	wiv = new WorkItemVisitor();
}

WorkItemSorter::~WorkItemSorter()
{
	delete wiv;
}

void WorkItemSorter::sort(std::vector<WorkItem*> WorkItemList)
{
	wiv->clearAllResults();
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
	return wiv->getProductBacklogItems();
}

std::vector<SprintBacklogItem*> WorkItemSorter::getSprintBacklogItems()
{
	return wiv->getSprintBacklogItems();
}

std::vector<Defect*> WorkItemSorter::getDefects()
{
	return wiv->getDefects();
}