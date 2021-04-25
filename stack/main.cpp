#include "stack.hpp"
//
// template<typename T>
// void print(Stack<T> e){
//   std::cout << "Size je: " <<e.size() << std::endl;
//   for(size_t i = 0; i <= e.size(); i++){
//     std::cout << e.top() << " ";
//     e.pop();
//     // size 4
//     // 4 
//     // e.top() e[3]
//     // stack top 3
//     // 
//   }
//   std::cout << std::endl;
// }
//
// int main()
// {
//   Stack<int> e{5};
//   e.push(5);
//   e.push(27);
//   e.push(545);
//   e.push(25);
//   print(e);
//   Stack<int>b{e};
//   print(b);
//   std::cout << "velicina je sada" << e.size() << std::endl;
//   return 0;
// }
void testCopyConstructor(Stack<int> otherStack);
int main()
{
Stack<int> a(50);
Stack<int> copyStack(50);
Stack<int> dummyStack(100);
a.push(85);
a.push(28);
a.push(56);
copyStack = a; //copy a into copyStack
std::cout << "The elements of copyStack: ";
while (!copyStack.empty()) //print copyStack
{
  std::cout << copyStack.top() << " ";
copyStack.pop();
}
std::cout << std::endl;
copyStack = a;
testCopyConstructor(a);
//test the copy constructor
if (!a.empty())
std::cout << "The original a is not empty." << std::endl
<< "The top element of the original a: "
<< copyStack.top() << std::endl;
dummyStack = a;
//copy a into dummyStack
std::cout << "The elements of dummyStack: ";
while (!dummyStack.empty()) //print dummyStack
{
  std::cout << dummyStack.top() << " ";
dummyStack.pop();
}
std::cout << std::endl;
return 0;
}
void testCopyConstructor(Stack<int> otherStack)
{
if (!otherStack.empty())
std::cout << "otherStack is not empty." << std::endl
<< "The top element of otherStack: "
<< otherStack.top() << std::endl;
}
