#pragma once

#include "Item.h"

class Task : public Item
{
public:
	Task(void);
	~Task(void);

	enum StatusType { InProgress, NotStarted, Canceled, Completed, Holding, Waiting, Pledge };

	virtual Item::Type getType() { return Item::Task; }
	virtual DateTimeType getDateForDisplay() { return completedDate_; }
	virtual std::tstring getTitle() { return title_; }
	virtual std::tstring getContents() { return description_; }

	void setTitle(const std::tstring& title) { title_ = title; }
	void setContents(const std::tstring& contents) { description_ = contents; }
	void setStatus(StatusType status) { status_ = status; }
	StatusType getStatus() { return status_; }
	int getProgress() { return progress_; }
	void setProgress(int progress) { progress_ = progress; }

private:
	std::tstring title_;
	std::tstring description_;

	int progress_;
	StatusType status_;

	DateTimeType completedDate_;
	DateTimeType startDate_;
	DateTimeType plannedDate_;

	std::vector<int> dependency_;
	int parentIdx_;
};
