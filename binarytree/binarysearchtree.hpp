#pragma once
#include <iostream>

template <typename T>
class bSearchTree {
  struct Node;

  public:
  bSearchTree() = default;
  bSearchTree(const bSearchTree& o);
  bSearchTree(bSearchTree&& o);
  bSearchTree& operator=(const bSearchTree& o);
  bSearchTree& operator=(bSearchTree&& o);
  ~bSearchTree() {}
  void preorderTraversal() {}
  void inorderTraversal() {}
  void postorderTraversal() {}
  int treeHeigt() {}

  void print(){
    print_subtree(root_);
  }
  bool search(const T& v) {
    Node* current = root_;
    while (current != nullptr) {
      if (current->value == v) {
        return true;
      } else if (current->value < v) {
        current = current->rchild;
      } else if (current->value > v) {
        current = current->lchild;
      } else {
        return false;
      }
    }
  }
  void insert(const T& e) {
    if (root_ == nullptr) {
      root_ = new Node{e};
    }
    else{
    Node* previous = nullptr;
    Node* current = root_;
    while (current != nullptr) {
      previous = current;
      if (current->value > e) {
        current = current->lchild;
      } else if (current->value < e) {
        current = current->rchild;
      }
    }

    Node* newNode = new Node{e};
    if (previous->value > e) {
      previous->lchild = newNode;
    } else if (previous->value < e) {
      previous->rchild = newNode;
    }
  }
  }
  void eraseNode(Node*& e) {
    if (e == nullptr) {
      return;
    } else if (e->lchild == nullptr || e->rchild == nullptr) {
      Node* temp = e;
      e = nullptr;
      delete temp;
    } else if (e->lchild == nullptr) {
      Node* temp = e;
      e = e->rchild;
      delete temp;
    } else if (e->rchild == nullptr) {
      Node* tmp = e;
      e = e->lchild;
      delete tmp;
    }
    // Node has left and right child
    else {
      Node* current = e->lchild;
      Node* tmp = nullptr;
      while (current->rchild != nullptr) {
        tmp = current;
        current = current->rchild;
      }
      e->value = current->value;
      if (tmp == nullptr) {
        e->lchild = current->lchild;
      } else {
        tmp->rchild = current->lchild;
      }
      delete current;
    }
    size_--;
  }

  bool isEmpty() { return (root_ == nullptr); }
  size_t size() { return size_; }

  protected:
  Node* root_ = nullptr;
  size_t size_ = 0;

  private:
  void print_subtree(Node* root) const {
    if (root == nullptr) return;
    std::cout << root->value << " ";
    print_subtree(root->lchild);
    print_subtree(root->rchild);
  }
  struct Node {
    T value;
    Node* lchild = nullptr;
    Node* rchild = nullptr;
    Node(const T& v) : value{v} {}
  };
};
