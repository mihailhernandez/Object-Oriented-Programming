#include "CriteriaFactory.h"

Criteria* CriteriaFactory::create(const int identifier)
{
	switch (identifier)
	{
	case CriteriaIdentifiers::HOMEWORK_CRITERIA_IDENTIFIER:
		return new HomeworkCriteria();
	case CriteriaIdentifiers::EXAM_CRITERIA_IDENTIFIER:
		return new ExamCriteria();
	default:
		return nullptr;
	}
}