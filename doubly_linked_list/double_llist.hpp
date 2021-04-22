#pragma once
#include <iostream>

template <typename T>
class List {
  public:
  List() : head_{nullptr}, tail_{nullptr}, sentinel{nullptr} {
    std::cout << "Default constructor" << std::endl;
  };
  // copy ctor
  List(const List<T>& other) {
    std::cout << "Copy constructor" << std::endl;
    if (other.size_ == 0) {
    } else {
      size_t counter = 0;
      auto temp = other.head_;
      while (counter != other.size_) {
        T value = temp->element_;
        if (head_ == nullptr) {
          auto temp_cont = new Node{value, nullptr, nullptr};
          head_ = tail_ = temp_cont;
        } else {
          auto temp_cont = new Node{value, nullptr, tail_};
          tail_->next_ = temp_cont;
          tail_ = temp_cont;
        }
        temp = temp->next_;
        counter++;
      }
      sentinel = new Node{};
      tail_->next_ = sentinel;
      sentinel->back_ = tail_;
      size_ = other.size_;
    }
  }
  // move copy ctor
  List(List<T>&& other) {
    std::cout << "Move copy constructor" << std::endl;
    if (other.size_ == 0) {
    } else {
      head_ = other.head_;
      tail_ = other.tail_;
      sentinel = other.sentinel;
      // tail_->next_ = sentinel;
      // sentinel->back_ = tail_;
      size_ = other.size_;
      other.head_ = other.tail_ = nullptr;
      other.size_ = 0;
    }
  }
  // operator=
  List& operator=(const List<T>& other) {
    std::cout << "Operator=" << std::endl;
    if (other.size_ == 0) {
      return *this;
    }
    if (!(empty())) {
      Node* temp;
      Node* temp2 = head_;
      while (size_ != 0) {
        temp = temp2->next_;
        delete temp2;
        temp2 = temp;
        size_--;
      }
    }
    size_t counter = 0;
    head_ = tail_ = sentinel = nullptr;
    auto temp = other.head_;
    while (counter != other.size_) {
      T value = temp->element_;
      if (head_ == nullptr) {
        auto temp_cont = new Node{value, nullptr, nullptr};
        head_ = tail_ = temp_cont;
      } else {
        auto temp_cont = new Node{value, nullptr, tail_};
        tail_->next_ = temp_cont;
        tail_ = temp_cont;
      }
      temp = temp->next_;
      counter++;
    }
    sentinel = new Node{};
    tail_->next_ = sentinel;
    sentinel->back_ = tail_;
    size_ = other.size_;
    return *this;
  }
  // move operator=
  List& operator=(List<T>&& other) {
    std::cout << "Move operator=" << std::endl;
    if (other.size_ == 0) {
      return *this;
    }
    std::cout << "Move operator= List<T>&&" << std::endl;
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    sentinel = other.sentinel;
    other.size_ = 0;
    other.tail_ = other.head_ = nullptr;
    other.sentinel = nullptr;
    return *this;
  }

  size_t size() { return size_; }

  void push_back(const T& element) {
    if (head_ == nullptr) {
      head_ = new Node{element, nullptr, nullptr};
      tail_ = head_;
      sentinel = new Node{};
      tail_->next_ = sentinel;
      sentinel->back_ = tail_;
      sentinel->next_ = nullptr;
    } 
    // Imamo sentinel/cuvara pa nam ovaj if postajre nepotreban
    // else if (head_->next_ == nullptr && head_->back_ == nullptr) {
    //   auto novi = new Node{element, nullptr, tail_};
    //   head_->next_ = novi;
    //   tail_ = novi;
    //   tail_->next_ = sentinel;
    //   sentinel->back_ = tail_;
    // } 
    else {
      Node* novi = new Node{element, nullptr, tail_};
      tail_->next_ = novi;
      tail_ = novi;
      tail_->next_ = sentinel;
      sentinel->back_ = tail_;
    }
    size_++;
  }
  void push_back(T&& element) {
    if (head_ == nullptr) {
      head_ = new Node{std::move(element), nullptr, nullptr};
      tail_ = head_;
      sentinel = new Node{};
      tail_->next_ = sentinel;
      sentinel->back_ = tail_;
      sentinel->next_ = nullptr;
    } else if (head_->next_ == nullptr && head_->back_ == nullptr) {
      auto novi = new Node{std::move(element), nullptr, tail_};
      head_->next_ = novi;
      tail_ = novi;
    } else {
      Node* novi = new Node{std::move(element), nullptr, tail_};
      tail_->next_ = novi;
      tail_ = novi;
      tail_->next_ = sentinel;
      sentinel->back_ = tail_;
    }
    size_++;
  }
  void push_front(const T& element) {
    if (head_ == nullptr) {
      push_back(element);
    } else {
      Node* novi = new Node{element, head_, nullptr};
      head_->back_ = novi;
      head_ = novi;
    }
    size_++;
  }
  void push_front(T&& element) {
    if (head_ == nullptr) {
      push_back(std::move(element));
    } else {
      Node* novi = new Node{std::move(element), head_, nullptr};
      head_->back_ = novi;
      head_ = novi;
    }
    size_++;
  }
  void pop_back() {
    auto temp = tail_;
    tail_ = tail_->back_;
    tail_->next_ = sentinel;
    sentinel->back_ = tail_;
    temp->next_ = temp->back_ = nullptr;
    delete temp;
    size_--;
  }
  void pop_front() {
    auto temp = head_;
    head_ = head_->next_;
    head_->back_ = nullptr;
    delete temp;
    size_--;
  }

