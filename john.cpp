#include <iostream>
using namespace std;

struct node
{
  int weight;
  node *leftParent;
  node *rightParent;
  node *leftChild;
  node *rightChild;
  node *left;
  node *right;
};