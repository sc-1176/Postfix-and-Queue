#include <iostream>
#include "Queue.h"
#include <iomanip>
#include <string>

using namespace std;

void Queue::queue() 						//initializer class
{
	head = NULL;
	tail = NULL;
	queueLength = 0;
}

void Queue::enqueue(int data) 				//adds integer data to the end of the queue
{
	node* temp = new node;					//creating nodes for the list
	temp->item = data;						//adding data to the node
	temp->next = NULL;						//adding node to the end of the list (queue)
	if (head == NULL) {						//if there is no current head, declare the node to be the head
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else {									//if there is a current head, add the node to the tail end of the queue
		tail->next = temp;
		tail = temp;
	}
	queueLength += 1;						//note that the queue has been increased by one
}

void Queue::dequeue() 						//deletes the value at the front of the queue after displaying it
{
	node* temp = new node;					//creating node for the list
	temp = head;							//start at the front of the list
	if (head == NULL) {						//if the list is empty, tell the user the queue is empty
		cout << "This queue is empty. There is nothing to delete." << endl;
	}
	else {									//if the list is not empty, delete the head node
		cout << "The value of the first item is:" << "\t" << head->item << endl;

		head = head->next;					//make the next node in the queue the new head
		delete temp;
		queueLength -= 1;					//note that the queue has been decreased by one
	}
}

void Queue::returnFront() 					//returns the value at the front of the queue
{
	node* temp = new node;					//create a node for the list
	temp = head;							//set the node to the head
											//return the value at the head of the list
	cout << "The item at the front of the list is:" << '\t' << temp->item << endl;
}

bool Queue::isEmpty() 						//checks to see if the queue is empty
{
	if (queueLength == 0) {					//if the queue has a length of 0, inform the user that the queue is empty
		cout << "This queue is empty." << endl;
		return true;
	}
	else if (queueLength > 0) {				//if the queue has a length greater than 0, inform the user that the queue is not empty
		cout << "This queue is not empty." << endl;
		return false;
	}
	else {									//if the queue somehow has a lenght less than 0, question the user
		cout << "How did you even manage this?	" << queueLength << endl;
		return false;
	}
}

int Queue::lengthOfQueue() 					//returns the length of the queue
{
	cout << "Queue Length:" << "\t" << queueLength << endl;
	return queueLength;
}

void Queue::display() 						//displays the queue
{
	node* temp = new node;					//create a node for iteration
	temp = head;							//start at the head of the queue
	while (temp != NULL)					//while the node is not yet at the end of the queue, display the values of the queue's nodes
	{
		cout << temp->item << "\t";
		if (temp->next == NULL) {
			cout << endl;
		}
		temp = temp->next;					//iterate to the next node	
	}
}