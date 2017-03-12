#include<iostream>

using namespace std;
typedef int E;

template <class E> class Node {
private:
	E value;
	Node<E>* next;

public:
	E getValue();
	void setValue(E val);
	Node<E>* getNext();
	void setNext(Node<E>* newNode);

};

template<class E> E Node<E>::getValue(){
	return this->value;
}

template<class E> void Node<E>::setValue(E val){
	this->value = val;
}

template<class E> Node<E>* Node<E>::getNext(){
	return this->next;
}

template<class E> void Node<E>::setNext(Node<E>* newNode){
	this->next = newNode;
}



template <class E> class LinkedList {
private:
	Node<E>* head;
	int length;

public:
	void  init_list();
	bool  is_list_empty();
	Node<E>*  search_(E value);
	E  deleteNode(E value);
	E  deleteat(int i);
	bool  insert_(E value);
	bool  insert_at(E value, int i);
	int  list_length();
	void  print();
};

template<class E> void LinkedList<E>::init_list(){
	length = 0;
	head = NULL;
}

template<class E> bool LinkedList<E>::is_list_empty(){
	if (length == 0){
		return true;
	}
	return false;
}

template<class E> Node<E>* LinkedList<E>::search_(E value){
	Node<E>* current = head;
	while (current != NULL ){
		if (current->getValue() == value){
			return current;
		}
		current = current->getNext();
	}

	return NULL;
}

template<class E> E LinkedList<E>::deleteNode(E value){
	Node<E>* current = head;
	Node<E>* temp;
	if (current == NULL ){
		return NULL;
	}

	if (current->getValue() == value){
		temp = head;
		head = current->getNext();
		length--;
		delete temp;
		return value;
	}

	while (current->getNext() != NULL ){
		if (current->getNext()->getValue() == value){
			temp = current->getNext();
			current->setNext(current->getNext()->getNext());
			length--;
			delete temp;
			return value;
		}
		current = current->getNext();
	}
	return NULL;
}

template<class E> E LinkedList<E>::deleteat(int i){
	Node<E>* current = head ;
	if (i > length || i < 0){
		return NULL;
	}
	if (i == 1){
		E value = current->getValue();
		deleteNode(current->getValue());
		return value;
	}

	for (int j = 1 ; j < i - 1 ; j++){
		current = current->getNext();
	}

	Node<E>* temp = current->getNext();
	current->setNext(current->getNext()->getNext());
	E value = temp->getValue();
	length--;
	delete temp;
	return value;
}

template<class E> bool LinkedList<E>::insert_(E value){
	Node<E>* current = head;
	Node<E>* temp = new Node<E>();
	temp->setValue(value);
	temp->setNext(NULL);
	if (head == NULL){
        head = temp;
		head->setNext(NULL);
		length++;
		return true;
	}
	while(current->getNext() != NULL){
		current = current->getNext();
	}
	current->setNext(temp);
	length++;
	return true;
}
template<class E> void LinkedList<E>::print(){
    Node<E>* current = head;
    if (head == NULL){
        cout << "list is empty"<<endl ;
        return;
    }
    cout << "-" <<head->getValue()<<"-" ;
    while(current->getNext()!= NULL) {
        current = current->getNext();
        cout << "-" <<current->getValue()<<"-" ;
    }
    cout <<endl;
}

template<class E> bool LinkedList<E>::insert_at(E value, int i){
	if (i <0){
		return false;
	}
	if (i> length){
		i = length + 1;
	}
	Node<E>* current = head;
	Node<E>* newNode = new Node<E>();
	newNode->setValue(value);
	if (i  == 1){
		Node<E>* temp = head;
		head = newNode;
		head->setNext(temp);
		length++;
		return true;
	}

	int j = 1;
	while( (j < i - 1 )&& (current != NULL)){
		current = current->getNext();
		j++;
	}
	Node<E>* temp = current->getNext();
	newNode->setNext(temp);
	current->setNext(newNode);
	length++;
}

template<class E>	int LinkedList<E>::list_length(){
	return length;
}

template <class E> class MyStack {
private:
	LinkedList<E>* values ;
public:
	void init_stack();
	bool is_stack_empty();
	bool push(E value);
	E pop();
	E peek();
	void print_stack();
};
template <class E> void MyStack<E>::init_stack(){
    values = new LinkedList<E>();
	values->init_list();
}

template <class E> bool MyStack<E>::is_stack_empty(){
	return values->is_list_empty();
}

template <class E> bool MyStack<E>::push(E value){
	return values->insert_(value);
}

template <class E> E MyStack<E>::pop(){
	return values->deleteat(values->list_length());
}

template <class E> E MyStack<E>::peek(){
	E val = pop();
	push(val);
	return val;
}

template <class E> void MyStack<E>::print_stack(){
    values->print();
}

int main(){
    MyStack<int>* stack_ = new MyStack<int>();
    cout<<"init stack"<<endl;
    stack_->init_stack();
    cout << "is stack empty" << endl;
    cout<<stack_->is_stack_empty()<<endl;
    cout << "push 5,6,7,8,9" << endl;
    stack_->push(5);stack_->push(6);stack_->push(7);stack_->push(8);stack_->push(9);
    cout << "print stack" << endl;
    stack_->print_stack();
    cout << "peek" <<endl;
    cout << stack_->peek()<<endl;
    cout << "pop" <<endl;
    stack_->pop();
    cout << "print stack" << endl;
    stack_->print_stack();
    cout << "peek" <<endl;
    cout << stack_->peek()<<endl;
    cout << "pop" <<endl;
    stack_->pop();
    cout << "print stack" << endl;
    stack_->print_stack();
    cout << "peek" <<endl;
    cout << stack_->peek()<<endl;
    cout << "pop" <<endl;
    stack_->pop();
    cout << "print stack" << endl;
    stack_->print_stack();
    cout << "peek" <<endl;
    cout << stack_->peek()<<endl;
    cout << "pop" <<endl;
    stack_->pop();
    cout << "print stack" << endl;
    stack_->print_stack();
    cout << "peek" <<endl;
    cout << stack_->peek()<<endl;
    cout << "pop" <<endl;
    stack_->pop();
    cout << "print stack" << endl;
    stack_->print_stack();
    return 0;
}

