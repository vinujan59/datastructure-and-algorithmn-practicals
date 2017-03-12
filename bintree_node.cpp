#include<iostream>
#include<queue>
using namespace std;

typedef int element_t; //Element type of the stack
typedef struct bintree_node{
	element_t value;
	bintree_node* left;
	bintree_node* right;
} bintree_node;

bintree_node* getBintree_node(element_t newvalue);
int add_left_child(bintree_node* parent, element_t newvalue);
int add_right_child (bintree_node* parent, element_t newvalue);
bintree_node* create_tree(element_t elements[],int length);
void expand_tree (bintree_node** root, element_t elements[],int start,int length);
void traverse_inorder(bintree_node* root);
void traverse_preorder(bintree_node* root);
void traverse_postorder(bintree_node* root);
int main(){
    cout << "test :\n";
    cout << "---------"<<endl;
    int elements[] = {1,45,23,33,25,53,54,11};
    int length = sizeof(elements)/sizeof(elements[0]);
    bintree_node* root = create_tree(elements,length);
    traverse_inorder(root);
    cout << "\n";
    traverse_postorder(root);
    cout << "\n";
    traverse_preorder(root);
    cout << "\n";
    int expand[] = {3,22,7,64};
    expand_tree(&root,expand,0,4);
    traverse_inorder(root);
    cout << "\n";
    traverse_postorder(root);
    cout << "\n";
    traverse_preorder(root);
    cout << "\n";

	return 0;
}
bintree_node* getBintree_node(element_t newvalue){
	bintree_node* temp  = new bintree_node();
	temp->value = newvalue;
	temp->left = NULL;
    temp->right = NULL;
	return temp;
}

int add_left_child(bintree_node* parent, element_t newvalue){
	if (parent == NULL){
		return -1;
	}
	if (parent->left == NULL){
		bintree_node* temp = getBintree_node(newvalue);
		parent->left = temp;
		return  1;
	}
	return -1;
}

int add_right_child (bintree_node* parent, element_t newvalue){
	if (parent == NULL){
		return -1;
	}
	if (parent->right == NULL){
		bintree_node* temp = getBintree_node(newvalue);
		parent->right = temp;
		return  1;
	}
	return -1;
}

bintree_node* create_tree(element_t elements[],int length){
    queue<bintree_node*> bintree_node_list;
    int i = 0;
    bintree_node *root = getBintree_node(elements[0]);
    bintree_node_list.push(root);
    while(!bintree_node_list.empty()){
            bintree_node *temp = bintree_node_list.front();
            bintree_node_list.pop();
            if(2*i + 1 >= length){
                break;
            }
            add_left_child(temp,elements[2*i + 1]);
            bintree_node_list.push(temp->left);
            if(2*i + 2 >= length){
                break;
            }
            add_right_child(temp,elements[2*i + 2]);
            bintree_node_list.push(temp->right);
            i++;
    }
    return root;
}

void expand_tree (bintree_node** root, element_t elements[],int start,int length){
    if(root != NULL){
        expand_tree(&((*root)->left),elements,start,length);
        if(start < length){
            if(add_left_child(*root,elements[start]) == 1){
                start++;
            }
            if(add_right_child(*root,elements[start]) == 1){
                start++;
            }
        }
        else{
            return ;
        }
        expand_tree(&((*root)->right),elements,start,length);
    }
//    int left = 2*start + 1;
//    int right = 2*start + 2;
//    if (left > length || right > length)
//        return NULL;
//    if(*root == NULL){
//        bintree_node* temp = getBintree_node(elements[start]);
//        *root = temp;
//    }
//    if((*root)->left == NULL && (*root)->right == NULL){
//            if(left<length)
//                (*root)->left = getBintree_node(elements[left]);
//            if(right<length)
//                (*root)->right = getBintree_node(elements[right]);
//    }
//    expand_tree(&((*root)->left),elements,left,length);
//    expand_tree(&((*root)->right),elements,right,length);
}

void traverse_inorder(bintree_node* root){
	if (root != NULL){
        traverse_inorder(root->left);
        cout << "-" << root->value <<"-";
        traverse_inorder(root->right);
    }
}

void traverse_preorder(bintree_node* root){
	if (root != NULL){
        cout << "-" << root->value <<"-";
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}
void traverse_postorder(bintree_node* root){
	if (root != NULL){
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        cout << "-" << root->value <<"-";
    }
}
