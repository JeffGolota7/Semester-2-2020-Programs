// This program implements a BST in a menu-driven program

#include <iostream>
using namespace std;

struct node
{
	int num;
	node *parent;
	node *left;
	node *right;
};
struct trunk
{
	trunk *prev;
	string str;

	trunk(trunk *prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

void showTrunks(trunk *temp)
{
	if (temp == NULL)
	{
		return;
	}
	showTrunks(temp->prev);
	cout << temp->str;
}
void print(node *temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{
		print(temp->left);
		cout << temp->num;
	}
}
//void print(node *temp); // see below the main for the function's (ugly) details...

void insert(node *&root, node *temp, int value)
{
	if (root == NULL) // If the tree is empty, insert value as the root node
	{
		root = new node;
		root->num = value;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
	}
	else if (value <= temp->num) // GO LEFT
	{
		if (temp->left == NULL) // If you have space, insert it
		{
			temp->left = new node;
			temp->left->num = value;
			temp->left->parent = temp;
			temp->left->left = NULL;
			temp->left->right = NULL;
		}
		else // If you don't, move left & repeat
		{
			temp = temp->left;
			insert(root, temp, value);
		}
	}
	else // GO RIGHT
	{
		if (temp->right == NULL) // If you have space, insert it
		{
			temp->right = new node;
			temp->right->num = value;
			temp->right->parent = temp;
			temp->right->left = NULL;
			temp->right->right = NULL;
		}
		else // If you don't, move right & repeat
		{
			temp = temp->right;
			insert(root, temp, value);
		}
	}
}

void search(node *temp, int value)
{
	if (temp == NULL)
	{
		cout << "The number is not in the tree\n";
	}
	else if (temp->num == value)
	{
		cout << "Your number is in the tree\n";
	}
	else if (value < temp->num)
	{
		search(temp->left, value);
	}
	else
	{
		search(temp->right, value);
	}
}

void remove(node *&root, int value)
{
	node *temp = root;
	node *temp2;
	node *temp3;
	// YOUR CODE GOES HERE!!
	if (root == NULL)
	{
		cout << "Tree is empty.\n";
		return;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->num == value)
			{
				temp2 = temp->parent;
				break;
			}
			else
			{
				if (value > temp->num)
				{
					temp = temp->right;
				}
				else
				{
					temp = temp->left;
				}
			}
		}
		if (temp == NULL) // If value isnt found then temp is NULL so we return the function
		{
			cout << "Value does not exist in the table.\n";
			return;
		}
		if (temp == root)
		{
			root = NULL;
		}
		else
		{
			if ((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL)) // if temp has only one child
			{
				if (temp2->left == temp)
				{
					temp2->left = temp->right;
					temp->right->parent = temp2;
					delete temp;
				}
				else
				{
					temp2->right = temp->left;
					temp->left->parent = temp2;
					delete temp;
				}
			}
			else if (temp->left == NULL && temp->right == NULL) // if temp has no children
			{
				if (temp2->left == temp)
				{
					temp2->left = NULL;
				}
				else if (temp2->right == temp)
				{
					temp2->right = NULL;
				}
				delete temp;
				return;
			}
			else if (temp->left != NULL && temp->right != NULL)
			{
				temp2 = temp;
				temp = temp->left;
				while (temp->right != NULL)
				{
					temp = temp->right;
				}
				temp2->num = temp->num;
				temp3 = temp->parent;
				if ((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL)) // if temp has only one child
				{
					if (temp3->left == temp)
					{
						temp3->left = temp->right;
						temp->right->parent = temp3;
						delete temp;
					}
					else
					{
						temp2->right = temp->left;
						temp->left->parent = temp3;
						delete temp;
					}
				}
				else if (temp->left == NULL && temp->right == NULL) // if temp has no children
				{
					if (temp3->left == temp)
					{
						temp3->left = NULL;
					}
					else if (temp3->right == temp)
					{
						temp3->right = NULL;
					}
					delete temp;
					return;
				}
			}
		}
	}
}

