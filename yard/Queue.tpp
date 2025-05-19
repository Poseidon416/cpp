template <typename T> Queue<T>::Queue() : LinkedList<T>() {
  this->tail = NULL;
}

template <typename T>
void Queue<T>::enqueue(T v) {
  Node<T>* newNode = new Node<T>(v);
  if (this->head == NULL) {
    this->head = newNode;
    this->tail = newNode;
  } else {
    this->tail->setNext(newNode);
    this->tail = newNode;
  }
}

template <typename T>
T Queue<T>::dequeue() {
  if (this->head == NULL) {
    throw out_of_range("Queue is empty");
  }
  Node<T>* temp = this->head;
  T v = temp->getVal(); 
  if(this->head == tail) {
    this->tail = NULL;
  } 
  this->head = this->head->getNext();
  delete temp;
  return v;
}

template <typename T>
bool Queue<T>::isEmpty() {
  return this->head == NULL;
}

template <typename T>
void Queue<T>::print() {
  Node<T>* current = this->head;
  while(current != NULL) {
    cout << current->getVal() << " ";
    current = current->getNext();
  }
}
