#include <iostream>
#include "Postfix.h"
#include "Queue.h"

using namespace std;

int main() {

	Queue testQueue;
	testQueue.queue();
	testQueue.isEmpty();
	testQueue.lengthOfQueue();

	testQueue.enqueue(1);
	testQueue.enqueue(2);
	testQueue.enqueue(3);
	testQueue.enqueue(4);
	testQueue.enqueue(5);
	testQueue.enqueue(6);
	testQueue.enqueue(7);

	testQueue.display();
	testQueue.isEmpty();
	testQueue.lengthOfQueue();

	testQueue.dequeue();
	testQueue.dequeue();
	testQueue.dequeue();

	testQueue.display();

	Postfix testString;

	testString.inputString();
	testString.convertPostfix();
	testString.display();

	return 0;
}