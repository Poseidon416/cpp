template <typename T> Node<T>::Node(T v): val(v), next(NULL) {}
template <typename T> Node<T>* Node<T>::getNext() { return next; }
template <typename T> void Node<T>::setNext(Node<T>* n) { next = n; }
template <typename T> T Node<T>::getVal() { return val; }

template <typename T> LinkedList<T>::LinkedList(): head(NULL) {}

template <typename T> 
LinkedList<T>::~LinkedList(){
  Node<T>* current = this->head;
  while(current != NULL){
    Node<T>* temp = current;
    current = current->getNext();
    delete temp;
  }
}

template <typename T> Node<T>* LinkedList<T>::getHead() { return this->head; }

