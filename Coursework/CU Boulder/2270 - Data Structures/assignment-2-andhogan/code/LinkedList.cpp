#include "LinkedList.h"

// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList(){
  head = shared_ptr<node>(NULL);
}

//deconstructor,
LinkedList::~LinkedList(){
}


shared_ptr<node> LinkedList::InitNode(int data){
  shared_ptr<node> newNode(new node); //Initialize pointer to a new node
  // Your code here
  newNode->data = data; //Use pointer notation to set node struct member variables
  newNode->next = NULL;
  
  return newNode;
}

string LinkedList::Report(){
  string ret = "";
  // Your code here
  shared_ptr<node> currNode = head; //  shared_ptr<node> currNode(head)
  if(currNode == NULL){
    return ret;
  }
  else{
    while(currNode != NULL){
      ret = ret + to_string(currNode->data) + " ";
      currNode = currNode->next;
    }
  }
  return ret;
}

void LinkedList::AppendData(int data){
  shared_ptr<node> newNode = InitNode(data);
  Append(newNode);
}

void LinkedList::Append(shared_ptr<node> newNode){
  shared_ptr<node> currNode = head;
  if (!head) { // List empty
      head = newNode;
      return;
  }
    while(true) {
      if(currNode->next == NULL){
        currNode->next = newNode;
        break;
    }
    currNode = currNode->next;
  }
}

void LinkedList::InsertData(int offset, int data){
  // Your code here
  shared_ptr<node> newNode = InitNode(data);
  Insert(offset, newNode);
}

void LinkedList::Insert(int offset, shared_ptr<node> newNode){
  // Your code here

  shared_ptr<node> currNode = head;

  if (offset == 0){
    newNode->next = head;
    head = newNode;
  }
  for (int i = 0;; i++){
    if (i == offset-1){
      newNode->next = currNode->next;
      currNode->next = newNode;
        /*  
            new
           /   \
        curr -> next
        
        */
    }
    if (currNode->next == NULL)
    {
      break;
    }
    currNode = currNode->next;
  }
  
}

void LinkedList::Remove(int offset){

  shared_ptr<node> currNode = head;

  if (offset == 0){
    head = head->next;
    return;
  }

  for (int i = 0;; i++){
    if (i == offset-1){
      currNode->next = currNode->next->next;
        /*
              _______
            /        \
        curr->(rem)->next
        
        */
    }
    if (currNode->next == NULL)
    {
      break;
    }
    currNode = currNode->next;
  }

  // int size = Size();
  // if (offset < 0 || (size-1) < offset){ //checks validity of offset
  //   //cout << "Invalid index." << endl;
  //   return;
  // }

  // shared_ptr<node> currNode = this->head;
  // // Your code here
  // for (int i = 0; i < offset; i++){
  //     currNode = currNode->next;
  //   }
  //   currNode->prev->next = currNode->next;
  //   currNode->next->prev = currNode->prev;
}

int LinkedList::Size(){
  int ret = 0;
  shared_ptr<node> currNode = this->head;
  if(currNode == NULL){
    return 0;
  }
  else{
    while(currNode != NULL){
      ret++;
      currNode = currNode->next;
    }

  }
  return ret;
}

bool LinkedList::Contains(int data){
  // Your code here
  shared_ptr<node> currNode = this->head;
  if(currNode == NULL){
    return false;
  }
  else{
    while(currNode != NULL){
      if(currNode->data == data){
        return true;
      }
      currNode = currNode->next;

    }

  }
  return false;
}

// This function is implemented for you
// It returns the top pointer
shared_ptr<node> LinkedList::GetTop(){
  return head;
}

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::SetTop(shared_ptr<node> top_ptr){
  head = top_ptr;
}