#ifndef __TODO_H__
#define __TODO_H__

#include "Item.h"

class Todo : public Item
{
public:
	Todo(void);
	~Todo(void);

	enum StateType { 
		StateInProgress, 
		StateNotStarted, 
		StateCanceled, 
		StateCompleted, 
		StateHolding, 
		StateWaiting, 
		StatePledge 
	};

	virtual Item::Type getType() { return Item::Todo; }
	virtual DateTimeType getDateForDisplay() { return completedDate_; }
	virtual std::string getTitle() { return title_; }
	virtual std::string getContents() { return description_; }

	void setTitle(const std::string& title) { title_ = title; }
	void setContents(const std::string& contents) { description_ = contents; }
	void setState(StateType status) { status_ = status; }
	StateType getState() { return status_; }
	int getProgress() { return progress_; }
	void setProgress(int progress) { progress_ = progress; }

private:
	std::string title_;
	std::string description_;

	int progress_;
	StateType status_;

	DateTimeType completedDate_;
	DateTimeType startDate_;
	DateTimeType plannedDate_;

	std::vector<int> dependency_;
	int parentIdx_;
};

#endif // __TODO_H__
