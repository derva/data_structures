#include <iostream>
#include <vector>
#include "linked_list.h"


int main()
{
  Node<int>* newNode, *first, *last;
  first = nullptr;
  // head->info_ = 5;
  // head->next_ = new Node<int>{2};
  std::cout <<"Enter value: ";
  int value = 0;
  std::cin >> value;
  while ( value != -999) {
    newNode = new Node<int>{value};

    if( first != nullptr){
      last->next_ = newNode;
      last = newNode;
    }
    else{
      first = newNode;
      last = newNode;
    }

    std::cout << "Successful!\nEnter new value or -999: ";
    std::cin >> value;
  }
  std::cout << "Linked list members: " << std::endl;
  Node<int>::iterator lastIt{last->next_};
  for(Node<int>::iterator ptr{first}; ptr != lastIt; ++ptr){
    std::cout << *ptr << std::endl; 
  }
  std::cout << "END" << std::endl;
  return 0;
}
