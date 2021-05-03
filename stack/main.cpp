#include "stack_array.hpp"

template<typename T>
void print(Stack<T> o){
  size_t condition = o.size();
  std::cout << "The elements of Stack: ";
  for(size_t i = 0; i < condition; i++){
    // std::cout << "Info: " << o.top() << " " << o.size() << std::endl;
    std::cout << o.top() << " ";
    o.pop();
  }
  std::cout << std::endl;
}

int main() {
  Stack<int> b;
  b.push(5);
  b.push(5);
  Stack<int> a(50);
  Stack<int> dummy{2};
  dummy.push(85);
  dummy.push(85);
  dummy.push(85);
  dummy.push(85);
  dummy.push(85);
  dummy.push(85);
  dummy.push(85);
  dummy.push(85);
  dummy.push(75);
  print(dummy);
  a.push(85);
  a.push(28);
  a.push(56);
  print(a);
  Stack<double> nova;
  nova.push(5);
  nova.push(35);
  nova.push(72);
  print(nova);
  std::cout << std::endl;
  return 0;
}

