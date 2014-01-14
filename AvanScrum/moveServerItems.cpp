#include "moveServerItems.h"


moveServerItems::moveServerItems(void)
{
}


moveServerItems::~moveServerItems(void)
{
}

void moveServerItems::moveWorkItemForward(WorkItem* item)
{
	QString t( typeid(*item).name());
	if (typeid(*item) == typeid(SprintBacklogItem)){
		SprintBacklogItem* sbi = dynamic_cast<SprintBacklogItem *>(item);
		moveSprintBacklogItemForward(sbi);
	}else if (typeid(*item) == typeid(Defect)){
		Defect* sbi = dynamic_cast<Defect *>(item);
		moveDefectItemForward(sbi);
	}else if (typeid(*item) == typeid(ProductBacklogItem)){
		ProductBacklogItem* sbi = dynamic_cast<ProductBacklogItem *>(item);
		moveProductBacklogItemForward(sbi);
	}
}

void moveServerItems::moveSprintBacklogItemForward(SprintBacklogItem* item)
{
	
	size_t s = item->sizeStatus()-1;
	Status* to = item->getStatus(s);
	item->addStatus(*getNextStatus(to));
}
void moveServerItems::moveDefectItemForward(Defect* item)
{
	Status* to;
	to = item->getStatus(item->getStatusArray().size()-1);
	item->addStatus(*getNextStatus(to));
}
void moveServerItems::moveProductBacklogItemForward(ProductBacklogItem* item)
{
	Status* to;
	to = item->getStatus(item->getSizeStatus()-1);
	item->addStatus(*getNextStatus(to));
}

void moveServerItems::moveWorkItemBack(WorkItem* item)
{
	if (typeid(item) == typeid(SprintBacklogItem)){
		SprintBacklogItem* sbi = dynamic_cast<SprintBacklogItem *>(item);
		moveSprintBacklogItemBack(sbi);
	}else if (typeid(item) == typeid(Defect)){
		Defect* sbi = dynamic_cast<Defect *>(item);
		moveDefectItemBack(sbi);
	}else if (typeid(item) == typeid(ProductBacklogItem)){
		ProductBacklogItem* sbi = dynamic_cast<ProductBacklogItem *>(item);
		moveProductBacklogItemBack(sbi);
	}
}

void moveServerItems::moveSprintBacklogItemBack(SprintBacklogItem* item)
{
	item->removeStatusAt(item->sizeStatus()-1);
}
void moveServerItems::moveDefectItemBack(Defect* item)
{
	item->removeStatusAt(item->getStatusArray().size() -1);
}
void moveServerItems::moveProductBacklogItemBack(ProductBacklogItem* item)
{
	item->removeStatusAt(item->getSizeStatus()-1);
}

Status* moveServerItems::getNextStatus(Status* s)
{
	if(s != NULL)
	{
		std::string name = s->getStatusType()->getName();
		if(name ==  "ToDo")
		{	
			Status*	_s	= new Status;
			s->setStatusType(*StatusType::withName("Doing"));
			return s;
		}
	
		else if(name == "Doing")
		{	
			Status*	_s	= new Status;
			s->setStatusType(*StatusType::withName("Verify"));
			return s;
		}
	
		else if(name == "Verify")
		{	
			Status*	_s	= new Status;
			s->setStatusType(*StatusType::withName("Done"));
			return s;
		}
	
		else if(name == "Done")
		{	
			Status*	_s	= new Status;
			s->setStatusType(*StatusType::withName("Done"));
			return s;
		}

		int b = 10;
	}
	return s;
}

