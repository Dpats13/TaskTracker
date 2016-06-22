#include <string>
#include <string.h>
#include <iostream>

using namespace std;


class Task {
	friend class TaskList;
private:
	string toDo; //task to do
	Task* next;  //next pointer to point to next task in queue

public:
	Task(); //constructor
	
};

Task::Task() { //constructor definition
	toDo = " ";
	next = NULL;
}


class TaskList { //Queue of things to do
private:
	Task* head;
	Task* tail;
	int score; //points for completing a task

public:
	TaskList(); //constructor
	string pop();
	void pushBack(string task);
	void traverseList();
	int displayScore();
	void addPoints();
	bool isEmpty(); //Is anything in list?
};

TaskList::TaskList() { //constructor definition
	head = NULL;
	tail = NULL; 
	score = 0;
}

void TaskList::pushBack(string task) { //Adds a new task to the end of the queue
	Task *newTask = new Task;
	newTask->toDo = task;
	if (head == NULL) {
		head = newTask;
		tail = newTask;
	}
	else {
		tail->next = newTask;
		tail = newTask;
	}

}

string TaskList::pop() { //Returns a task to do from the queue in FIFO ordering
	string taskToDo = " ";
	string errorMessage = "There is nothing currently in the list!";
	Task* removal; //pointer to be deleted
	if (head == NULL) {
		return errorMessage;
	}
	else {
		taskToDo = head->toDo;
		removal = head;
		head = head->next;
		delete removal; //free up memory
		return taskToDo;
	}
	
}

void TaskList::traverseList() {
	Task *curr; //pointer to follow
	cout << "Currently on the ToDo List: " << endl;
	if (head == NULL) {
		cout << "There is nothing currently in your ToDo list! " << endl;
	}
	else {
		for (curr = head; curr != NULL; curr = curr->next) {
			cout << curr->toDo << endl;
		}
	}
}

void TaskList::addPoints() {
	score += 5;
	cout << "5 points have been added to your score for completing the task! Your total score now is " << displayScore() << "." << endl;
}

int TaskList::displayScore() {
	return score;
}

bool TaskList::isEmpty() {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}