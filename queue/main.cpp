#include "queue.hpp"
#include <stdexcept>

int main(void)
{
  try{
  // queue<int> l{2};
  queue<int> l;
  std::cout << "Capacity: " << l.capacity() << std::endl;
  for (int i = 1;  i < 10; ++i) {
    l.push(i);
    // std::cout << "e" << std::endl;
  }
  // std::cout <<"Before " <<  l.size() << std::endl;
  // int el =  l.pop();
  // std::cout << "element" << el << std::endl;
  // el =  l.pop();
  // std::cout << "element" << el << std::endl;
  std::cout <<"After " << l.size() << std::endl;
  queue<int> second_cont{l};
  std::cout << "second_cont.size() " << second_cont.size();
  std::cout << "\nsecond_cont elements" << std::endl;
  int counter = l.size();
  for( int i = 0; i < counter; i++){
    std::cout << l.pop() << std::endl;
  }
  std::cout<<"second_cont" << std::endl;
  counter = second_cont.size();
  for( int i = 0; i < counter; i++){
    std::cout << second_cont.pop() << std::endl;
  }
  std::cout << std::endl;
  }
  catch( std::out_of_range& o){
    std::cerr << o.what() << '\n';
  }
  return 0;
}

