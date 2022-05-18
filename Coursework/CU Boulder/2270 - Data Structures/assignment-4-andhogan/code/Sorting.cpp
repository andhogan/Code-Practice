#include "Sorting.h"

/*
  Please refer to sorting.h for documentation on each function.

   + ------ N O T E: -- Big scary warning! -----------------------------\
   |                                                                    |
   |    We clearly can't use unit testing to ensure that you're         |
   |    actually implementing the correct algorithm. I suppose we could |
   |    write some complicated static analysis checker. But it is       |
   |    easier to just look at it with our eyeballs.                    |
   |                                                                    |
   |    After the assignment is due, we will look at the most recent    |
   |    version of your implementation that got the highest score and   |
   |    make sure you're not doing something sneaky like using a        |
   |    standard library call to sort a vector.                         |
   |                                                                    |
   |    Anyone caught doing this (even though it is kinda funny) will   |
   |    be given 0 points on the assignment.                            |
   |                                                                    |
   `--------------------------------------------------------------------/ 
*/

// constructor, initialize class variables and pointers here if you need.
Sorting::Sorting(){
  // Your code here
}

//deconstructor,
Sorting::~Sorting(){
}

void Sorting::quicksort(vector<int>& data, int low_idx, int high_idx){
  //Base Case:
  // If partition size is 1 or 0 elements, partition is sorted:
  if (low_idx >= high_idx) return;

  //Otherwise, partition data within the array provided.

  // The quicksort_partition function returns the index of the last element
  // of the lower partition.

  int lowPartIdx = quicksort_partition(data, low_idx, high_idx);

  // Recursively sort low and high partitions, 
  // lowPartIdx+1 is the starting element of the high partition
  quicksort(data, low_idx, lowPartIdx);
  quicksort(data, lowPartIdx+1, high_idx);

}

int Sorting::quicksort_partition(vector<int>& data, int low_idx, int high_idx){
  //Pick the middle element as the pivot
  int midpoint = low_idx + (high_idx - low_idx)/2;
  int pivot = data[midpoint];

  bool done = false;
  while(!done) { // Loop while low end index is less than the high end index
                 // Exploit a boolean as a switch for the conditional check later

    // Increment low index while data[low index] < pivot
    while(data[low_idx] < pivot) { 
      low_idx++;
    }

    // Decrement high index while pivot < data[high index]
    while(pivot < data[high_idx]) {
      high_idx--;
    }
    
    //If zero or one elements remain, numbers are partiitioned.
    //Switch done boolean to true to exit while loop.
    if (low_idx >= high_idx){
      done = true;
    }

    else { // Not done partitioning, so sort values via swapping low and high instead
      int temp = data[low_idx];
      data[low_idx] = data[high_idx];
      data[high_idx] = temp;

      // Update low and high indices to continue paritioning, or until done.
      low_idx++;
      high_idx--;
    }
  }
    
  //Return the high index of the low partition when done=true
  return high_idx;

}

void Sorting::bubblesort(vector<int>& data){
  int size = data.size(); //Sorting algorithm depends on the size of the vector for the loops
  int i;
  int j;
  int temp;

  for (i = 0; i < size; i++){ // Outer loop
    for (j = 0; j < size - i - 1; j++){
      if (data[j] > data[j+1]){
        temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }

}

void Sorting::mergesort(vector<int>& data){
  //Base Case:
  // If the inserted data array is of size 1 or less, the array is sorted, return.
  if (data.size() <= 1) return;

  //Find the midpoint of the array:
  int mid_idx = data.size()/2;

  //We can use the vector functions .begin() and .end() 
  // to retrieve the first and last indices of the vector

  //We can use them to initialize new vectors that are partitions of the original
  //Ex: data.size() = 10, indices range [0, 9]
  //    mid_idx = 5
  //    left(0, 9-5) = (0, 4)
  //    right(0 + 5, 9) = (5, 9)
  vector<int> left(data.begin(), data.end() - mid_idx);
  vector<int> right(data.begin() + mid_idx, data.end());

  //Recursively merge_sort the left and right partitions
  mergesort(left);
  //  left.size() = 5, indices range [0, 4]
  //  mid_idx = 2
  //  left(0, 2)
  //  right(3, 4)
  mergesort(right);
  //  right.size() = 5, indices range [5, 9]
  //  mid_idx = 7
  //  left(5, 7)
  //  right(8, 9)

  //When mergesorts are finished, the returned left and right arrays will be merged.
  //Merging is simulated by replacing the elements in the original vector using pass by reference.
  merge(left, right, data);
}

void Sorting::merge(vector<int>& left, vector<int>& right, vector<int>& result){
  // Traverse the left and right vectors using "two-finger" index pointers
  // Using the vectors' sizes to keep track of position
  int leftSize = left.size();
  int rightSize = right.size();
  int leftPos = 0; //keep track of starting element in left
  int rightPos = 0; //keep track of starting element in right
  int dataPos = 0; //keep a third finger pointing to each result position

  // Using a while loop, we iterate through each element in both left and right vecs.
  // If the index of one vector ever equals the size, we know we've reached the end
  // and will break from this loop to append the rest of the other vector.

  while(leftPos < leftSize && rightPos < rightSize){ // check that indices are still valid
    // check if left element is smaller than right
    if (left[leftPos] < right[rightPos]){ 
      // If so, set left element into the data vector, 
      // and increment the leftPos index pointer
      result[dataPos] = left[leftPos];
      leftPos++;
    } 
    else { // right element is smaller than left, and increment right pointer
      result[dataPos] = right[rightPos];
      rightPos++;
    }
    //Afterwards, increment the dataPos to move to the next position
    dataPos++;
  }

  // When we leave the above while loop, we know we've reached the end of one vector 
  // and will now append the other.
  while(leftPos < leftSize){ //append rest of left vector if any remain
    result[dataPos] = left[leftPos];
    leftPos++;
    dataPos++;
  }
  while(rightPos < rightSize){ //append rest of right vector if any remain
    result[dataPos] = right[rightPos];
    rightPos++;
    dataPos++;
  }
}

// Selection Sort implementation
void Sorting::mystery_sort(vector<int>& data){
  
  // Selection Sort implementation

  // Use the size of the array to control the for loop iteration
  int size = data.size();

  int i; //outer loop iterator and index pointer
  int j; //inner loop iterator and index pointer
  int smallest_idx; // index pointer to the smallest element in the list, starting with the beginning
  int temp; // placeholder for the swap

  //Iterate i < size-1 times until i reaches the last element.
  // By the time i reaches the last element, the list will have been sorted.
  for (i = 0; i < size-1; i++){
    // start smallest index at the beginning with i, 
    // since this is the smallest element until it is compared later.
    smallest_idx = i; 

    //Next, the inner loop finds the smallest element in the list.
    //use j to loop into the unsorted part of the list, starting ahead of i
    for (j = i+1; j < size; j++){
      // If the element at j is smaller than the smallest_idx element, 
      // set element j to be the smallest.
      if (data[j] < data[smallest_idx]) {smallest_idx = j;}
    }

    // After inner loop has finished a lap, 
    // swap the element at i and the smallest element
    temp = data[i];
    data[i] = data[smallest_idx];
    data[smallest_idx] = temp;
  }

  
}