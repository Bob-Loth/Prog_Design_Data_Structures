#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <queue>
using namespace std;
template <typename K, typename V, int CAP>
class HashTable
{
  struct Node
  {
    Node(K key, V value) { this->key = key; this->value = value; }
    K key;
    V value;
  };

  list<Node> data[CAP]; //an array of lists of nodes, each with a key-value pair
  int(*hashCode)(const K&);//ptr to hashCode function;
  int siz; //active elements in array

public:
  HashTable(int(*hashCode)(const K&) = 0);
  double loadFactor() const;
  V operator[](const K&) const;
  V& operator[](const K&);
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  queue<K> Keys() const;
  int size() const { return siz; }
  void clearTable();
};


template<typename K, typename V, int CAP>
inline HashTable<K, V, CAP>::HashTable(int(*hashCode)(const K&))
{
  this->hashCode = hashCode;
  siz = 0;
}

template<typename K, typename V, int CAP>
inline double HashTable<K, V, CAP>::loadFactor() const
{
  double loadF = 0.0;
  for (int i = 0; i < CAP; i++) {
    if (data[i].size() != 0) loadF++;
  }
  loadF = loadF / CAP;
  return loadF;
}

template<typename K, typename V, int CAP>
inline V HashTable<K, V, CAP>::operator[](const K& key) const
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++) {
    if (it->key == key) return it->value;
    if (it == data[index].end()) {
      return V();
    }
  }
}

template<typename K, typename V, int CAP>
inline V& HashTable<K, V, CAP>::operator[](const K& key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++) {
    if (it->key == key) {
      return it->value;
    }
  }
  //if not found
    Node temp = { key, V() }; //make new node, place in list in array
    data[index].push_back(temp);
    return data[index].back().value;
 
}

template<typename K, typename V, int CAP>
inline bool HashTable<K, V, CAP>::containsKey(const K& key) const
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++) {
    if (it->key == key) return true;
    if (it == data[index].end()) return false;
  }
}
template<typename K, typename V, int CAP>
inline void HashTable<K, V, CAP>::deleteKey(const K& key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  for (auto it = data[index].begin(); it != data[index].end(); it++) {
    if (it->key == key) it = data[index].erase(it);
  }
}
template<typename K, typename V, int CAP>
inline queue<K> HashTable<K, V, CAP>::Keys() const
{
  queue<K> keyQueue;
  
  for (int index = 0; index < CAP; index++) { //for each index in array
    for (auto it = data[index].begin(); it != data[index].end(); it++) {
      keyQueue.push(it->key);
    }
    }
  
  return keyQueue;
}
template<typename K, typename V, int CAP>
inline void HashTable<K, V, CAP>::clearTable()
{
  for (int i = 0; i < CAP; i++) {
    data[i].clear(); //list::clear clears entire list
    siz = 0;         //update size of hashmap
  }
}
#endif