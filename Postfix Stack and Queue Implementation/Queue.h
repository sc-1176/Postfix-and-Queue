#pragma once

/*
Queue class implemented using a single-linked list. Can do the following:
- add integer-based data to the end of the queue
- delete the value at the front of the queue and display the value that was deleted
- return the integer at the front of the queue
- check to see if the queue is empty
- return the current length of the queue
*/

using namespace std;

class Queue {
public:
	void queue();					//initializer class
	void enqueue(int newData);		//adds integer data to the end of the queue
	void dequeue();					//deletes the value at the front of the queue after displaying it
	void returnFront();				//returns the value at the front of the queue
	bool isEmpty();					//checks to see if the queue is empty
	int lengthOfQueue();			//returns the length of the queue
	void display();					//displays the queue

private:
	struct node {
		int item;
		node* next;
	};
	node* head;
	node* tail;
	int queueLength;
};