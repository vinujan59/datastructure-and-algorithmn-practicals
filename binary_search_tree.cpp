#include<iostream>
#include<exception>
using namespace std;

typedef int element_t; //Element type of the stack
typedef struct bintree_node{
	element_t value;
	bintree_node* left;
	bintree_node* right;
}bintree_node;

bintree_node* getBintree_node(element_t newvalue);
int add_value (bintree_node** root, element_t newvalue);
bintree_node* search_value (bintree_node* root, element_t value);
bintree_node* findMin(bintree_node* root);
element_t delete_value (bintree_node** root, element_t value);
void print_tree(bintree_node* root);

int main(){
    cout<< "test 1:" << endl;
	bintree_node* root = getBintree_node(3);//creating root node
	add_value(&root,64);//add(64)
	add_value(&root,43);
	add_value(&root,4);
	add_value(&root,4);
	print_tree(root);//print tree
	cout<< "\n";
	cout<< search_value(root,4)->value ;
	cout<< "\n";
	delete_value(&root,3);
	print_tree(root);//print tree
	add_value(&root,12);
	add_value(&root,84);
	cout<< "\n";
	print_tree(root);//print tree
	cout<< "\n--------------------------------------------"<< endl;
	cout<< "test 2:" << endl;
	root = getBintree_node(3);//creating root node
	add_value(&root,64);//add(64)
	add_value(&root,43);
    delete_value(&root,64);
    print_tree(root);//print tree
    cout <<"\n";
    delete_value(&root,43);
    print_tree(root);//print tree
    cout <<"\n";
    delete_value(&root,3);
    print_tree(root);//print tree
    cout <<endl;
    add_value(&root,56);
	add_value(&root,62);
	add_value(&root,83);
	print_tree(root);//print tree
    cout <<endl;
	return 0;
}

bintree_node* getBintree_node(element_t newvalue){
	bintree_node* temp  = new bintree_node();
	temp->value = newvalue;
	temp->left = NULL;
    temp->right = NULL;
	return temp;
}

int add_value(bintree_node** root, element_t newvalue){
	if (*root == NULL){
		*root = getBintree_node(newvalue);
		return 1;
	}
	else if ((*root)->value > newvalue ){
		add_value(&(*root)->left,newvalue);
	}
	else{
		add_value(&(*root)->right,newvalue);
	}
}

bintree_node* search_value (bintree_node* root, element_t value){
	if(root == NULL){
		return NULL;
	}
	else if (root->value == value ){
		return root;
	}
	else if (root->value > value ){
		search_value(root->left,value);
	}
	else
		search_value(root->right,value);
}

bintree_node* findMin(bintree_node* root){//minimum value will be on left child
	bintree_node* min = root;
	while(root->left != NULL){
		root = root->left;
		if (root->value < min->value){
			min = root;
		}
	}
	return min;
}

element_t delete_value (bintree_node** root, element_t value){
	if(*root == NULL){
		return -1;
	}
	else if((*root)->value == value){
		//case 1 :no child
		if((*root)->left == NULL && (*root)->right == NULL){
			element_t val = (*root)->value;
			delete *root;
			*root = NULL;
			return val;
		}
		//case 2 :right child is null
		else if((*root)->right == NULL){
			bintree_node* temp = *root;
			element_t value = (*root)->value;
			delete *root;
			*root = (*root)->left;
			return value;
		}
		//case 3 :left child is null
		else if((*root)->left == NULL){
			bintree_node* temp = *root;
			element_t value = (*root)->value;
			delete *root;
			*root = (*root)->right;
			return value;
		}
		//case 4 :no NULL child
		else{
			bintree_node* temp = findMin((*root)->right);
			(*root)->value = temp->value;
			delete_value(&((*root)->right) ,temp->value);

		}
	}
	else if(value < (*root)->value){
		return delete_value(&((*root)->left),value);
	}
	else
		return delete_value(&((*root)->right),value);
}

void print_tree(bintree_node* root){
	if (root != NULL){
	   print_tree(root->left);
       cout << "-" << root->value <<"-";
       print_tree(root->right);
    }
    else
        cout << "";
}

