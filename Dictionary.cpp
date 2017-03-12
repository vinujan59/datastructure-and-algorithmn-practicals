#include <stdio.h>
#include <string.h>
#include<iostream>
#include <string>
#include <fstream>
#include <cstring>
#include<vector>

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ,.;:/-_/+-*";

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

class DNode{
private:
    string word;
    LinkedList<int>* index ;
    DNode* next;
public:
    void setWord(string word);
    string getWord();
    void setNext_(DNode* node);
    DNode* getNext_();
    void setIndex(int aindex);
    LinkedList<int>* getIndex();
    void print_index();
    void init_DNode();
};
void DNode::init_DNode(){
    index = new LinkedList<int>();
    index->init_list();
    next = NULL;
}

void DNode::setWord(string word){
    this->word = word;
}

string DNode::getWord(){
    return word;
}
void DNode::setNext_(DNode* node){
    next = node;
}
DNode* DNode::getNext_(){
    return next;
}

void DNode::setIndex(int aindex){
    index->insert_(aindex);
}
LinkedList<int>* DNode::getIndex(){
    return index;
}

void DNode::print_index(){
    index->print();
}
class dictionary{
private:
    DNode* head;
public:
    void init_dictionary();
    void insert_word(string word,int index);
    void print_dictionary();
};
/*initialise dictionary*/
void dictionary::init_dictionary(){
    head =NULL;
}
/*it will inset word and index to dictionary if word not
exist otherwise it will insert index of word to corressponding words index list*/
void dictionary::insert_word(string word,int index){
    DNode* current = head;
    DNode* temp = new DNode();
    temp->setWord(word);

    temp->init_DNode();
    temp->setIndex(index);
    if(head == NULL){
        head = temp;
        return ;
    }
    if(head->getWord()==word){
        head->setIndex(index);
        return;
    }
    while(current->getNext_() != NULL){
        current = current->getNext_();
        if (current->getWord()==word){
            current->setIndex(index);
            return ;
        }
    }
    current->setNext_(temp);
    return;
}
//this function print the dictionary words and their index//it will print empty when dictionary is empty////
void dictionary::print_dictionary(){
    if(head == NULL){
        cout << "dictionary is empty." <<endl;
    }
    DNode* current = head;
    while(current!=NULL){
        cout << current->getWord() <<endl;
        current->print_index();
        current = current->getNext_();
    }
    return ;
}
vector<string> StrSplit2( string inStr, string sepStr, string option ) ;
vector<string> &StrSplit2( string inStr, string sepStr, vector<string> &outStrVec);
int main(int argc, char* argv[]){
    char* fileName;
	if(argc == 2){
		fileName = argv[1];
	}
	else{
		cout << "Incorrect number of arguments! Input file name is required. Number of arguments received is " << argc-1 << ".\n";
		//system("pause");
		//exit(-1);
	}
    dictionary* diction  = new dictionary();
    diction->init_dictionary();
    ////////////////////////////////////////////////////////////////////////////////
    //*file reading and inserting code come here*///////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    ifstream file(fileName);
    string str;
    int n = 1;
    while (getline(file, str)){
        vector<string> v;
        v = StrSplit2( str, " :|#$*@./&,_-\t\n\"()\b!^'", "don't keep empty element" );
        for (unsigned int i = 0; i < v.size(); ++i) {
            diction->insert_word(v[i],n);
            n++;
        }
        if(n == 150)
            break;
    }
    file.close();
    ////////////////////////////////////////////////////////////////////////////////
    diction->print_dictionary();

    return 0;
}

vector<string> &StrSplit2( string inStr, string sepStr, vector<string> &outStrVec) {
	size_t found, token = 0;
	found = inStr.find_first_of( sepStr );
	while ( found != string::npos ) {
		outStrVec.push_back( inStr.substr( token, found - token ) );
		token = found + 1;
		found = inStr.find_first_of( sepStr, token );
	}
	outStrVec.push_back( inStr.substr( token, found - token ) );
	return outStrVec;
}

vector<string> StrSplit2( string inStr, string sepStr, string option ) {
	vector<string> outStrVec, tempVec;
	StrSplit2( inStr, sepStr, tempVec );
	if ( option == "keep empty element" ) {
		outStrVec = tempVec;
	} else {
		for ( unsigned int i = 0; i < tempVec.size(); ++i ) {
			if ( tempVec[i].length() > 0 ) {
				outStrVec.push_back( tempVec[i] );
			}
		}
	}
	return outStrVec;
}


