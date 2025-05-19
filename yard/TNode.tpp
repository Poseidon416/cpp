template <typename T> TNode<T>::TNode(T v): val(v), left(NULL), right(NULL) {}
template <typename T> T TNode<T>::getVal() {return val;}
template <typename T> TNode<T>* TNode<T>::getLeft() {return left;}
template <typename T> TNode<T>* TNode<T>::getRight() {return right;}
template <typename T> void TNode<T>::setLeft(TNode<T>* t) {left = t;}
template <typename T> void TNode<T>::setRight(TNode<T>* t) {right = t;}

