#include "Vector10.h"
#include <iostream>

using namespace std;

Vector10::Vector10(){ // Constructor
    pb_index = 0; // set to 0, nothing should be in this array, 
                  // and we want to push_back to the last index.

    //initialize with 10 0's in the vector
    for (int i = 0; i < 10; i++){
        my_vect[i] = 0;
    }
 
}   

Vector10::~Vector10(){
    // Destructor
}

// Implement this function first, since all tests use it.
int Vector10::ValueAt(int index){
    if (index < 10){ //index values range from 0-9
        return my_vect[index]; // return value @ index location
    }
    else {
        cout << "Error: Index out of bounds." << endl;
        return -1;
    }
}

// Implement this function second, since most tests use it.
bool Vector10::PushBack(int value){
    if (pb_index >= 10){ // index values range from 0-9
        cout << "Vector full, cannot push back." << endl;
        return false;
    }
    else {
        my_vect[pb_index] = value;
        pb_index++;
        return true;
    }
}

int Vector10::CountEmpty(){
    int sum = 0;
    int i;

    for(i = pb_index; i < 10; i++){ 
        sum++;
    }
    cout << "Empty spaces: " << sum << endl;
    return sum;

    // if(pb_index == 10){ // vector size is 10, and pb_index marks location ahead of last value
    //     cout << "Vector full." << endl;
    //     return 0;
    // }
    // else{
    //     // start count at pb_index and go all the way to before 10
        
        
    // }
    // return sum;
}

bool Vector10::Search(int value){
    int i;

    // iterate through the vector until the pb_index is reached
    for (i = 0; i < pb_index; i++){
        if(my_vect[i] == value){
            cout << "Value " << value << " found at index " << i << endl;
            return true;
        }
    }
    cout << "Value not in the set." << endl;
    return false;
}



bool Vector10::Remove(int index){
    if (index >= pb_index){
        cout << "Index out of bounds, no value to extract." << endl;
        return false;
    }
    else{
        for (int i = index; i < pb_index - 1; i++) {
            my_vect[i] = my_vect[i + 1];
        }
    }
    cout << "Removed value at index " << index << endl;
    pb_index--;
    return true;
}

// Vector10::PrintMembers(void){
//     unsigned int i;
//     cout << "Current my_vect: ";
//     for (i = 0; i < pb_index; i++) {
//         cout << my_vect.ValueAt(i) << ", ";
//     }
//     cout << endl;
// }

// int Vector::GetPBIndex(void){
//     return pb_index;
// }