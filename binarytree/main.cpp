#include "binarysearchtree.hpp"
#include <iostream>

int main()
{
  std::cout << "prva" << std::endl;
  bSearchTree<int> a;
  a.insert(5);
  a.insert(10);
  a.insert(21);
  a.insert(3);
  a.insert(1);
  std::cout << "prije printa" << std::endl;
  a.print();
  std::cout << std::endl;
  return 0;
}
