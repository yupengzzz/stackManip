/**
* @file stackM.cpp
* @author Yupeng Zhao
* @Date 2018-06-27
* @version 1.0
* @section DESCRIPTION:
	This program uses a linked list to define stack elements and
uses class for stack manipulation. The size of the stack is
determined by the user as an input. Two exceptions for manipulating
class are pushing data into a full class, and popping data from an
empty class.
*/


#include<iostream>
#include<string>

using namespace std;

struct Node
{
	char a;
	Node* next;
};
typedef Node* NodePtr;

class Stack
{
public:
	Stack();
	Stack(int a);

	int getMaxSize();
	int getCurrentSize();
	void dispStack();

	void pushNext(char c);
	// Insert the new node at the head
	char popNext();
	// Remove and return a node from the head

private:
	int size;
	// Input size for stack
	int currentSize;
	// Current size for stack
	NodePtr head;
	// Head pointer for stack
};

class StackOverflowException
{
public:
	StackOverflowException(string a);
	string getMessageE();
private:
	string messageE;
};

class StackEmptyException
{
public:
	StackEmptyException(string a);
	string getMessageE();
private:
	string messageE;
};


int main()
{
	Stack stack1;
	int size = 0;
	// int currentSize = 0;
	char ans = '\0';
	bool loopCond = false;
	char pushChar = '\0';
	char poppedChar = '\0';

	cout << "Enter the size of the stack: ";
	cin >> size;
	if(cin.fail())
	{
		cerr << "Error: Wrong entry type." << endl
			<< "Terminating program." << endl;
		exit(1);
 	}
	else if(size < 0)
	{
		cerr << "Error: Stack size cannot be negative." << endl
			<< "Terminating program." << endl;
		exit(1);
	}
	cin.ignore(100, '\n');

	stack1 = Stack(size);

	do
	{
		cout << "Press '1' to push a new element into the stack." << endl
			<< "Press '2' to pop an element from the stack." << endl
			<< "Press '3' to exit." << endl;
		cin >> ans;

		try
		{
			switch(ans)
			{
			case '1':
				cout << "Enter character to be pushed in: ";
				cin >> pushChar;
				cin.ignore(100, '\n');
				stack1.pushNext(pushChar);
				loopCond = true;
				break;

			case '2':
				poppedChar = stack1.popNext();
				cout << "Character '" << poppedChar << "' has been popped out." << endl;
				loopCond = true;
				break;

			case '3':
				cout << "Exiting simulation." << endl;
				loopCond = false;
				break;

			default:
				cout << "Your entry could not be recognized." << endl
					<< "Try agian." << endl;
				loopCond = true;
			}

			cout << "Max stack size " << stack1.getMaxSize()
				<< ", current stack size " << stack1.getCurrentSize() << endl;
			cout << "The current stack is ";
			stack1.dispStack();
			cout << endl << endl;

		}
		catch(StackOverflowException e)
		{
			cout << e.getMessageE() << endl;
			cout << "Ending silumation." << endl;
			loopCond = false;
		}
		catch(StackEmptyException e)
		{
			cout << e.getMessageE() << endl;
			cout << "Ending simulatoin." << endl;
			loopCond = false;
		}

	}while(loopCond);

	return 0;
}

Stack::Stack()
{
	size = 0;
	currentSize = 0;
	head = nullptr;
}

Stack::Stack(int a)
{
	size = a;
	currentSize = 0;
	head = nullptr;
}

int Stack::getMaxSize()
{
	return(size);
}

int Stack::getCurrentSize()
{
	return(currentSize);
}

void Stack::dispStack()
{
	NodePtr temp = head;
	while(temp != nullptr)
	{
		cout << temp->a << " ";
		temp = temp->next;
	}
}

void Stack::pushNext(char c)
{
	if(currentSize >= size)
	{
		throw StackOverflowException("Error: Stack is full.");
	}

	NodePtr temp;
	temp = new Node;
	temp->a = c;
	temp->next = head;
	head = temp;

	currentSize++;
}

char Stack::popNext()
{
	if(currentSize <= 0)
	{
		throw StackEmptyException("Error: Stack is empty.");
	}

	char c;
	NodePtr temp;
	temp = head;
	c = head->a;
	head = head->next;
	delete temp;

	currentSize--;
	return(c);
}

StackOverflowException::StackOverflowException(string a)
{
	messageE = a;
}

string StackOverflowException::getMessageE()
{
	return messageE;
}

StackEmptyException::StackEmptyException(string a)
{
	messageE = a;
}

string StackEmptyException::getMessageE()
{
	return messageE;
}
