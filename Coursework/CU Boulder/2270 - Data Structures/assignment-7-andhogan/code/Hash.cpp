#include "Hash.h"

// implemented for you - don't change this one
unsigned int DJB2(std::string key){
  unsigned int hash = 5381;
  // Leaving the debugging stuff commented out, in case you want to
  // play. It will output the hash at each incremental step so you can
  // see how it takes shape.
  //
  //  cout << "Hashing string \"" << key << "\"" << endl;
  //  cout << bitset<32>(hash) << " " << hash << endl;
  for (size_t i=0; i < key.length(); i++) {
    char c = key[i]; 
    hash = ((hash << 5) + hash) + c;
    // cout << bitset<32>(hash) << " " << hash << endl;
  }
  // cout << "Hashed string \"" << key << "\" to " << hash << endl;
  //
  // for light reading on why djb2 might not be the best
  // production-grade hash function, go to
  // http://dmytry.blogspot.com/2009/11/horrible-hashes.html
  return hash;
}

// implemented for you - don't change this one
unsigned int ModuloBucketFunc(unsigned int hashcode, unsigned int cap){
  unsigned int b = hashcode % cap;
  return b;
}

// constructor, initialize class variables and pointers here if need.
Hash::Hash(){
  // your code here
}

//deconstructor,
Hash::~Hash(){
}

shared_ptr<hash_table> Hash::InitTable(unsigned int cap){
  shared_ptr<hash_table> newHashTable(new hash_table);
  newHashTable->capacity = cap; //capacity of the hash table
  newHashTable->size = 0; //no entries in the table yet
  newHashTable->occupied = 0; //no entires in table yet, but also considers those that have been occupied in the past
  newHashTable->hash_func = DJB2;
  newHashTable->bucket_func = ModuloBucketFunc;
  newHashTable->table = shared_ptr<htable>(new htable(cap));

  return newHashTable;
}

shared_ptr<hash_node> Hash::InitNode(std::string key, unsigned int hashcode, std::string val){
  shared_ptr<hash_node> newNode(new hash_node);
  newNode->deleted = false;
  newNode->key = key;
  newNode->hashcode = hashcode;
  newNode->value = val;
  return newNode;
}

bool Hash::SetKVP(shared_ptr<hash_table> tbl, std::string key, std::string value){
  if (tbl->capacity == tbl->occupied)
  {//IF capacity is equal to occupied, the table is full and nothing can be added to it. Return false.
    return false;
  }
  
  //If there is room, create a new hash node and find a bucket to place the new node into.
  unsigned int hashcode = tbl->hash_func(key); // create a hashcode for the key, DJB2
  shared_ptr<hash_node> newNode = InitNode(key, hashcode, value); //initialize new hash node with hashcode

  //Compute table insertion index using the table's bucket function: ModuloBucketFunc(hashcode, tbl->cap
  //returns index = hashcode % capacity
  unsigned int insertIndex = tbl->bucket_func(hashcode, tbl->capacity); 

  //Linearly Probe to find an insertion point
  for(int i = 0; i < tbl->capacity; i++) 
  {
    if(tbl->table->at(i) && tbl->table->at(i)->key == newNode->key)
    {
      tbl->table->at(i)=newNode;
      return true;
    }
  }

  if (tbl->occupied < tbl->capacity)
  {//
    tbl->table->at(insertIndex)=(newNode);
    tbl->size++;
    tbl->occupied++;
    return true;
  }

}

float Hash::Load(shared_ptr<hash_table> tbl){
  //Load returns a load factor describing how full the table is, i.e. how many buckets are, or were, occupied at some point.
  if (tbl->capacity != 0)
  {// We don't want to run into Divide by Zero errors:
    return (float(tbl->occupied))/ (float(tbl->capacity));
  }
  else
  {//Table capacity is 0, return 0
    return 0;
  }
}

std::string Hash::GetVal(shared_ptr<hash_table> tbl, std::string key){
//   unsigned int hashcode = tbl->hash_func(key);
//   unsigned int getIndex = tbl->bucket_func(hashcode, tbl->capacity); 
//   if(tbl->table->at(getIndex)->key == key)
//   {//search that index first
//     return tbl->table->at(getIndex)->value;
//   }
//   else
//   {//linear probe until we find the key or an empty bucket
//     int counter = 0;
//     while(tbl->table->at(getIndex) && !tbl->table->at(getIndex)->deleted)
//     {//search while we 
//       if(tbl->table->at(getIndex)->key == key)
//       {//search that index first
//         return tbl->table->at(getIndex)->value;
//       }
//       getIndex++;
//       counter++;
//     }
  
//   //All else fails, return an empty string:
  
//   }
// return "";
  


  for(int i = 0; i < tbl->table->size(); i++) 
  {//probe the table
    if(tbl->table->at(i) && tbl->table->at(i)->key == key)
    {
      return tbl->table->at(i)->value;
    }
  }  
  return "";
}

bool Hash::Contains(shared_ptr<hash_table> tbl, std::string key){
  for(int i = 0; i < tbl->table->size(); i++) 
  {//probe the table
    if(tbl->table->at(i) && tbl->table->at(i)->key == key)
    {
      return true;
    }
  }  
  return false;
}

bool Hash::Remove(shared_ptr<hash_table> tbl, std::string key){
  unsigned int hashcode = DJB2(key);
  for(int i = 0; i <tbl ->table->size(); i++){
    if(tbl->table->at(i) && tbl->table->at(i)->key == key){
      tbl->table->at(i) == NULL;
      tbl->size--;
      return true;
    }
  }
  return false;
}

void Hash::Resize(shared_ptr<hash_table> tbl, unsigned int new_capacity){
  // your code here
}

// implemented for you - feel free to change this one if you like
void Hash::PrintTable(shared_ptr<hash_table> tbl){
  cout << "Hashtable:" << endl;
  cout << "  capacity: " << tbl->capacity << endl;
  cout << "  size:     " << tbl->size << endl;
  cout << "  occupied: " << tbl->occupied << endl;
  cout << "  load:     " << Load(tbl) << endl;
  if (tbl->capacity < 130) {
    for (unsigned int i=0; i < tbl->capacity; i++) {
      cout << "[" << i << "]    ";
      if (!tbl->table->at(i)) {
        cout << "<empty>" << endl;
      } else if (tbl->table->at(i)->deleted) {
        cout << "<deleted>" << endl;
      } else {
        cout << "\"" << tbl->table->at(i)->key << "\" = \"" << tbl->table->at(i)->value << "\"" << endl;
      }
    }
  } else {
    cout << "    <hashtable too big to print out>" << endl;
  }
}

