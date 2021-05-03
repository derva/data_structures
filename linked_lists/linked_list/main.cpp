#include "linked_list.h"


int main()
{
  List<int> a;  
  a.push_back(5);
  a.push_back(25);
  a.push_back(55);
  a.push_back(26);
  a.push_back(0);
  a.push_back(274);
  auto e = a.begin();
  a.print();
  std::cout << "END" << std::endl;
  return 0;
}
