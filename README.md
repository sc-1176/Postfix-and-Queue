# Postfix-and-Queue
Postfix conversion implemented with a stack and a simple queue implemented with a single-linked list


As aforementioned, this is a dual-program with both a queue and a postfix function built in. They are not built using each other, they're two separate classes that happen to be in the same overarching file. 

# Queue

To start, we will discuss the Queue program, which is a queue implemented using a single-linked list. 
Specifics will be written into the comments of the original file, but here is what the program can do in very simple terms, with screenshots of the output and, when appropriate, the built in test code.

queue() - standard initialization class, outputs nothing

enqueue(int) - adds items to the end of the queue, operates with integer data but, with how the program is structured, this can easily be changed to include any value type
Please note, for enqueue and for the nodes in general, they only accept one value of input.
This function attaches any new nodes created exclusively to the end of the queue, there is no other addition function.

The queue built with the enqueue function in the test code:

![image](https://user-images.githubusercontent.com/124931156/232592660-250cee00-83d1-4f08-9f34-621c3a42499c.png)

![image](https://user-images.githubusercontent.com/124931156/232592739-91098be9-3b66-4d19-bad4-7cf845748ce9.png)

dequeue() - will delete the first element of the queue, also known as the item in the front of the queue.
Before deleting the element, deqeueu will return the element that used to be at the front of the queue.
This is the only deletion method implemented.

Deletion of items in the queue with the dequeue method:

![image](https://user-images.githubusercontent.com/124931156/232598193-2dc61f72-8837-4b55-a63d-cb0040c1f680.png)

![image](https://user-images.githubusercontent.com/124931156/232598233-e3e51c9b-3074-474c-9cff-d0a51fc2d7d0.png)

returnFront() - not in the test file provided because the test file was built at one in the morning, but functions as a way to return the current front of the queue without deleting anything.

Returning the front of the queue in-between deletion of items:

![image](https://user-images.githubusercontent.com/124931156/232598506-75f72363-6e82-4bfc-bce0-5127962f6248.png)

![image](https://user-images.githubusercontent.com/124931156/232598638-f67d3c46-d069-4f8f-9f79-2c411b019cd8.png)

isEmpty() - a bool function that returns whether or not the queue is empty by measuring the length of the single-linked list.

Example of the program checking to see whether the list is empty or not:

![image](https://user-images.githubusercontent.com/124931156/232600028-26458f8e-502a-4994-8744-6376971ff32a.png)

lengthOfQueue() - returns the current length of the queue. Examples can be found above, but will be posted here for reference.

![image](https://user-images.githubusercontent.com/124931156/232601351-e8b735bf-c159-432d-b021-b98481f45607.png)

# Postfix

Postfix is, as earlier described, an infix-to-postfix conversion program. It can check if the parentheses of an equation are balanced, establishes the priority of the operators used in the equation, and accepts all its input via a single cin prompt.
This cin prompt is then consequently stored in the class's private member functions so that the program utilizes as few prompts to run as possible. 
To run every function in Postfix, only 3 calls need to be made. Please note; this does not compute postfix using numbers, only letters.

priority(char) - determines the priority order of operators. Called specifically within convertPostfix() to determine the order of the items to be pushed or popped from the stack

An example of priority being called within the program:

![image](https://user-images.githubusercontent.com/124931156/232605551-3e70cb72-c0e6-4b54-a175-444db66330ae.png)

inputString() - gets user input to declare the infix string, technically the infix initialization function

Example of the input prompt, with "(a+b)" inputted for an example function

![image](https://user-images.githubusercontent.com/124931156/232605836-fc79e6e9-1350-4d87-9449-c6b05e397f27.png)

balancedBrackets() - this function verifies whether or not an infix expression's brackets are balanced correctly. It's a boolean function and stores its result in status, a private member variable, for use with the rest of the code. 
Status is displayed as a 1 for true and a 0 for false.

The following is an example of balanced brackets executing from within convertPostfix():

![image](https://user-images.githubusercontent.com/124931156/232607600-e4c444b1-a65b-4eae-a61a-ac4d87f56ead.png)

![image](https://user-images.githubusercontent.com/124931156/232607681-55ad1511-2df0-47f5-9e1f-975349c948b7.png)

convertPostfix() - postfix conversion function. Utilizes every other function in the list, barring display, to function properly. 
This function has two modes, a correctly input infix expression and one where the brackets of the infix expression are unbalanced, thus, invalid, meaning that the function will only fully execute after it has validated the infix expression using balancedBrackets().
Brackets are deleted from the equation upon successful runs

The following is the full output of convertPostfix() as displayed by the display() function, on multiple possible inputs - 

![image](https://user-images.githubusercontent.com/124931156/232607855-d6f8248c-7b25-4060-8444-927edb165a75.png)

![image](https://user-images.githubusercontent.com/124931156/232608015-9b503aee-645c-431e-82c5-c4e746435331.png)

![image](https://user-images.githubusercontent.com/124931156/232608143-0fba7041-abad-4371-97d0-83d822d44e24.png)

![image](https://user-images.githubusercontent.com/124931156/232608524-ca3de433-0b51-4c79-9f48-299513852eec.png)


For the postfix conversion, I am not an expert, there may be cases I have not accounted for. Things might possibly break if an exception is thrown in these unaccounted for cases that I do not know about. But the code runs, which is what matters. Thank you for reading.
