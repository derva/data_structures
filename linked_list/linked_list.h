#include <iostream>

template<typename T>
struct Node{
public:
  Node() = default;
  Node(const T& e) : info_{e} {}

  T info_;
  Node* next_ = nullptr;
  class iterator{
  public:
    iterator() = default;
    iterator(Node<T>* nodeptr){
      current = nodeptr;
    }
    //it1 = head.begin();
    //it1++
    iterator operator++(){
      current = current->next_;
      return *this;
    }
    T operator*(){
      return current->info_;
    }
    // auto it1 = head.begin();
    // auto it2 = head.end();
    // it != it2
    bool operator!=(const Node<T>::iterator& other){
      return current == other.current;
    }
  private:
    Node<T>* current;
  };
private:
};
