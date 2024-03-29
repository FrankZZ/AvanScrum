#ifndef WorkItemVisitor_h
#define WorkItemVisitor_h

#include "TFS\TFSVisitor.h"
#include "TFS\WorkItem.h"
#include "TFS\ProductBacklogItem.h"
#include "TFS\SprintBacklogItem.h"

class WorkItemVisitor : public TFSVisitor
{
private:
	std::vector<ProductBacklogItem*> pbiResult;
	std::vector<SprintBacklogItem*> sbiResult;
	std::vector<Defect*> defResult;

public:
	WorkItemVisitor();
	~WorkItemVisitor();
	void visit( ProductBacklogItem& );
	void visit( SprintBacklogItem& );
	void visit( Defect& );
	std::vector<ProductBacklogItem*> getProductBacklogItems();
	std::vector<SprintBacklogItem*> getSprintBacklogItems();
	std::vector<Defect*> getDefects();
	void clearAllResults();
};

#endif