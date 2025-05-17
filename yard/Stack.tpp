template <typename T> Stack<T>::Stack() : LinkedList<T>() {}

template <typename T>
void Stack<T>::push(T v) {
  Node<T>* newNode = new Node<T>(v);
  newNode->setNext(this->head);
  this->head = newNode;
}

template <typename T>
T Stack<T>::pop() {
  if (this->head == NULL) {
    throw out_of_range("Stack is empty.");
  }
  Node<T>* temp = this->head;
  T v = temp->getVal();
  this->head = this->head->getNext();
  delete temp;
  return v;
}

template <typename T>
T Stack<T>::peek() {
  if (this->head == NULL) {
    throw out_of_range("Stack is empty.");
  }
  return this->head->getVal();
}

template <typename T>
bool Stack<T>::isEmpty() {
  return this->head == NULL;
}
