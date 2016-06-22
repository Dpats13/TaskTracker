#include "TaskList.h"
#include <iostream>
#include <string>

using namespace std;

void addTask(TaskList &toDoList, string task) {
	toDoList.pushBack(task);
	cout << task << ", has been added to your to do list! " << endl << endl;;
}

void removeTask(TaskList &toDoList) {
	cout << toDoList.pop();
	cout << " has been removed from your to do list!" << endl << endl;
}

void displayTasks(TaskList &toDoList) {
	toDoList.traverseList();
}

void completeTask(TaskList &toDoList) {
	if (!toDoList.isEmpty()) { //Making sure at least one task is in the list to complete
		cout << toDoList.pop();
		cout << " has been completed!" << endl;
		toDoList.addPoints();
	}
	else {
		cout << "There is nothing on your list to complete!" << endl;
	}
}

int main() {

	TaskList list;
	char cont = ' '; //variable to continue using system or not
	cout << "Welcome to Task Tracker Version 1!" << endl;
	while (cont != 'Q') {
		string task = " "; //Task to be added
		cout << "Please enter what you would like to do (A: to add task), (R: to remove task), (D: to display list), (C: to show task was completed) and (Q: to quit): " << endl;
		cin >> cont;
		switch(cont) {
			case 'A':
				cout << "Enter task you wish to add to your to do list: " << endl;
				cin.ignore();
				getline(cin, task);
				addTask(list, task);
				break;
			case 'R':
				removeTask(list);
				break;
			case 'D':
				displayTasks(list);
				break;
			case 'C':
				completeTask(list);
				break;
			case 'Q':
				cout << "Shutting down" << endl;
				break;
			default:
				cout << "That is not a recognized command please try again. ";
				break;
		}
	}
	return 0;
}


