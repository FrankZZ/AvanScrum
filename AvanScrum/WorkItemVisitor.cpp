#include "WorkItemVisitor.h"

WorkItemVisitor::WorkItemVisitor() : TFSVisitor()
{

}

WorkItemVisitor::~WorkItemVisitor()
{

}

void WorkItemVisitor::visit( ProductBacklogItem& pbi)
{
	pbiResult.push_back(&pbi);
}

void WorkItemVisitor::visit( SprintBacklogItem& sbi)
{
	sbiResult.push_back(&sbi);
}

void WorkItemVisitor::visit( Defect& def)
{
	defResult.push_back(&def);
}

std::vector<ProductBacklogItem*> WorkItemVisitor::getProductBacklogItems()
{
	return pbiResult;
}

std::vector<SprintBacklogItem*> WorkItemVisitor::getSprintBacklogItems()
{
	return sbiResult;
}

std::vector<Defect*> WorkItemVisitor::getDefects()
{
	return defResult;
}

void WorkItemVisitor::clearAllResults()
{
	pbiResult.clear();
	sbiResult.clear();
	defResult.clear();
}