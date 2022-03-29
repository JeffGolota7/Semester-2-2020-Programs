#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    int num;
    node *left;
    node *right;
    node *parent;
};

class tree
{

public:
    node *root;
    node *temp;
    int size;

    tree()
    {
        root = NULL;
        temp = root;
        size = 0;
    }

    void addLeaf(int addNumber)
    {
        if (temp == NULL)
        {
            root = new node;
            root->num = addNumber;
            root->left = NULL;
            root->right = NULL;
            root->parent = NULL;
        }
        else if (addNumber < temp->num)
        {
            if (temp->left == NULL)
            {
                temp->left->num = addNumber;
                temp->left->parent = temp;
                temp->left->left = NULL;
                temp->left->right = NULL;
            }
            else
            {
                temp = temp->left;
                addLeaf(addNumber);
            }
        }
        else if (addNumber > temp->num)
        {
            if (temp->right == NULL)
            {
                temp->right->num = addNumber;
                temp->right->parent = temp;
                temp->right->left = NULL;
                temp->right->right = NULL;
            }
            else
            {
                temp = temp->right;
                addLeaf(addNumber);
            }
        }
    }
    void print()
    {
        postorder(root);
    }
    void postorder(node *p, int indent = 0)
    {
        if (p != NULL)
        {
            cout << p->num << "\n ";
            if (p->left)
                postorder(p->left, indent + 4);
            if (p->right)
                postorder(p->right, indent + 4);
            if (indent)
            {
                std::cout << std::setw(indent) << ' ';
            }
        }
    }
};
int main()
{
    int choice;
    tree chart;
    do
    {
        cout << "choice: ";
        cin >> choice;

        if (choice == 1)
        {
            chart.print();
        }
        else if (choice == 2)
        {
            int addNum;
            cout << "Enter a number you would like to add: ";
            cin >> addNum;
            chart.addLeaf(addNum);
        }
    } while (choice != 6);
    return 0;
}