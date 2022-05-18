#include "BST.h"

// constructor, initialize class variables and pointers here if need.
BST::BST(){
  root = shared_ptr<bst_node>(NULL);
}

//deconstructor,
BST::~BST(){
}

shared_ptr<bst_node> BST::InitNode(int data){
  shared_ptr<bst_node> newNode(new bst_node);
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->parent = NULL;

  return newNode;
}

void BST::Insert(shared_ptr<bst_node> newNode){
  if(root == NULL){
    root = newNode;
    return;
  }

  shared_ptr<bst_node> currNode = root;
  while(currNode){
    if (newNode->data < currNode->data)
    {
      if (currNode->left == NULL){
        currNode->left = newNode;
        newNode->parent = currNode;
        return;
      }
      else{
        currNode = currNode->left;
      }
    }
    else{
      if (currNode->right == NULL){
        currNode->right = newNode;
        newNode->parent = currNode;
        return;
      }
      else{
        currNode = currNode->right;
      }
      
    }
    
  }

}

void BST::InsertData(int data){
  shared_ptr<bst_node> newNode = InitNode(data); // initialize node w/ data
  Insert(newNode); // use the insert function as helper
}

void BST::Remove(int data){
  // Your code here
  shared_ptr<bst_node> currNode = root;
  shared_ptr<bst_node> parent = NULL;
  while(currNode)
  {
    if(currNode->data == data)
    {
        if(!currNode->left && !currNode->right) //Leaf
        {
          if(!parent) // data is the root, set root to NULL
          {
            root = NULL;
          }
          else if (parent->left == currNode) // remove Left leaf
          {
            parent->left = NULL;
          }
          else // remove right leaf
          {
            parent->right = NULL;
          }
        }
        else if(!currNode->right) // Remove node with left child
        {
          if(!parent)
          {
            root = currNode->left;
          }
          else if (parent->left == currNode)
          {
            parent->left = currNode->left;
          }
          else
          {
            parent->right = currNode->left;
          }
        }
        else if(!currNode->left) // Remove node with right child
        {
          if(!parent)
          {
            root = currNode->right;
          }
          else if (parent->left == currNode)
          {
            parent->left = currNode->left;
          }
          else
          {
            parent->right = currNode->left;
          }
        }
        else // Find successor
        {
          shared_ptr<bst_node> successorNode = currNode->right;
          while(successorNode->left){
            successorNode = successorNode->left;
          }
          int successorData = successorNode->data;
          Remove(successorData);
          currNode->data = successorData;
        }
        return; // Node found and removed
        
    }
    else if(data < currNode->data)
    {
      parent = currNode;
      currNode = currNode->left;
    }
    else
    {
      parent = currNode;
      currNode = currNode->right;
    }
  }
  return;
}

bool BST::Contains(shared_ptr<bst_node> subt, int data){
  if(GetNode(subt, data)){
    return true;
  }
  return false;
}

shared_ptr<bst_node> BST::GetNode(shared_ptr<bst_node> subt, int data){
  if (subt)
  {
    if (subt->data == data){
      return subt;
    }
    else if(data < subt->data){
      return GetNode(subt->left, data);
    }
    else{
      return GetNode(subt->right, data);
    }
  }
  return shared_ptr<bst_node>(NULL);
}

int BST::Size(shared_ptr<bst_node> subt){
  if(!subt)
  {
    return 0;
  }
  else
  {
    return 1 + Size(subt->left) + Size(subt->right);
  }
}

void BST::ToVector(shared_ptr<bst_node> subt, vector<int>& vec){
  if (!subt){
    return;
  }
  else{
    ToVector(subt->left, vec);
    vec.push_back(subt->data);
    ToVector(subt->right, vec);
  }
}

// This function is implemented for you
// Returns the root pointer
shared_ptr<bst_node> BST::GetRoot(){
  return root;
}

// This function is implemented for you
// sets a given pointer as the top pointer
void BST::SetRoot(shared_ptr<bst_node> root_ptr){
  root = root_ptr;
}