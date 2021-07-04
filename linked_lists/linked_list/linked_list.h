#pragma once
#include <iostream>

template <typename T>
class List {
  public:
  List() = default;
  List(const List& other){
    Node* newNode;
    Node* current;
    if( first_ != nullptr){
     destroy(); 
    }
    if( other.first_ == nullptr){
      first_ = last_ = nullptr;
      size_ = 0;
    }
    else{
      size_ = other.size_;
      current = other.first_;
      first_ = new Node();
      first_->info_ = current->info_;
      first_->next_ = nullptr;
      last_ = first_;
      current = current->next_;
      while( current != nullptr){
        newNode = new Node();
        newNode->info = current->info_;
        newNode->next_ = nullptr;
        last_->next_ = newNode;
        last_ = newNode;
        current = current->next_;
      }
    }
  }
  ~List() {
    Node* temp;
    while (first_ != nullptr) {
      temp = first_;
      first_ = first_->next_;
      delete temp;
    }
    last_ = nullptr;
    size_ = 0;
  }
  void destroy() {
    Node* temp;
    while (first_ != nullptr) {
      temp = first_;
      first_ = first_->next_;
      delete temp;
    }
    last_ = nullptr;
    size_ = 0;
  }
  void push_back(const T& element) {
    if (first_ == nullptr) {
      first_ = new Node;
      first_->info_ = element;
      first_->next_ = nullptr;
      last_ = first_;
    } 
    else {
      Node* novi = new Node;
      novi->info_ = element;
      novi->next_ = nullptr;
      last_->next_ = novi;
      last_ = novi;
    }
    size_++;
  }
  void print() const {
    Node* temp = first_;
    while (temp != nullptr) {
      std::cout << temp->info_ << std::endl;
      temp = temp->next_;
    }
  }
  size_t size() { return size_; }
  struct Node {
public:
    Node() = default;
    Node(const T& e) : info_{e} {}

    T info_;
    Node* next_ = nullptr;
    size_t size_ = 0;
  };
  class iterator {
public:
    iterator() : current{nullptr} {}
    iterator(Node* other) { current = other; }
    iterator(const iterator& other) { current = other.current; }
    T& operator*() { return current->info_; }
    iterator operator++() {
      current = current->next_;
      return *this;
    }
    bool operator==(const iterator& other) { return current == other.current; }
    bool operator!=(const iterator& other) { return current != other.current; }

private:
    Node* current;
  };

  private:
  Node* first_ = nullptr;
  Node* last_ = nullptr;
  size_t size_ = 0;
  // int capacity = 0;
public:
  iterator begin(){
    return iterator{first_};
  }
  iterator end(){
    return iterator{last_->next_};
  }
};
