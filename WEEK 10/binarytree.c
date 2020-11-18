#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int value) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value; 
    node->left = NULL;
    node->right = NULL; 
    return (node); 
}


int findBiggest(struct Node* iter)
{
  if (iter == NULL)
	  return 0;
  if (findBiggest(iter->left) < findBiggest(iter->right))
	return iter->value + findBiggest(iter->right);
  else
	  return iter->value + findBiggest(iter->left);


}

int main(){
  struct Node* root = newNode(1);
  root->left = newNode(5);
  root->right = newNode(10);
  root->left->left = newNode(20);
  root->left->left->left = newNode(25);
  root->left->right = newNode(15);
  root->left->left->right = newNode(13);
  root->right->left = newNode(35);
  root->right->right = newNode(8);
  root->right->right->left = newNode(28);
  
  printf("the biggest sum of the tree is %d\n", findBiggest(root));

  return 0;
}
