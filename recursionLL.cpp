// This program introduces recursion into basic LL functions
// Author: Jeff Golota
// Date: 4/8/2020

#include <iostream>
using namespace std;

struct node{
	int num;
	node * next;
};

void append(node * & last)			// Non-recursive function appends to the list
{
	last -> next = new node;
	cout << "Please enter a number: ";
	cin >> last -> next -> num;
	last = last -> next;
	last -> next = NULL;
}

void print(node * temp)				// Recursive printing function from class
{
	if(temp == NULL)	// BASE CASE
	{
		cout << "NULL" << endl << "Printing has completed\n";
	}
	else				// RECURSIVE CASE
	{
		cout << temp -> num << " -> ";
		print (temp -> next);
	}
}

int sum(node * temp)
{
	if(temp == NULL)	// BASE CASE
	{
		return 0;
	}					// RECURSIVE CASE
	else
	{
		return (temp -> num + sum(temp -> next));
	}
}

int largest(node * temp, int biggest)
{
	if (temp == NULL) { // Ends the recursive function by returning the biggest number
		return biggest;
	}
	else {
		if (temp->num >= biggest) { // If the current temp number is bigger than the biggest value it reassigns biggest
			biggest = temp->num;
		}
		temp = temp->next;
		return largest(temp,biggest);
	}

}

bool finder(node * temp, int key_value)
{
	// YOUR CODE GOES HERE
	if (temp == NULL) { // If temp scrolls through the list and doesn't find the value it returns false
		return false;
	}
	else {
		if (temp->num == key_value) { // Returns true if it finds the value
			return true;
		}
		temp = temp->next;
		return finder(temp,key_value);
	}
	
}

void big_swap(node * temp, node * big_ptr, node * last)
{
	// YOUR CODE GOES HERE
	if (big_ptr == last) { // Checks to see if the largest number is already at the end.
		cout << "Biggest number is already at the end.\n";
	}
	else if (temp == NULL) { // Swaps the big ptr value with the last value once temp is done scrolling through
		temp = new node;
		temp->num = big_ptr->num;
		big_ptr->num = last->num;
		last->num = temp->num;
		big_ptr = last;
	}
	else if (temp->num >= big_ptr->num) { // If the current temp value is larger than big ptr's value it assigns big ptr to the temp slot
		big_ptr = temp;
		temp = temp->next;
		big_swap(temp,big_ptr,last);
	}
	else { // if all other cases aren't true it just moves temp along
		temp = temp->next;
		big_swap(temp,big_ptr,last);
	}
}

int main()
{
	int choice, total, key_value, max;

//  Load the first node
	node * first;
	node * last;
	first = new node;
	cout << "Please enter the first number: ";
	cin >> first -> num;
	first -> next = NULL;
	last = first;

	do 
	{
		cout << "\n1. Append to the list\n"
			 << "2. Print the list\n"
			 << "3. Compute the sum\n"
			 << "4. Compute the largest number\n"
			 << "5. Search for a value\n"
			 << "6. Swap the largest value with last\n"
			 << "7. Quit\n\n"			 
			 << "What do you want to do: ";
		cin >> choice;

		if (choice == 1) {
			append(last);
		} 
		if (choice == 2) {
			print(first);
		} 
		else if (choice == 3) {
			total = sum(first);
			cout << "The sum of the numbers is " << total << endl;
		} 
		else if (choice == 4) {
			max = largest(first, first -> num);
			cout << "The largest number is " << max << endl;
		}
		else if (choice == 5) {
			cout << "What number do you want to search for: ";
			cin >> key_value;

			if(finder(first, key_value) == true)
			{
				cout << "The number IS in the list!\n";
			}
			else
			{
				cout << "The number is NOT in the list\n";
			}		
		}
		else if (choice == 6) {
			big_swap(first, first, last);
		}
	} while (choice != 7);

	return 0;
}

