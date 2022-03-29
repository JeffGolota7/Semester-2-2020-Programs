// This program does some basic functionalities of using a DOUBLE linked list, like loading, printing and deleting

#include <iostream>
using namespace std;
/* Doubly Linked List Program
Author: Jeff Golota
Date: 3-13-2020 */

struct node				// This structure of each node
{
	int num;			// A single integer field (called num)
	node * next;		// A pointer to the next node in the list
	node * prev;		// A pointer to the previous node in the list
};
void print(node*first) // This is just a standard print to be ran after every action to show the updated list
{
	node*temp;
	temp = first;
	while(temp != NULL)
	{
		cout << temp -> num;
		if(temp->next != NULL) {
			cout << " <--> ";
		}
		temp = temp -> next;
	}
	cout << endl;
}
void inOrder(node *& first, node *& last) //This function inserts a new number in its correct slot in the list
{
	node * temp;
	node * temp2;
	temp = first;
	int addNum;
	cout << "What number would you like to add?: ";
	cin >> addNum;
	cout << endl;
	if (first == NULL) {
		first = new node;
		first -> num = addNum;
		first->next = NULL;
		first->prev = NULL;
	}
	else if (first->num >= addNum) {
		first->prev = new node;
		first->prev->num = addNum;
		first->prev->next = first;
		first->prev->prev = NULL;
		first = first->prev;
	}
	else if (last->num <= addNum) {
		last->next = new node;
		last->next->num = addNum;
		last->next->prev = last;
		last->next->next = NULL;
		last = last->next;
	}
	else {
		temp = first;
		while(temp->next != NULL && temp->next->num < addNum){
			temp = temp->next;
		}
		temp2 = temp->next;
		temp->next = new node;
		temp->next->next = temp2;
		temp->next->num = addNum;
		temp->next->prev = temp;
		temp = temp->next;
		temp2->prev = temp;
	}
}
void printMenu(node * first, node * last) // This is the menu version of printing; it can print forwards and backwards
{
// Print out the linked list by having a temporary pointer scroll through the entire list
	int choice;
	do {
		cout << "How would you like the list to be printed?\n";
		cout << "(1) First to last\n";
		cout << "(2) Last to first\n";
		cin >> choice;
	} while (choice <= 1 && choice >= 2);
	node * temp;
	if (choice == 1) {
		temp = first;

		while(temp != NULL)
		{
			cout << temp -> num;
			if(temp->next != NULL) {
				cout << " <--> ";
			}
			temp = temp -> next;
		}
		cout << endl;
	}
	else if (choice == 2) {
		temp = last;

		while(temp != NULL)
		{
			cout << temp -> num;
			if(temp->prev != NULL) {
				cout << " <--> ";
			}
			temp = temp -> prev;
		}
		cout << endl;
	}
	
}
void del (node *& first, node *& last) // This function deletes a specific node and tells the user if the number named doesn't exist
{
	node*temp;
	temp = first;

	int key_value;
	cout << "Enter the value you want to delete: ";
	cin >> key_value;

	if (first -> num == key_value)
	{
		first = first -> next;	
		delete temp;
		first -> prev = NULL;
	}
	else if(last -> num == key_value)
	{
		last = last -> prev;
		delete last -> next;
		last -> next = NULL;
	}
	else
	{
		while(temp != NULL && temp-> num != key_value)
		{
			temp = temp -> next;
		}

		if(temp == NULL)
		{
			cout << "Number is not in the list\n";
		}
		else
		{		
			temp -> next -> prev = temp -> prev;
			temp -> prev -> next = temp -> next;
			delete temp;
		}
	}
}

int main()
{	
// Pointer definitions
	node * first = NULL;
	node * last;
	node * temp;
	node * temp2;
	int menuChoice = 0;
// Creates the first node
	first = new node;
	cout << "What number goes in the first node: ";
	cin >> first -> num;
	first -> next = NULL;
	first -> prev = NULL;
	last = first;

// This loop adds one new node, IN THE RIGHT ORDER into the list
	char more_nodes = 'y';		// Control to know if the user wants to enter more
	int new_number;				// Holds the new value to be entered

	while(more_nodes == 'y')		
	{
		cout << "What's the number for this new node? ";
		cin >> new_number;

		if(first->num > new_number) { //Checks if new number is less than the number in the first slot
			first->prev = new node;
			first->prev->prev = NULL;
			first->prev->next = first;
			first->prev->num = new_number;
			first = first->prev;
		}
		else if(last->num < new_number) { // Checks if new number is less than the number in the last slot
			last->next = new node;
			last->next->next = NULL;
			last->next->prev = last;
			last->next->num = new_number;
			last = last->next;
		}
		else { // finds the proper slot for the new number and inserts it correctly.
			temp = first;
			while(temp->next != NULL && temp->next->num < new_number){
				temp = temp->next;
			}
			temp2 = temp->next;
			temp->next = new node;
			temp->next->next = temp2;
			temp->next->num = new_number;
			temp->next->prev = temp;
			temp = temp->next;
			temp2->prev = temp;
		}
		
		print(first); //prints updated list
		cout << "Do you have more numbers to enter? ";
		cin >> more_nodes;
	}

	do { //Menu list
		cout << "What would you like to do?\n";
		cout << "(1) Print the linked list\n";
		cout << "(2) Delete a node\n";
		cout << "(3) Insert a node in order\n";
		cout << "(4) Quit\n";
		cin >> menuChoice;

		if (menuChoice == 1) { //Runs the menu print function
			printMenu(first,last);
		}
		else if (menuChoice == 2) { //Runs the delete function then prints updated list
			del(first,last);
			print(first);
		}
		else if (menuChoice == 3) {//Runs the insert in order function and prints updated list
			inOrder(first,last);
			print(first);
		}
	} while (menuChoice != 4);
return 0;
}