int main()
{
	node *root = NULL;
	int choice;
	int value;

	do
	{
		cout << "\n1. Print the tree\n"
			 << "2. Insert into the tree\n"
			 << "3. Search for a value in the tree\n"
			 << "4. Delete from the tree\n"
			 << "5. Quit\n\n"
			 << "What do you want to do: ";
		cin >> choice;

		if (choice == 1)
		{
			print(root);
		}
		else if (choice == 2)
		{
			cout << "\nWhat number do you want to insert: ";
			cin >> value;
			insert(root, root, value);
			print(root);
		}
		else if (choice == 3)
		{
			print(root);
			cout << "\nWhat number do you want to search for: ";
			cin >> value;
			search(root, value);
		}
		else if (choice == 4)
		{
			cout << "What number do you want to remove: ";
			cin >> value;
			remove(root, value);
			print(root);
		}
	} while (choice != 5);

	return 0;
}

/*void print(node *temp)
{
	if (temp == NULL)
	{
		cout << "Tree is empty.\n";
	}
	else
	{
		cout << endl
			 << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << '\t';
		}
		cout << temp->num << endl
			 << endl;

		for (int j = 1; j < 5; j++)
		{
			cout << '\t';
		}

		if (temp->left != NULL)
			cout << temp->left->num << "                  ";
		else
			cout << "                        ";
		if (temp->right != NULL)
			cout << temp->right->num;

		cout << endl
			 << endl;

		cout << "                            ";

		node *templ = NULL;
		node *tempr = NULL;
		node *templl = NULL;
		node *templr = NULL;
		node *temprl = NULL;
		node *temprr = NULL;

		if (temp->left != NULL)
		{
			templ = temp->left;
			if (templ->left != NULL)
			{
				cout << templ->left->num << "      ";
				templl = templ->left;
			}
			else
				cout << "       ";
			if (templ->right != NULL)
			{
				cout << templ->right->num << "          ";
				templr = templ->right;
			}
			else
				cout << "         ";
		}
		if (temp->right != NULL)
		{
			tempr = temp->right;
			if (tempr->left != NULL)
			{
				cout << tempr->left->num << "      ";
				temprl = tempr->left;
			}
			else
				cout << "          ";
			if (tempr->right != NULL)
			{
				cout << tempr->right->num << "      ";
				temprr = tempr->right;
			}
			else
				cout << "        ";
		}

		cout << endl
			 << endl;

		cout << "                        ";

		if (temp->left != NULL)
		{
			if (templl != NULL)
			{
				if (templl->left != NULL)
					cout << templl->left->num << "    ";
				else
					cout << "     ";
				if (templl->right != NULL)
					cout << templl->right->num << "    ";
				else
					cout << "     ";
			}
			else
				cout << "           ";

			if (templr != NULL)
			{
				if (templr->left != NULL)
					cout << templr->left->num << "   ";
				else
					cout << "    ";
				if (templr->right != NULL)
					cout << templr->right->num << "   ";
				else
					cout << "     ";
			}
			else
				cout << "          ";
		}
		else
			cout << "             ";

		if (temp->right != NULL)
		{
			if (temprl != NULL)
			{
				if (temprl->left != NULL)
					cout << temprl->left->num << "   ";
				else
					cout << "     ";
				if (temprl->right != NULL)
					cout << temprl->right->num << "   ";
				else
					cout << "    ";
			}
			else
				cout << "        ";

			if (temprr != NULL)
			{
				if (temprr->left != NULL)
					cout << temprr->left->num << "   ";
				else
					cout << "    ";
				if (temprr->right != NULL)
					cout << temprr->right->num << "   ";
				else
					cout << "     ";
			}
			else
				cout << "        ";
		}
		else
			cout << "           ";
	}
}
*/