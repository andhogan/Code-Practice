#include "Huffman.h"

// constructor, initialize class variables and pointers here if need.
Huffman::Huffman(){
  // your code here
}

//deconstructor,
Huffman::~Huffman(){
}

shared_ptr<freq_info> Huffman::CreateLeaf(char symbol, int count) {
  shared_ptr<freq_info> ret(new freq_info);

  ret->count = count;
  ret->symbol = symbol;
  ret->left = NULL;
  ret->right = NULL;
  ret->is_leaf = true;

  return ret;
}

shared_ptr<freq_info> Huffman::CombineNodes(shared_ptr<freq_info> left, shared_ptr<freq_info> right) {
  shared_ptr<freq_info> ret(new freq_info);

  ret->left = left;
  ret->right = right;
  ret->symbol = NULL;
  ret->count= left->count + right->count;
  ret->is_leaf = false;

  return ret;

}

void Huffman::IncrementLookup(map<char, int>& lookup, char symbol) {

  if (lookup[symbol]){
    lookup[symbol] ++;
  }
  else{
    lookup[symbol] = 1;
  }
}

void Huffman::LoadQueue(const map<char, int>& lookup, tree_queue& q) {

 for (auto i = lookup.begin(); i != lookup.end(); i++){

  auto ret = CreateLeaf(i->first, i->second);
  q.push(ret);
}
}


shared_ptr<freq_info> Huffman::BuildTree(tree_queue& q) {
  shared_ptr<freq_info> root(new freq_info);


  while (q.size() > 1){
    shared_ptr<freq_info> left = q.top();
    q.pop();
    shared_ptr<freq_info> right = q.top();
    q.pop();
    shared_ptr<freq_info> root = CombineNodes(left, right);
    root->left = left;
    root->right = right;
    q.push(root);

  }
  return q.top();
}


  

void Helper(shared_ptr<freq_info> current, string temp, map<char, string> &enc_table) {


if(!current->left && !current->right){
  enc_table[current->symbol] = temp;
  return;
  }
 else if (!current){
   return;
 } 
  
  
  Helper(current->left, temp + LEFT_CHAR, enc_table);
 
  Helper(current->right,temp + RIGHT_CHAR, enc_table);

}

map<char, string> Huffman::BuildEncodingTable(shared_ptr<freq_info> root) {
string temp = "";
map<char, string> enc_table;

Helper(root, temp, enc_table) ;

return enc_table;

  
}


string Huffman::Encode(map<char, string> enc_table, string input) {

  string output = "";

  for (int i = 0; i<input.size(); i++){
    char chary = input[i];
    output += (enc_table[chary]);
  }
  return output;
}


string Huffman::Decode(shared_ptr<freq_info> root, string input) {
 string output = "";

shared_ptr<freq_info> current = root;

if (!root){
   return output;
 }
for(int pos= 0; pos < input.size(); pos++) {

if(input[pos] == '.') {
  current = current->left;
}
else{
  current = current->right;
}
if (!current->left && !current->right){
  output += current->symbol;
  current = root;
}
}
return output;
  
}

