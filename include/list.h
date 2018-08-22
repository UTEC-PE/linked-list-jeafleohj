#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
	Node<T>* head;
	Node<T>* tail;
	int nodes;

	void print_reverse(Node<T>* head);

public:
	List();

	T front(){ return head->data;}
	T back(){ return tail->data;}
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
void List<T>::print(){
	if( !empty() ){
		Node<T>* it = head;
		do{
			std::cout << it->data;
			if( it -> next == nullptr ) std::cout<<" ";
			else std::cout<<"\n";
		}while( it -> next != nullptr);
	}
}

template <typename T>
void List<T>::push_front(T value){
	Node<T>* newnode = new Node<T>;
	newnode->data = value;

	if( size == 0 ){
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
	if( size == 0 ){
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
		while( it ){
			if( it -> next == nullptr ){
				tail = it;
 				delete (it -> next);
			}
			it = it -> next;
		}
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
	
}
#endif
