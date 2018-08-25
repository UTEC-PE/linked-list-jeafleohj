#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

template <typename T>
class List {
	Node<T>* head;
	Node<T>* tail;
	int nodes;

	void print_reverse(Node<T>* head);

public:
	List();

	T front(){
		if(!head)
			throw "Lista vacía";
		return head->data;
	}
	T back(){
		if(!tail)
			throw "Lista vacía";
		return tail->data;
	}
	void push_front(T value);
	void push_back(T value);
	void pop_front();
	void pop_back();
	T get(int position);
	void concat(List<T> &other);
	bool empty(){ return tail==nullptr; }
	int size(){ return nodes; }
	void print();
	void print_reverse();
	void clear();
	Iterator<T> begin();
	Iterator<T> end();

	~List();
};

template <typename T>
List<T>::List(){
	head = tail = nullptr;
	nodes = 0;
}

template <typename T>
List<T>::~List(){
	clear();
}

template <typename T>
void List<T>::print(){
	if( !empty() ){
		Node<T>* it = head;
		do{
			std::cout << it->data;
			if( it -> next != nullptr ) std::cout<<" ";
			else std::cout<<"\n";
			it = it -> next;
		}while( it );
	}
}

template <typename T>
void List<T>::push_front(T value){
	Node<T>* newnode = new Node<T>;
	newnode->data = value;

	if( nodes == 0 ){
		newnode -> next = nullptr;
		tail = newnode;
	}else{
		newnode -> next = head;
	}
	head = newnode;
	nodes++;
}

template <typename T>
void List<T>::push_back(T value){
	Node<T>* newnode = new Node<T>;
	newnode->data = value;
	newnode->next = nullptr;
	if( nodes == 0 ){
		head = newnode;
	}else{
		tail -> next = newnode;
	}
	tail = newnode;
	nodes++;
}

template <typename T>
void List<T>::pop_front(){
	if( !empty() ){
		Node<T>* tmpnode = head;
		head = head -> next;
		delete tmpnode;
		nodes--;
	}

}

template <typename T>
void List<T>::pop_back(){
	if( !empty() ){
		Node<T>* it = head;
		while(it->next!=tail){
			it = it->next;
		}
		tail = it;
		it = it->next;
		tail->next = nullptr;		
		delete it->next;
		nodes--;		
	}
}

template <typename T>
void List<T>::print_reverse(Node<T>* head){
	if( head != nullptr ){
		print_reverse(head->next);
		std::cout << head -> data;
		if( head == this->head) std::cout<<"\n";
		else std::cout<<" ";		
	}
}

template<typename T>
void List<T>::print_reverse(){
	print_reverse(head);
}
template<typename T>
void List<T>::clear(){
	if(head){
		nodes = 0;
		head->killSelf();
		head = tail = nullptr;
	}

	
}

template < typename T>
T  List<T>::get(int position){
	if( position < 0 || position >= nodes)
		throw "Invalid range";
	Node<T>* it = head;
	for(int i = 0; i<position; ++i) {
		it = it -> next;
	}
	return it->data;
}

template < typename T>
void  List<T>::concat(List<T> &other){
	for(int i = 0; i<other.size(); ++i) {
		push_back(other.get(i));
	}
	nodes += other.size();
}
#endif
