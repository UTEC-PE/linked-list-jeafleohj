#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* next;

    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
	if(next){
		next->killSelf();
	}
	delete this;
}

#endif
