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
    for(size_t i = 0; i < stack_top_; i++){
      arr_ptr_[i] = o.arr_ptr_[i];
    }
  }
  Stack(Stack<T>&& o) : arr_ptr_{o.arr_ptr_} {
    o.arr_ptr_ = nullptr;
  }
  ~Stack(){
    delete[] arr_ptr_;
  };


  void push(const T& element){
    if(stack_top_ == capacity_){
      reallocate((capacity_*2));
    }
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
  size_t capacity(){
    return capacity_;
  }


private:

  void reallocate(size_t size){
    T* new_arr = new T[size];
    for(size_t i = 0; i < stack_top_; i++){
      new_arr[i] = arr_ptr_[i];
    }
    delete[] arr_ptr_;
    arr_ptr_ = new_arr;
    new_arr = nullptr;
    capacity_ = size;
  }

  // size_t size_ = 0;
  size_t capacity_ = 100;
  size_t stack_top_ = 0;
  T* arr_ptr_ = nullptr;
};
