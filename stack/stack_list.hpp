#pragma once
#include <assert.h>
#include <iostream>

template <typename T>
class stack_list {
  public:
  stack_list() = default;
  stack_list(const stack_list& o) {
    if (stack_top_ != nullptr) {
      auto temp = stack_top_;
      while (stack_top_ != nullptr) {
        stack_top_ = stack_top_->link_;
        delete temp;
        temp = stack_top_;
      }
    }
    // if (o.stack_top_ == nullptr) {
    //   stack_top_ = nullptr;
    // }
    // std::cout << "copy ctor, o.size(): " << o.size_ << std::endl;
    stack_list temp_stack;
    size_t counter = o.size_;
    auto temp = o.stack_top_;
    while (counter != 0) {
      temp_stack.push(temp->info_);
      temp = temp->link_;
      counter--;
    }
    counter = temp_stack.size_;
    temp = temp_stack.stack_top_;
    while (counter != 0) {
      push(temp->info_);
      temp = temp->link_;
      counter--;
    }
  }
  stack_list(stack_list&& o) {
    size_ = o.size_;
    stack_top_ = o.stack_top_;
    o.stack_top_ = nullptr;
    o.size_ = 0;
  }
  stack_list& operator=(const stack_list& o) {
    if (stack_top_ != nullptr) {
      auto temp = stack_top_;
      while (stack_top_ != nullptr) {
        stack_top_ = stack_top_->link_;
        delete temp;
        temp = stack_top_;
      }
    }
    stack_list temp_stack;
    size_t counter = o.size_;
    auto temp = o.stack_top_;
    while (counter != 0) {
      temp_stack.push(temp->info_);
      temp = temp->link_;
      counter--;
    }
    counter = temp_stack.size_;
    temp = temp_stack.stack_top_;
    while (counter != 0) {
      push(temp->info_);
      temp = temp->link_;
      counter--;
    }

    return *this;
  }
  stack_list& operator=(stack_list&& o) {
    if (o.stack_top_ != nullptr) {
      size_ = o.size_;
      stack_top_ = o.stack_top_;
      o.stack_top_ = nullptr;
      o.size_ = 0;
    }
    return *this;
  }
  ~stack_list() {
    while (stack_top_ != nullptr) {
      auto temp = stack_top_;
      stack_top_ = stack_top_->link_;
      delete temp;
    }
  }
  void push(const T& val) {
    Node* novi = new Node;
    novi->info_ = val;
    novi->link_ = stack_top_;
    stack_top_ = novi;
    size_++;
  };
  void push(T&& val) {
    Node* novi = new Node;
    novi->info_ = std::move(val);
    novi->link_ = stack_top_;
    stack_top_ = novi;
    size_++;
  }
  T& top() {
    assert(stack_top_ != nullptr);
    return stack_top_->info_;
  }
  const T& top() const {
    assert(stack_top_ != nullptr);
    return stack_top_->info_;
  }
  void pop() {
    if (stack_top_ != nullptr) {
      auto temp = stack_top_;
      stack_top_ = stack_top_->link_;
      delete temp;
    }
  }

  size_t size() const { return size_; };
  bool empty() const { return stack_top_ == nullptr; };

  bool operator==(const stack_list& o) {
    if (size_ != o.size()) {
      return false;
    } else {
      Node* temp = stack_top_;
      Node* temp1 = o.stack_top_;
      for (size_t i = 0; i < size_; i++) {
        if (temp->info_ != temp1->info_) {
          return false;
        }
        temp = temp->link_;
        temp1 = temp1->link_;
      }
      return true;
    }
  }
  bool operator!=(const stack_list& o) { return !(*this == o); }
  stack_list& operator+(stack_list o) {
    stack_list dva;
    Node* temp = o.stack_top_;
    for (size_t i = 0; i < o.size(); i++) {
      dva.push(temp->info_);
      temp = temp->link_;
    }
    temp = dva.stack_top_;
    for (size_t i = 0; i < dva.size(); i++) {
      push(temp->info_);
      temp = temp->link_;
    }

    return *this;
  }

  private:
  struct Node {
    T info_;
    Node* link_;
  };
  size_t size_ = 0;
  Node* stack_top_ = nullptr;
  // Node* last_ = nullptr;
};

template <typename U>
std::ostream& operator<<(std::ostream& o, stack_list<U> a) {
  size_t condition = a.size();
  while (condition != 0) {
    std::cout << a.top() << " ";
    a.pop();
    condition--;
  }
  return o;
}

