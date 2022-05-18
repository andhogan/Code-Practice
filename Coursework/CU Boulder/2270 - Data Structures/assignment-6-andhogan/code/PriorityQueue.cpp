#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(){
    head = shared_ptr<pq>(NULL);
}

PriorityQueue::~PriorityQueue(){
    // You don't need to add anything here
}

// Implement this after defining struct in .h file
shared_ptr<pq> PriorityQueue::InitPriorityQueue(){
    shared_ptr<pq> new_pq(new pq);
    SetHead(new_pq);
    return new_pq;
}

// Implement this second
void PriorityQueue::Insert(shared_ptr<pq> queue, string text, float priority){
    // Initialize new node
    shared_ptr<pq> new_pq(new pq);
    new_pq->text = text;
    new_pq->priority = priority;
    new_pq->next = NULL;

    // Initialize pointer nodes
    shared_ptr<pq> currNode = head;
    shared_ptr<pq> prevNode(NULL);

    // Check to see if a head node is present
    if(!currNode)
    {// If the queue is empty (no head is present), make this the head node
        head = new_pq;
        return;
    }

    // If there is a head, check to see whether this new node has higher priority, 
    // and set a new head
    if(new_pq->priority >= currNode->priority)
    {
        new_pq->next = head;
        head = new_pq;
        return;
    }
    
    //Already checked the head, move nodes ahead.
    prevNode = currNode;
    currNode = currNode->next;

    // Compare the new node with the rest in the list, planning on inserting in the middle
    while(currNode)
    {// Loop while there is a node being looked at that is not NULL
        if(new_pq->priority >= currNode->priority)
        {
            new_pq->next = currNode;
            prevNode->next = new_pq;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;

    }
    return;

}

// Implement this third
string PriorityQueue::Remove(shared_ptr<pq> queue){

    if(!head)
    {//If the queue is empty, return a blank string ""
        return "";
    }

    //If the queue is not empty, return head->text and set a new head

    // Save head text result
    string result = head->text;

    // Set new head, which is head->next
    head = head->next;

    return result;

}

// Implement this last
string PriorityQueue::Peek(shared_ptr<pq> queue){
    return head->text;    // replace this line with your own code
}

//Helper Functions


void PriorityQueue::SetHead(shared_ptr<pq> head){
    this->head = head;
}