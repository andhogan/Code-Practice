#include "BTree.h"

// constructor, initialize class variables and pointers here if need.
BTree::BTree(){
  // Your code here
}

//deconstructor,
BTree::~BTree(){
}

void BTree::insert(shared_ptr<btree> root, int key){
  shared_ptr<btree> find_key = find(root, key);
  if(key == root->keys[0] || 
     key == root->keys[1] ||
     key == root->keys[2] ||
     key == root->keys[3])
  { //if key is in the node, return NULL. No duplicates allowed
    return;
  }
  if (root->is_leaf)
  {// We can only insert into leaf nodes
    if (root->num_keys == 5)
    {//There's no room to fit the key
      /* code */
    }
    
  }

}

void BTree::remove(shared_ptr<btree> root, int key){

}

shared_ptr<btree> BTree::find(shared_ptr<btree> root, int key){
  //Base Case
  if(root != NULL)           
  { // If root is not null, check the keys for a match or go to the next child node
    if( key == root->keys[0] ||
        key == root->keys[1] ||
        key == root->keys[2]   )
    { // The key has been found, return the node the key is located in.
        return root; 
    }

    if (root->is_leaf) 
    { // If the key was not found, but we have reached a leaf node, 
      // we return the node it would fit into.
      // We also want to stop our search here because there are no further children to traverse to.
      return root; 
    }

    if (key < root->keys[0]) 
    {//If the key is < A, go recursive search left
      return find(root->children[0], key);
    }
    else if (key < root->keys[1] || root->keys[1] == NULL) 
    {//If B is null or the key is < B, recursive search mid1
      return find(root->children[1], key);
    }
    else if (key < root->keys[2] || root->keys[2] == NULL) 
    {//If C is null or the key is < C, recursive search mid2
      return find(root->children[2], key);
    }
    else if(key < root->keys[3] || root->keys[3] == NULL)
    {//If D is null or the key is < D, recursive search mid3
      return find(root->children[3], key);
    }
    else{ //If key is greater than all keys, recursive search right
      return find(root->children[4], key);
    }
    
  }
  return root;
}

int BTree::count_nodes(shared_ptr<btree> root){
  //Base Case
  if(root == NULL)
  {
    return 0;
  }
  // if (root->is_leaf)
  // {//if node is the leaf, we count it and traverse no further
  //   return 1;
  // }
  if(root->num_keys == 1)
  {//If the node has 1 key, count it and then search the left and mid1 children
    return 1 + 
    count_nodes(root->children[0]) + 
    count_nodes(root->children[1]);
  }
  else if(root->num_keys == 2)
  {//If the node has 2 keys, count it and then search the left, mid1, mid2 children
    return 1 + 
    count_nodes(root->children[0]) + 
    count_nodes(root->children[1]) + 
    count_nodes(root->children[2]);
  }
  else if(root->num_keys == 3)
  {//If the node IS FULL with 3 keys, count it and then search the left, mid1, mid2, right children
    return 1 + 
    count_nodes(root->children[0]) + 
    count_nodes(root->children[1]) + 
    count_nodes(root->children[2]) +
    count_nodes(root->children[3]);
  }
  else
  {
      return 1 + 
    count_nodes(root->children[0]) + 
    count_nodes(root->children[1]) + 
    count_nodes(root->children[2]) +
    count_nodes(root->children[3]) +
    count_nodes(root->children[4]);
  }
  
}

int BTree::count_keys(shared_ptr<btree> root){
  //Base Case
  if(root == NULL)
  {
    return 0;
  }
  // if (root->is_leaf)
  // {//if node is the leaf, we count it and traverse no further
  //   return 1;
  // }
  if(root->num_keys == 1)
  {//If the node has 1 key, count it and then search the left and mid1 children
    return root->num_keys + 
    count_keys(root->children[0]) + 
    count_keys(root->children[1]);
  }
  else if(root->num_keys == 2)
  {//If the node has 2 keys, count it and then search the left, mid1, mid2 children
    return root->num_keys + 
    count_keys(root->children[0]) + 
    count_keys(root->children[1]) + 
    count_keys(root->children[2]);
  }
  else if(root->num_keys == 3)
  {//If the node IS FULL with 3 keys, count it and then search the left, mid1, mid2, right children
    return root->num_keys + 
    count_keys(root->children[0]) + 
    count_keys(root->children[1]) + 
    count_keys(root->children[2]) +
    count_keys(root->children[3]);
  }
  else
  {
    return root->num_keys + 
    count_keys(root->children[0]) + 
    count_keys(root->children[1]) + 
    count_keys(root->children[2]) +
    count_keys(root->children[3]) +
    count_keys(root->children[4]);
  }
}