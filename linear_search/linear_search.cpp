#include <iostream>


template<typename T>
// T linearSearch(T arr[],int size, T w){
void linearSearch(T arr[],int size, T w){
  bool found = false;
  for(int i = 0; i < size; i++){
    if(arr[i] == w){
      std::cout << "Element " << w << " found at " << i + 1 << " position" << std::endl;
      found = true;
      // return arr[i];
    }
  }
  if(!found) std::cout << "Oops, looks like there is not " << w << " element in this arr" << std::endl;
}

template<typename T>
void printArray(T arr[], int size){
  std::cout << "Array: ";
  for(int i = 0; i < size; i++){
    std::cout << i << " ";  
  }
  std::cout << std::endl;
}

int main(){
  int arr[10] = {1,2,3,33, 4,432,53,234, 10, 69};
  printArray<int>(arr, 10);
  linearSearch<int>(arr, 10, 3);
  linearSearch<int>(arr, 10, 0);
  return 0;
}


