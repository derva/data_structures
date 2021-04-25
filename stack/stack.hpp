#include <iostream>
#include <algorithm>

template<typename T>
class Stack{
public:
  Stack(): arr_ptr_{new T[capacity_]}{}
  Stack(size_t size) 
    : capacity_{size}, arr_ptr_{new T[capacity_]} {};

  Stack(const Stack<T>& o): stack_top_{o.stack_top_}{
    delete[] arr_ptr_;
    arr_ptr_ = new T[stack_top_]; 
    for(int i = 0; i < stack_top_; i++){
      arr_ptr_[i] = o.arr_ptr_[i];
    }
  }
  ~Stack(){
    delete[] arr_ptr_;
  };

  void push(const T& element){
    // std::cout << "push" << stack_top_ << std::endl;
    arr_ptr_[stack_top_] = element;
    stack_top_++;
    // size_++;
  }
  T& top() { return arr_ptr_[stack_top_ - 1]; }
  void pop(){
    if(empty()){
    }
    else{
    stack_top_--;
    // size_--;
    }
  }
  bool empty() const{
    return stack_top_ == 0;
  }
  size_t size() {
    return stack_top_;
  }


private:
  // size_t size_ = 0;
  size_t capacity_ = 100;
  size_t stack_top_ = 0;
  T* arr_ptr_ = nullptr;
};
