// This program manages a database in a linked list

#include <iostream>
#include <fstream>
using namespace std;

struct node				// FILL IN THE DATA PORTION
{
	string firstName, lastName;
	int id;
	node * next;		// A pointer to the next node in the list
};

void print(node * first)   // NEEDS A PRINT UPDATE
{
	// Print out the linked list by having a temporary pointer scroll through the entire list
	node * temp;				// Make a temporary (dummy) pointer
	temp = first;				// Point it to the first node in the list

	while(temp != NULL)			// Continue until temp reaches NULL (the end)
	{
		cout << temp -> firstName << " " << temp -> lastName << endl;
		cout << temp -> id << endl;						// PRINT OUT THE NAME AND ID
		temp = temp -> next;				// Move temp to the next node
	}
	cout << endl;
}			

void prepend(node * & first)
{
	node*temp;
	temp = first;
	first = new node;
	cout << "Enter a new student name: ";
	cin >> first -> firstName >> first -> lastName;
	cout << endl;
	cout << "Enter an id for the student: ";
	cin >> first -> id;
	first -> next = temp;
}

void append(node * & last)
{
	node*temp;
	temp = last;
	last = new node;
	cout << "Enter a new student name: ";
	cin >> last -> firstName >> last -> lastName;
	cout << endl;
	cout << "Enter an id for the student: ";
	cin >> last -> id;
	last -> next = NULL;
	temp -> next = last;
}

void remove(node * & first, int delNum)	// THINK ABOUT APPRORPIATE PARAMETERS
{
	node*temp;
	bool found = false;
	temp = first;
	while (temp != NULL) {
		if (temp -> id == delNum) {
			delete temp;
			found = true;
			break;
		}
		else {
			temp = temp -> next;
		}
	}
	if (!found) {
		cout << "Student ID not found\n";
	}

}

void sort(node * first)
{
	node*temp;
	node*end = NULL;
	int swapNum = 0;
	string swapFirst,swapLast;
	bool swap; 
	do {
		swap = false;
		temp = first;
		while (temp->next != end) {
			if(temp->id > temp->next->id){
				swapFirst = temp -> firstName;
				swapLast = temp -> lastName;
				swapNum = temp -> id;
				temp->firstName = temp->next->firstName;
				temp->id = temp->next->id;
				temp->lastName = temp->next->lastName;
				temp->next->firstName = swapFirst;
				temp->next->lastName = swapLast;
				temp->next->id = swapNum;
				swap = true;
			}
			temp = temp-> next;
		}
		end = temp;
	} while (swap);
}

int main()
{
// Variable definitions
	node * first;				// Pointer to the first node in the list
	node * last;				// Pointer to the last node in the list
	int choice;					// Menu choice
	ifstream input;
	int delNum;
// Create the first node
	first = new node;			// Create the first node
	last = first;				// Point last to it (since it's the end)

// OPEN THE FILE AND LOAD DATA INTO THE first NODE
	input.open("class_list.txt");
	input >> first -> lastName >> first -> firstName >> first -> id;

// LOOP THROUGH THE FILE AND LOAD THE REMAINING DATA INTO THE LIST
	while (!input.eof()) {
		last -> next = new node;
		last = last -> next;
		input >> last -> lastName >> last -> firstName >> last -> id;
		last -> next = NULL;
	}



	do
	{
		cout << "1. Print the list\n"
		     << "2. Prepend (add) a node to the beginning of the list\n"
		     << "3. Append (add) a node to the end of the list\n"
			 << "4. Delete a node by ID\n"
			 << "5. Sort the list by ID\n"
		     << "6. Quit\n\n"
		     << "What do you want to do: ";
		cin >> choice;

		if (choice == 1)
		{
			print(first);
		}
		else if (choice == 2)
		{
      		prepend(first);
			cout << "Here's your updated list\n";		
			print(first);
      	}		
		else if (choice == 3)
		{
      		append(last);
			cout << "Here's your updated list\n";		
			print(first);
      	}		
		else if (choice == 4)
		{
			cout << "Enter the id of the student that you want to remove from the list: ";
			cin >> delNum;
		    remove(first,delNum);
			cout << "Here's your updated list\n";		
			print(first);		
		}
		else if (choice == 5)
		{
		    sort(first);
			cout << "Here's your updated list\n";		
			print(first);			
		}
	} while (choice != 6);

	return 0;
}


