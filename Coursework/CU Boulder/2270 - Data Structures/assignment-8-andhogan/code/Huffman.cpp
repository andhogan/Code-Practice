#include "Huffman.h"

// constructor, initialize class variables and pointers here if need.
Huffman::Huffman(){
  // your code here
}

//deconstructor,
Huffman::~Huffman(){
}

shared_ptr<freq_info> Huffman::CreateLeaf(char symbol, int count) {
  shared_ptr<freq_info> newLeaf(new freq_info);
  //Leaf nodes contain both the character "symbol" and the number of times it appears in the text.
  newLeaf->symbol = symbol;
  newLeaf->count = count;
  newLeaf->left = NULL;
  newLeaf->right = NULL;
  newLeaf->is_leaf = true;
  return newLeaf;
}

shared_ptr<freq_info> Huffman::CombineNodes(shared_ptr<freq_info> left, shared_ptr<freq_info> right) {
  shared_ptr<freq_info> newIntNode(new freq_info);
  //Internal nodes keep track of total character counts of children nodes, and do not contain symbols themselves
  //They also have left and right pointers to children nodes to allow for traversal. These are NOT leaf nodes
  newIntNode->symbol = NULL;
  newIntNode->count = left->count + right->count;
  newIntNode->left = left;
  newIntNode->right = right;
  newIntNode->is_leaf = false;
  return newIntNode;
}

void Huffman::IncrementLookup(map<char, int>& lookup, char symbol) {
  lookup[symbol] += 1;
}

void Huffman::LoadQueue(const map<char, int>& lookup, tree_queue& q) {
  for (auto it = lookup.cbegin(); it != lookup.cend(); ++it) 
  {//Iterate through the map and create freq_info nodes that wil push onto the priority queue
    char k = (*it).first;
    int v =  (*it).second;

    //create new leaf nodes using the character k and frequency value v
    shared_ptr<freq_info> newNode = CreateLeaf(k, v);

    //Then push onto the priority queue, the push command pushes it to the right spot. 
    //Important to remember: LEAST FREQUENT characters are AT THE TOP
    q.push(newNode);
  }

}

shared_ptr<freq_info> Huffman::BuildTree(tree_queue& q) {
  //A root node keeps track of the top of the Huffman Codec Tree
  shared_ptr<freq_info> root(new freq_info);

  while (q.size() > 1)
  {//Iterate through the queue, popping off two nodes at a time and combining them using a greedy algorithm
    shared_ptr<freq_info> left = q.top();
    q.pop();
    shared_ptr<freq_info> right = q.top();
    q.pop();
    //The front of the queue contains the least frequent characters.
    //Root will "combine" these nodes and become an internal node keeping track of the number of characters in its children.
    shared_ptr<freq_info> root = CombineNodes(left, right);
    root->left = left;
    root->right = right;
    //We then push this combined node back onto the priority queue to be pulled again shortly.
    q.push(root);
  }
  return q.top();
}

map<char, string> Huffman::BuildEncodingTable(shared_ptr<freq_info> root) 
{
  string temp = "";
  map<char, string> enc_table;

  TreeTraversalRecursive(root, temp, enc_table);

  return enc_table;
}

string Huffman::Encode(map<char, string> enc_table, string input) 
{
  string output = ""; //Output is the encoded string being returned. 
                      //Iterating over the input string will append characters to this.
  char input_char;    //The variable that will hold input characters as keys to access the encoding table.

  for (int i = 0; i<input.size(); i++)
  {//Iterate over the characters in the string input, appending the string bit rep value associated with that char key.
    input_char = input[i];
    output += enc_table[input_char]; //accessing the table with the key yields a series of '.' ad '^' that append to the output.
  }

  return output;
}

string Huffman::Decode(shared_ptr<freq_info> root, string input) 
{//Working backwards, we trace the encoded string to leaf nodes.
//Once a leaf node has been found, we append its symbol/character to the output string
//and reset our search to the top node.

  string output = "";
  shared_ptr<freq_info> currNode = root;

  if(!root)
  {//Safety base case for if the tree is empty
    return output;
  }

  for(int i = 0; i < input.size(); i++)
  {//iterate over the encoded message, traversing the tree left for each '.' and right for each '^'
    if(input[i] == '.')
    {//If the char is '.', go left
      currNode = currNode->left;
    }
    else
    {//if the char isn't '.', it can only be '^'. Go right.
      currNode = currNode->right;
    }

    if(currNode->is_leaf)
    {//Once we encounter a leaf, append the symbol within the node to the output
     //then return currNode to the root to traverse again.
      output += currNode->symbol;
      currNode = root;
    }
  }
  return output;
}


//HELPER FUNCTIONS

  void Huffman::TreeTraversalRecursive(shared_ptr<freq_info> currNode, string temp, map<char, string> &enc_table)
  {//Recursively traverses the Huffman Encoding Tree
   //Once we reach a leaf node, we want to be able to map a string encoding to it. 
   //Earlier/More frequent leaf nodes thus receive smaller bit string reps than uncommon ones.

    if(currNode->is_leaf)
    {//If the node has is_leaf set to true,
     //Map the leaf node's symbol and bit string rep to the encoding table:
      enc_table[currNode->symbol] = temp;
      return;
    }
    else if (!currNode)
    {//If the node we are looking at happens to be NULL, nothing is to be done.
     //This case occurs when an internal node has either a left or right child, but not both.
      return;
    } 
  
  //Recursively call the helper function on the left and right children
  //while also updating the string accordingly to the direction we move in the tree.

  //      root
  //  '.' /  \ '^'
  //  left    right
  TreeTraversalRecursive(currNode->left, temp + LEFT_CHAR, enc_table);
 
  TreeTraversalRecursive(currNode->right,temp + RIGHT_CHAR, enc_table);

  }