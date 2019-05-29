#ifndef QUEUE
#define QUEUE
template <typename V>
class Queue
{
  public:
    Queue() { firstNode = lastNode = nullptr; } // may have a defaulted parameter
    Queue(const Queue<V>&); // copy constructor
    ~Queue();
    Queue<V>& operator=(const Queue<V>&);
    void push(const V&);
    const V& front() const; // return an immutable reference to the oldest node
    const V& back() const; // return an immutable reference to the newest node
    void pop(); // remove the oldest node
    int size() const;
    bool empty() const;
    void clear();

private:
  struct Node
  {
    V values;
    Node* next;
  };
  Node* firstNode;
  Node* lastNode;
  V dummy;
  int siz = 0;
  
};

template<typename V>
Queue<V>::~Queue()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}


template<typename V>
Queue<V>::Queue(const Queue<V>& original)
{
  firstNode = 0;
  lastNode = 0;
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->values = p->values;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}




template<typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& node2)
{
  if (this != &node2)
  {
    while (lastNode)
    {
      Node* p = lastNode;
      lastNode = lastNode->next;
      delete p;
    }

    lastNode = 0;
    for (Node* p = node2.lastNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->values = p->values;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = node2.siz;
  }
  return *this;
}

template<typename V>
void Queue<V>::push(const V & value)
{
  Node* temp = new Node{ value }; // C++11
  if (lastNode) lastNode->next = temp;
  if (siz == 0) firstNode = temp;
  lastNode = temp;
  ++siz;
}

template<typename V>
const V & Queue<V>::front() const
{
  if (firstNode == 0) return dummy;
  else return firstNode->values;
}

template<typename V>
const V & Queue<V>::back() const
{
  if (firstNode == 0) return dummy;
  else return lastNode->values;
}

template<typename V>
void Queue<V>::pop()
{
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
  if (siz == 0)
  {
    lastNode = 0;
  }
}

template<typename V>
int Queue<V>::size() const
{
  return siz;
}

template<typename V>
bool Queue<V>::empty() const
{
  if (siz == 0)
  {
    return true;
  }
  else if (siz > 0) {
    return false;
  }
  else throw "Size is negative";
}

template<typename V>
void Queue<V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}

#endif