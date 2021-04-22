#include "double_llist.hpp"

template <typename tip>
void print(List<tip>& T) {
  // auto i = T.begin();
  std::cout << "List items" << std::endl;
  for (auto i = T.begin(); i != T.end(); i++) {
    std::cout << i->element_ << " ";
  }
  std::cout << std::endl;
}

int main(void) {
  std::cout << "\t\t**DOUBLY LINKED LIST**" << std::endl;
  std::cout << "\n\n*Constructors & destructor*\n" << std::endl;
  List<int> moja_lista;
  List<int> moja_lista3;
  List<int> moja_lista2{moja_lista};
  moja_lista3 = moja_lista2;
  List<int> moja_lista4{std::move(moja_lista)};
  moja_lista2 = std::move(moja_lista3);
  std::cout << std::endl;
  List<int> druga_lista;
  druga_lista.push_back(22);
  druga_lista.push_back(4);
  druga_lista.push_back(27);
  print(druga_lista);
  List<int> tvoja_lista{druga_lista};
  print(tvoja_lista);
  List<int> tvoja_lista_2{std::move(tvoja_lista)};
  print(tvoja_lista_2);

  std::cout << "\n\n*Metodi liste*\n" << std::endl;
  // std::cout << "\n=push_back() & push_front() lvalue & rvalue\n" <<
  // std::endl;
  int value = 7;
  tvoja_lista_2.push_back(value);
  tvoja_lista_2.push_front(value);
  print(tvoja_lista_2);
  tvoja_lista_2.pop_back();
  tvoja_lista_2.pop_front();
  print(tvoja_lista_2);
  tvoja_lista_2.push_back(7);
  tvoja_lista_2.push_front(7);
  print(tvoja_lista_2);
  tvoja_lista_2.pop_back();
  tvoja_lista_2.pop_front();
  print(tvoja_lista_2);

  std::cout << "\n\n*Klasa iterator*\n" << std::endl;
  //*i
  // i->m
  //++i
  // i++
  //--i
  // i--
  // i1==i2
  // i1!=i2
  // i1=i2
  List<int> nova_lista{};
  nova_lista.push_back(22);
  nova_lista.push_back(5);
  nova_lista.push_back(27);
  auto it = nova_lista.begin();
  auto it2 = it;
  bool e = it == it2;
  std::cout << "it == it2: " << e << std::endl;
  e = it != it2;
  std::cout << "it != it2: " << e << std::endl;
  std::cout << it->element_ << std::endl;
  it++;
  std::cout << *it << std::endl;
  it2 = nova_lista.end();
  it2--;
  std::cout << *it2 << std::endl;
  e = it == it2;
  std::cout << "it == it2: " << e << std::endl;
  e = it != it2;
  std::cout << "it != it2: " << e << std::endl;

  std::cout << "\n\n-=Metod insert(const iterator& position,T value)=-\n"
            << std::endl;
  nova_lista.insert(it2, 9);
  print(nova_lista);
  nova_lista.insert(it, 21);
  print(nova_lista);

  std::cout << "\n\n-=Metod remove(const iterator& position)=-\n" << std::endl;
  nova_lista.remove(it2);
  print(nova_lista);

  std::cout << "\noperator-- on list.end() iterator" << std::endl;
  List<int>::iterator kraj = nova_lista.end();
  kraj--;
  std::cout << *kraj << std::endl;
  return 0;
}
