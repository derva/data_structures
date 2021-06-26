#pragma once
#include <iostream>

template <typename T>
class queue {
  public:
  queue() {
    link_ = new T[capacity_];
    front_ = 0;
    back_ = capacity_ - 1;
  }
  queue(size_t c) {
    // if (c <= 0) {
    //   c = 100;
    // }
    capacity_ = c;
    link_ = new T[capacity_];
    front_ = 0;
    back_ = capacity_ - 1;
    size_ = 0;
  }
  queue(const queue& o) {
    size_ = o.size_;
    capacity_ = o.capacity_;
    link_ = new T[capacity_];
    for (int i = 0; i < o.size(); i++) {
      link_[i] = o.link_[i];
    }
    front_ = o.front_;
    back_ = o.back_;
  }
  queue(queue&& o) {
    link_ = o.link_;
    size_ = o.size_;
    capacity_ = o.capacity_;
    front_ = o.front_;
    back_ = o.back_;
    o.size_ = o.capacity_ = o.front_ = o.back_ = 0;
    o.link = nullptr;
  }
  queue& operator=(const queue& o) {
    size_ = o.size_;
    capacity_ = o.capacity_;
    link_ = new T[capacity_];
    for (int i = 0; i < o.size(); i++) {
      link_[i] = o.link_[i];
    }
    front_ = o.front_;
    back_ = o.back_;
    return *this;
  }
  queue& operator=(queue&& o) {
    link_ = o.link_;
    size_ = o.size_;
    capacity_ = o.capacity_;
    front_ = o.front_;
    back_ = o.back_;
    o.size_ = o.capacity_ = o.front_ = o.back_ = 0;
    o.link = nullptr;
    return *this;
  }
  ~queue() { delete[] link_; }
  template <typename U>
  void push(U&& e) {
    if (isFull()) {
      throw std::out_of_range{"Exception: The container is full!"};
    } else {
      back_ = (back_ + 1) % capacity_;
      // std::cout << back_ << std::endl;
      link_[back_] = std::forward<U>(e);
      size_++;
    }
  }
  T pop() {
    if (isEmpty()) {
      throw std::out_of_range{"Exception: The container is full!"};
    }
    // else{
    T elem = link_[front_];
    front_ = (front_ + 1) % capacity_;
    size_--;
    // }
    return elem;
  }
  T& top() { return link_[back_]; }
  const T& top() const { return link_[back_]; }
  bool isEmpty() { return size_ == 0; }
  bool isFull() { return size_ == capacity_; }
  size_t size() const { return size_; }
  size_t capacity() { return capacity_; }

  private:
  int front_;
  int back_;
  size_t capacity_ = 100;
  size_t size_ = 0;
  T* link_ = nullptr;
};
