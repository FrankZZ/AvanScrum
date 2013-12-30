#include "TFS\WorkItem.h"
#include "TFS\ProductBacklogItem.h"
#include "TFS\SprintBacklogItem.h"
#include "WorkItemVisitor.h"
#include <vector>

class WorkItemSorter : public TFSVisitor
{
private:
	std::vector<ProductBacklogItem*> pbiResult;
	std::vector<SprintBacklogItem*> sbiResult;
	std::vector<Defect*> defResult;
	WorkItemVisitor* wiv;

public:
	WorkItemSorter();
	~WorkItemSorter();
	void sort(std::vector<WorkItem*>);
	std::vector<ProductBacklogItem*> getProductBacklogItems();
	std::vector<SprintBacklogItem*> getSprintBacklogItems();
	std::vector<Defect*> getDefects();
	void clearAllResults();
};