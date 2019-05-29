#pragma once
#include <queue>
template <typename K, typename V>
class AssociativeArray
{
  struct Node
  {
    K key;
    V values;
    Node* next;
  };
  Node* firstNode;
  int siz;
  
public:
  AssociativeArray();
  AssociativeArray(const AssociativeArray<K, V>&);
  AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&);
  ~AssociativeArray();
  V operator[](const K&) const;
  V& operator[](const K&);
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  std::queue<K> Keys() const;
  void clear();
  int size() { return siz; }
};

template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray()
{
  siz = 0;
  firstNode = 0;
}
template <typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

template<typename K, typename V>
V AssociativeArray<K, V>::operator[](const K & key) const
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
      return p->values;
  }
  return V(); //if not found
}

template<typename K, typename V>
V & AssociativeArray<K, V>::operator[](const K & key)
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
      return p->values;
  }
  ++siz;
  Node* temp = new Node;
  temp->key = key;
  temp->values = V();
  temp->next = firstNode;
  firstNode = temp;
  return firstNode->values;
}

template<typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
      return true;
  }
  return false;
}

template<typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K & key)
{
  Node* p, *prev;
  for (p = firstNode, prev = 0; p; prev = p, p = p->next)
  {
    if (p->key == key)
      break;
  }
  if (p)
  {
    --siz;
    if (prev) prev->next = p->next;
    else firstNode = p->next;
    delete p;
  }
}

template<typename K, typename V>
std::queue<K> AssociativeArray<K, V>::Keys() const
{
  std::queue<K> keys;
  for (Node* p = firstNode; p; p = p->next)
  {
    keys.push(p->key);
  }
  return keys;
}

template<typename K, typename V>
void AssociativeArray<K, V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}

template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original)
{
  firstNode = 0;
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->key = p->key;
    temp->values = p->values;
    temp->next = 0;
    firstNode = temp;
  }
}

template<typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& original)
{
  if (this != &original)
  {
    while (firstNode)
    {
      Node* p = firstNode;
      firstNode = firstNode->next;
      delete p;
    }


    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->values = p->values;
      temp->key = p->key;
      temp->next = 0;
      firstNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}