  private:
  size_t size_ = 0;
  struct Node {
    Node() = default;
    Node(const T& element, Node* next, Node* back)
        : element_{element}, next_{next}, back_{back} {}

    Node(const Node& other) {
      auto novi = new Node{other.element_, other.next_, other.back_};
      element_ = novi->element_;
      next_ = novi->next_;
      back_ = novi->back_;
      novi = nullptr;
    }
    Node(Node&& other) {
      element_ = other.element_;
      next_ = other.next_;
      back_ = other.back_;
      other = other.back_ = other.next_ = nullptr;
    }
    Node& operator=(const Node& other) {
      element_ = other.element_;
      next_ = other.next_;
      back_ = other.back_;
      return *this;
    }
    Node& operator=(Node&& other) {
      element_ = other.element_;
      next_ = other.next_;
      back_ = other.back_;
      other = other.back_ = other.next_ = nullptr;
      return *this;
    }
    T element_;
    Node* next_ = nullptr;
    Node* back_ = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  Node* sentinel = nullptr;

  public:
  class iterator {
public:
    // ZA RAD SA ALGORITMIMA IZ STDL
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = size_t;
    // bidirekcioni itetator
    iterator() = default;
    iterator(Node* p) : p_{p} {}
    iterator(const iterator& other) : p_{other.p_} {}
    iterator& operator=(const iterator& other) {
      p_ = other.p_;
      return *this;
    }
    iterator& operator++() {
      p_->next_;
      return *this;
    }
    iterator operator++(int) {
      auto temp = p_;
      p_ = p_->next_;
      return iterator{temp};
    }
    iterator& operator--() {
      p_ = p_->back_;
      return *this;
    }
    iterator operator--(int) {
      auto temp = p_;
      p_ = p_->back_;
      return iterator{temp};
    }
    Node* operator->() { return p_; }
    T& operator*() { return p_->element_; }
    bool operator==(const iterator& other) { return p_ == other.p_; }
    bool operator!=(const iterator& other) { return p_ != other.p_; }

private:
    Node* p_ = nullptr;
  };
  bool empty() { return size_ == 0; }
  void insert(iterator& it, T value) {
    if (empty()) {
      auto novi = new Node{value, nullptr, nullptr};
      head_ = tail_ = novi;
    } else if (it == sentinel) {
      return;
    } 
    // Buduci kako imamo sentinel/cuvara, ovaj if mozemo izostaviti
    // i dodatno ubrazti program
    // else if (it->back_ == nullptr && it->next_ == nullptr) {
    //   auto novi = new Node{value, head_, nullptr};
    //   it->back_ = novi;
    //   head_ = novi;
    //   it = begin();
    // } 
    else if (it->back_ == nullptr) {
      auto novi = new Node{value, it->next_->back_, nullptr};
      it->back_ = novi;
      head_ = novi;
      it = begin();
    } else if (it->next_ == sentinel) {
      auto novi = new Node{value, tail_, tail_->back_};
      it->back_->next_ = novi;
      it->back_ = novi;
      tail_->next_ = sentinel;
      sentinel->back_ = tail_;
    } else {
      auto novi = new Node{value, it->back_->next_, it->back_};
      it->back_->next_ = novi;
      it->back_ = novi;
    }
    size_++;
  }
  // kraj inserta
  void remove(iterator& it) {
    if (empty()) {
      return;
    }
    // Ukoliko zelimo da je iterator poslije remova validan
    // auto ittemp = it;
    // ittemp--;
    if (it->back_ == nullptr && it->next_->next_ == nullptr) {
      delete head_;

    } else if (it->back_ == nullptr) {
      head_ = it->next_;
      Node* temp = it->next_->back_;
      delete temp;
      it = head_;
    } else if (it->next_->next_ == nullptr) {
      Node* temp = it->back_->next_;
      tail_ = it->back_;
      it->back_->next_ = nullptr;
      tail_->next_ = sentinel;
      sentinel->back_ = tail_;
      delete temp;

    } else {
      Node* temp = it->back_->next_;
      it->back_->next_ = it->next_;
      it->next_->back_ = it->back_;
      delete temp;
    }
    // it = ittemp;
    size_--;
  }
  iterator begin() { return head_; }
  iterator end() { return tail_->next_; }
  ~List() {
    Node* temp;
    Node* temp2 = head_;
    while (size_ != 0) {
      temp = temp2->next_;
      delete temp2;
      temp2 = temp;
      size_--;
    }
  }
};
