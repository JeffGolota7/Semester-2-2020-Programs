
#include <iostream>
using namespace std;

struct node
{
	int num;
	node *parent;
	node *left;
	node *right;
	node *prev;
	node *next;
};

class heap
{
public:
	node *root;
	node *last;
	node *last_parent;
	node *temp;
	bool empty;

	heap() // Constructor
	{
		root = NULL;
		last = NULL;
		last_parent = NULL;
		empty = true;
	}

	void search() // Searches the heap for the user's request and prints a family summary
	{
		if (empty)
		{
			cout << "Heap is empty.\n";
		}
		else
		{
			temp = root;
			int searchNum;
			cout << "Enter the number you would like to search for: \n";
			cin >> searchNum;

			while (temp != NULL)
			{
				if (temp->num == searchNum)
				{
					cout << "Number found!\n";
					if (temp->parent != NULL)
					{
						cout << "Parent: " << temp->parent->num << endl;
					}
					else
					{
						cout << "No parent value.\n";
					}
					if (temp->left != NULL)
					{
						cout << "Left child: " << temp->left->num << endl;
					}
					else
					{
						cout << "No left child value.\n";
					}
					if (temp->right != NULL)
					{
						cout << "Right child: " << temp->right->num << endl;
					}
					else
					{
						cout << "No right child value.\n";
					}
					return;
				}
				else
				{
					temp = temp->next;
				}
			}
			if (temp == NULL)
			{
				cout << "Number was not found in the heap.\n";
			}
		}
	}

	void down_heapify(node *temp) // Recursively down heapifies after a deletion
	{
		int tempNum;
		if (temp->left == NULL && temp->right == NULL)
		{
			return;
		}
		else if (temp->left != NULL && temp->right == NULL)
		{
			if (temp->left->num > temp->num)
			{
				tempNum = temp->num;
				temp->num = temp->left->num;
				temp->left->num = tempNum;
				down_heapify(temp->left);
			}
		}
		else if (temp->left == NULL && temp->right != NULL)
		{
			if (temp->right->num > temp->num)
			{
				tempNum = temp->num;
				temp->num = temp->right->num;
				temp->right->num = tempNum;
				down_heapify(temp->right);
			}
		}
		else if (temp->left != NULL && temp->right != NULL)
		{
			if (temp->left->num > temp->right->num)
			{
				if (temp->left->num > temp->num)
				{
					tempNum = temp->num;
					temp->num = temp->left->num;
					temp->left->num = tempNum;
					down_heapify(temp->left);
				}
			}
			else if (temp->right->num > temp->left->num)
			{
				if (temp->right->num > temp->num)
				{
					tempNum = temp->num;
					temp->num = temp->right->num;
					temp->right->num = tempNum;
					down_heapify(temp->right);
				}
			}
		}
	}

	void remove()
	{
		if (empty)
		{
			cout << "Heap is empty.\n";
		}
		else
		{
			if (last == root)
			{
				cout << "The root value is: " << root->num << endl;
				root = NULL;
				empty = true;
			}
			else
			{
				cout << "The root value is: " << root->num << endl;
				root->num = last->num;
				temp = last;
				last = last->prev;
				last->next = NULL;
				if (temp == temp->parent->right)
				{
					temp->parent->right = NULL;
				}
				else if (temp == temp->parent->left)
				{
					temp->parent->left = NULL;
				}
				delete temp;
				down_heapify(root);
				print();
			}
		}
	}
	// These functions are already complete
	void heapify(node *temp)
	{
		int dummy;

		// Base Cases
		if (temp->parent == NULL) // If you reach the top of the tree, stop
		{
			cout << "You've reach the top and it's been heapified.\n";
		}
		else if (temp->parent->num > temp->num) // If you didn't need to swap, stop
		{
			cout << "No swap needed, so it's been heapified.\n";
		}
		// Recursive Case
		else
		{
			dummy = temp->num; // Swap the values
			temp->num = temp->parent->num;
			temp->parent->num = dummy;
			heapify(temp->parent); // Call the function, but send it the parent
		}
	}

	void insert()
	{
		if (root == NULL)
		{
			root = new node;
			cout << "What's the first value to add to the heap: ";
			cin >> root->num;
			root->left = NULL;
			root->right = NULL;
			root->parent = NULL;
			root->next = NULL;
			root->prev = NULL;
			last = root;
			last_parent = root;
		}
		else // Makes a new node and links it in with the tree and linked list
		{
			last->next = new node;
			last->next->prev = last;
			last = last->next;
			cout << "What's the next number: ";
			cin >> last->num;
			last->left = NULL;
			last->right = NULL;
			last->next = NULL;
			last->parent = last_parent;

			// Toggle the last_parent pointer if needed
			if (last_parent->left == NULL)
			{
				last_parent->left = last;
			}
			else
			{
				last_parent->right = last;
				last_parent = last_parent->next;
			}
		}
		empty = false;

		heapify(last);
		print();
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		node *temp = root;

		cout << endl
			 << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << '\t';
		}
		cout << temp->num << endl
			 << endl;
		temp = temp->next;

		for (int j = 1; j < 5; j++)
		{
			cout << '\t';
		}
		for (int i = 0; i < 2; i++)
		{
			if (temp != NULL)
			{
				cout << temp->num << '\t' << '\t';
				temp = temp->next;
			}
		}
		cout << endl
			 << endl;

		cout << "                          ";
		for (int i = 0; i < 4; i++)
		{
			if (temp != NULL)
			{
				cout << temp->num << "        ";
				temp = temp->next;
			}
		}
		cout << endl
			 << endl;

		cout << "                      ";
		for (int i = 0; i < 8; i++)
		{
			if (temp != NULL)
			{
				cout << temp->num << "    ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
};

int main()
{
	heap tree;
	int ans = 0;

	// This menu lets you add, delete or print the heap. 1 & 3 already work
	while (ans != 5)
	{
		cout << "What do you want to do?\n"
			 << "1. Print the heap\n"
			 << "2. Search the heap\n"
			 << "3. Add to the heap\n"
			 << "4. Delete the root\n"
			 << "5. Quit\n";
		cin >> ans;

		if (ans == 1)
		{
			tree.print();
		}
		else if (ans == 2)
		{
			tree.search();
		}
		else if (ans == 3)
		{
			tree.insert();
		}
		else if (ans == 4)
		{
			tree.remove();
		}
	}

	return 0;
}
