// This program does some basic functionalities of using a linked list

#include<iostream>
using namespace std;
/* Author: Jeff Golota
Date Due: 3-2-2020 
This program will create a linked list and perform actions from a menu onto the linked list */

struct node				// This structure of each node
{
	int num;			// A single integer field (called num)
	node * next;		// A pointer to the next node in the list
};

void print(node * first);

//This function performs option 2 and calculates the average, the largest, and the amount of nodes
void option2(struct node * first, int& count, int& average, int& largest) {
	node * temp;
	count = 0;
	average = 0;
	largest = 0;
	temp = first;
	do {
		if ((temp -> num) > largest) {
			largest = temp -> num;
		}
		average += temp -> num;
		temp = temp -> next;
		count++;
	} while (temp != NULL);
	average = average / count;
}
//This function performs menu option 3 and it adds a new node to the beginning of the list
void option3(struct node *& first) {
	node*temp;
	temp = first;
	first = new node;
	cout << "Enter a number you want to add to the beginning: ";
	cin >> first -> num;
	first -> next = temp;
}
//This function performs option 4 on the menu and it deletes the first node in the list
void option4(struct node*& first) {
	node* temp;
	temp = first;
	temp = temp -> next;
	delete first;
	first = temp;
}

int main()
{
// Variable definitions
	node * first;				// Pointer to the first node in the list
	node * last;				// Pointer to the last node in the list
	char more_nodes = 'y';		// Control to know if the user wants to enter more
	int choice;

// Creates the first node
	first = new node;			// Create the first node
	cout << "What's the first number: ";
	cin >> first -> num;		// Put data in it
	first -> next = NULL;		// Point it to NULL (since it's the end)
	last = first;				// Point last to it (since it's the end)


// This loop adds one new node, loads data into it, and updates pointers	
	while(more_nodes == 'y')		
	{
		last -> next = new node;	// Get a new node tacked onto the end of the list
		last = last -> next;		// Toggle last to point to this new node (since it's the new "last")
		cout << "What value do you want to put in the new box: ";
		cin >> last -> num;			// Put the data from the user into the new node
		last -> next = NULL;		// Point the new node to NULL
		
		print(first);

		cout << "Do you have more numbers to enter? ";
		cin >> more_nodes;
	}

	//This loop controls the menu options and then calls the functions based on what the user chooses
	do 
	{
		cout << "1. Print the list\n"
		     << "2. Print a report of largest, size and average values\n"
		     << "3. Prepend (add) a node to the beginning of the list\n"
			 << "4. Delete the first node\n"
		     << "5. Quit\n\n"
		     << "What do you want to do: ";
		cin >> choice;

		if (choice == 1)
		{
			print(first);
		}

		else if (choice == 2)
		{
			node*temp;
			int count = 0;
			int average = 0;
			int largest = 0;
			temp = first;
			option2(first,count,average,largest);
			cout << "Largest value: " << largest << endl;
			cout << "Average value: " << average << endl;
			cout << "# of Nodes: " << count << endl;
		}
		else if (choice == 3)
		{
			option3(first);
			print(first);
		}	
		else if (choice == 4)
		{
			option4(first);
			print(first);
		}	
	} while (choice != 5);
	
return 0;
}

void print(node * first)
{
	// Print out the linked list by having a temporary pointer scroll through the entire list
	node * temp;				// Make a temporary (dummy) pointer
	temp = first;				// Point it to the first node in the list
	
	while(temp != NULL)		// Continue until temp reaches NULL (the end)
	{
		cout << temp -> num;		// Print out temp's number
		temp = temp -> next;
		if (temp != NULL) {
			cout << " -> ";
		}				// Move temp to the next node
	}
    cout << endl << endl;
}