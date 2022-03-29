// This program implements a class for a hash table
// Author: Jeff Golota
// Date: 4/15/2020

#include <iostream>
using namespace std;

const int SIZE = 10;

struct node
{
	string name;
	int IDnum;
	node *next; // the next node in each row of the table
};

class hash_table
{
public:
	node *table[SIZE]; // an array of FIRST pointers, one for each row
	int length[SIZE];  // an array to hold the lengths of each row
	node *temp;
	bool empty;

	// ADD additional data members if you want

	//  Constructor
	hash_table()
	{
		temp = NULL;
		empty = true;
		for (int i = 0; i < SIZE; ++i) // Sets all the entries and length amounts to NULL and 0 respectively
		{
			table[i] = NULL;
			length[i] = 0;
		}
	}

	//  Methods
	int hashing(int key_ID)
	{
		return key_ID % SIZE;
	}

	void print() // Don't change this function
	{
		for (int i = 0; i < SIZE; i++)
		{
			temp = table[i];
			cout << '|' << i << "| ";
			for (int j = 0; j < length[i]; j++)
			{
				cout << temp->name << " -> ";
				temp = temp->next;
			}
			cout << "NULL\n";
		}
		cout << endl;
	}

	void addNode()
	{
		int newID;
		int row;

		cout << "Enter ID: ";
		cin >> newID;
		cout << endl;

		row = hashing(newID); // Grabs the initial row for the new entry
		temp = table[row]; // Sets temp to the first pointer in that row
		while (temp != NULL) // Scrolls through all entries and checks if there are any duplicate IDs and then asks you to enter a new one if there is
		{
			if (temp->IDnum == newID)
			{
				cout << "Duplicate ID found! Please enter a new ID: ";
				cin >> newID;
				cout << endl;
				row = hashing(newID);
				temp = table[row];
			}
			else
			{
				temp = temp->next;
			}
		}
		temp = table[row]; // Prepends the row and increases length and sets empty to false
		table[row] = new node;
		table[row]->IDnum = newID;
		cout << "Enter the name of the new entry: \n";
		cin >> table[row]->name;
		table[row]->next = temp;
		length[row]++;
		empty = false;
	}

	void remove()
	{
		int delID;
		int row;
		bool found = false;
		bool emptyCheck = true; // Boolean to check if all the rows are empty after removal in order for the program to update empty
		if (empty)
		{
			cout << "The table is empty\n";
		}
		else
		{
			cout << "Enter the ID number of the entry you would like to delete: ";
			cin >> delID;
			row = hashing(delID);
			temp = table[row];
			if (length[row] == 1) // If the length in the row is one, then it will do a check to make sure it is or isn't the only row that is going to be empty and if so it updates empty.
			{
				table[row] = NULL;
				length[row]--;
				for (int i = 0; i < SIZE; ++i)
				{
					if (length[i] == 0)
					{
						emptyCheck = true;
					}
					else
					{
						emptyCheck = false;
					}
				}
				if (emptyCheck)
				{
					empty = true;
				}
			}
			else // If the row is more than one entry it runs this code
			{
				while (temp != NULL)
				{
					if (temp->IDnum == delID)
					{
						delete temp;
						found = true;
						length[row]--;
						break;
					}
				}
				if (!found)
				{
					cout << "ID not in system\n";
				}
			}
		}
	}

	void IDLookup(node *temp, int key_ID){ // Recursive function to scroll through the row and find the entry
		if (temp == NULL)
		{
			cout << "ID not in system\n";
		}
		else if (temp->IDnum == key_ID)
		{
			cout << "Entry found\n";
			cout << "Name: " << temp->name << endl;
			cout << "ID: " << temp->IDnum << endl;
		}
		else
		{
			IDLookup(temp->next,key_ID);
		}
	}
	
	bool nameLookup(node *temp, int row, string key_name)
	{
		if (length[row] == 1) { // If the length is one then it just checks the name against the search and returns if true or not
			if (temp->name == key_name) {
				return true;
			}
		}
		else if (length[row] > 1) { // If the length is greater than one it scrolls through and finds the name
			while (temp != NULL) {
				if (temp->name == key_name) {
					return true;
				}
				temp = temp->next;
			}
			row++;
			temp = table[row];
			return nameLookup(temp,row,key_name);
		}
		else {
			row++;
			temp = table[row];
			return nameLookup(temp,row,key_name);
		}
	}
};

int main()
{
	int choice, key_ID;
	node *temp;
	string key_name;
	hash_table chart; // Declares a hash table called chart

	do
	{
		cout << "\n1. Print the table\n"
			 << "2. Add a node\n"
			 << "3. Delete a node\n"
			 << "4. Look up a node in the table by ID number\n"
			 << "5. Look up a node in the table by name\n"
			 << "6. Quit\n\n"
			 << "What do you want to do: ";
		cin >> choice;

		if (choice == 1)
		{
			chart.print();
		}
		else if (choice == 2)
		{
			chart.addNode();
		}
		else if (choice == 3)
		{
			chart.remove();
		}
		else if (choice == 4)
		{
			if (chart.empty)
			{
				cout << "System is empty.\n";
			}
			else
			{
				cout << "What ID number do you want to search for: ";
				cin >> key_ID;
				temp = chart.table[chart.hashing(key_ID)];
				chart.IDLookup(temp, key_ID);
			}
		}
		else if (choice == 5)
		{
			if (chart.empty) {
				cout << "System is empty\n";
			}
				else {
				cout << "What name do you want to search for: ";
				cin >> key_name;
				temp = chart.table[0];
				if (chart.nameLookup(temp, 0, key_name) == true)
				{
					cout << key_name << " is in your chart!\n";
				}
				else
				{
					cout << key_name << " is NOT in the chart\n";
				}
			}
		}

	} while (choice != 6);
	return 0;
}
