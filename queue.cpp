// This program enacts a QUEUE class with a double linked list
// Author: Jeff Golota
// Date: 3/30/2020
#include <iostream>
using namespace std;

struct node // This structure of each node
{
	int num;	// A single integer field (called num)
	node *up;	// A pointer to the node above in the queue
	node *down; // A pointer to the node below in the queue
};

class queue
{
public:
	node *top;	  // A pointer to the top of the queue
	node *bottom; // A pointer to the bottom of the queue
	int largest;  // Tracks the largest number in the queue
	int size;	  // Tracks the size of the queue
	bool empty;	  // Tracks if the queue is empty

	// Constructor
	queue()
	{
		// Fill in details setting the class variables to appropriate values
		largest = 0;
		size = 0;
		empty = true;
		top = new node;
		top->up = NULL;
		top->down = NULL;
		bottom = top;
	}

	// Methods
	void print() // DON'T CHANGE THIS FUNCTION AT ALL
	{
		if (empty == false)
		{
			node *temp = top;
			while (temp != NULL)
			{
				cout << temp->num << endl;
				temp = temp->down;
			}
			cout << "The size of the queue is: " << size << endl;
			cout << "The largest number in the queue is: " << largest << "\n\n";
		}
		else
			cout << "The queue is empty\n";
	}

	void enqueue() // prompt the user for a new value and enqueue it
	{
		node *temp;
		int addNum;
		cout << "Enter a number you would like added to the queue: \n";
		cin >> addNum;
		temp = bottom;
		if (empty == true)
		{
			top->num = addNum;
		}
		else
		{
			bottom->down = new node;
			bottom = bottom->down;
			bottom->down = NULL;
			bottom->up = temp;
			temp->down = bottom;
			bottom->num = addNum;
		}
		empty = false;
		++size;
		if (bottom->num > largest)
		{
			largest = bottom->num;
		}
	}

	void dequeue() // dequeue the next value and print it to the screen
	{
		node *temp;
		if (empty == true)
		{
			cout << "Cannot dequeue because the list is empty.\n";
		}
		else
		{
			if (size == 1)
			{
				cout << "Next value is " << top->num << endl;
				empty = true;
				delete top;
				top = new node;
				top->up = NULL;
				top->down = NULL;
				bottom = top;
				--size;
			}
			else
			{
				temp = top->down;
				cout << "Next value is " << top->num << endl;
				delete top;
				top = temp;
				top->up = NULL;
				--size;
			}
		}
	}

	bool isSorted() // checks if the queue is sorted, largest values on top
	{
		node *temp;
		if (top->num == largest)
		{
			temp = top->down;
			while (temp->down != NULL)
			{
				if (temp->num < temp->down->num)
				{
					return false;
				}
				temp = temp->down;
			}
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	queue list; // declares an instance of a queue, called list
	int choice;

	do
	{
		cout << "1. Print the queue, along with its size\n"
			 << "2. Enqueue\n"
			 << "3. Dequeue\n"
			 << "4. Check if it's sorted (top = biggest...)\n"
			 << "5. Quit\n\n"
			 << "What do you want to do: ";
		cin >> choice;

		if (choice == 1)
		{
			list.print();
		}
		else if (choice == 2)
		{
			list.enqueue();
		}
		else if (choice == 3)
		{
			list.dequeue();
		}
		else if (choice == 4)
		{
			if (!list.empty) // I'm sorry I edited the main just to include a cout for when the queue is empty
			{
				if (list.size == 1) {
					cout << "There is only one value in the queue so it cannot be sorted.\n";
				}
				else {
					if (list.isSorted() == true)
					{
						cout << "Your queue is sorted, with the highest value on top\n\n";
					}
					else
					{
						cout << "Your queue is not sorted\n\n";
					}
				}
			}
			else {
				cout << "The queue is empty\n";
			}
		}

	} while (choice != 5);

	return 0;
}
