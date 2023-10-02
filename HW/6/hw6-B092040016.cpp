
#include<iostream>
using namespace std;

class TreeNode{//implement class TreeNode
	//friend class Tree;
	public:
		friend class Tree;
		TreeNode(int d,TreeNode *l,TreeNode *r){data=d;left=l;right=r;}//constrcutor of TreeNode
	private:
		int data;
		TreeNode *left;
		TreeNode *right;
};
class Tree{//implement the Tree class
	public:
		Tree(){root=0;}//constructor of Tree
		void Modify(int d,TreeNode *t);//passing the data and the treenode root
		void Insert(int d,TreeNode*t);//passing the data you want to insert and the treenode root
		void Delete(int d,TreeNode *t);//passing the treenode root and the data you want to delete 
		void Print(TreeNode *t);//passing the treenode root to Print
		void PrintNode(TreeNode *t);//passing the treenode root to Print
		void PrintLeft(TreeNode *t);//passing the treenode root to Print
		void PrintRight(TreeNode *t);//passing the treenode root to Print
		void Reset(TreeNode *t);//passing the treenode root
		TreeNode *root;//root ot Tree
};
void Tree::Reset(TreeNode *t){root=0;}//reset the tree 
void Tree::Insert(int d,TreeNode *t){
	if(t==0){//if the tree is empty,insert it as root
		root=new TreeNode(d,0,0);
	}
	else{//alwats insert into leafnode
		while(1){//find the right place 't' to insert
			if(d < t->data){
				if(t->left==0){break;}
				else t=t->left;
			}
			else if(d>t -> data){
				if(t->right==0){break;}
				else t=t->right;
			}
		}
		if(d < t->data)
			t->left=new TreeNode(d,0,0);
		else
			t->right=new TreeNode(d,0,0);
			
	}
}

void Tree::Delete(int d,TreeNode *t){//passing the treenode root and the data you want to delete 
	TreeNode *t0;//t0 represent the parent of t
	while(1){//to find the correct 't' and t0
		if(d < t->data){t0=t;t=t->left;}
		else if(d>t -> data){t0=t;t=t->right;}
		else{//d==t->data
			break;
		}
	}
	if(t==root){//to delete a root
		if(t->left==0 && t->right == 0){//no son
			root=0;
		} 
		else if(t->left==0 && t->right != 0){//one son
			root=t->right;
		}
		else if(t->left!=0 && t->right == 0){//one son
			root=t->left;
		}
		else{//two son
			TreeNode *temp=t;//temp represent the parent of t
			t=t->right;
			
			if(t->left!=0){
				while(t->left!=0){
					temp=t;t=t->left;
				}
				temp->left=0;
				t->left=root->left;
				t->right=root->right;
				root=t;
			}
			else{
				root->right->left=root->left;
				root=root->right;
			}
			/*
			while(1){//to find the inorder successor to replace the position of the root
				if(t->left!=0){
					temp=t;
					t=t->left;
					break;
				}
				if(t->right==0){break;}
				temp=t;
				t=t->right;
			}
			
			if(t==temp->right){//case 1
				root->right->left=root->left;
				root=root->right;
			}
			
			else{//case 2
				while(t->left!=0){
					temp=t;t=t->left;
				}
				//inorder sucessor 't' replace to the position of the root
				temp->left=0;
				t->left=root->left;
				t->right=root->right;
				root=t;
			}
		*/	
		}
	}
	else{//t0 is parent of T
		if(t==t0->left){//t is left subtree of t0
			if(t->left==0 && t->right == 0){//no son
				t0->left=0;
			} 
			else if(t->left==0 && t->right != 0){//one son
				t0->left=t->right;
			}
			else if(t->left!=0 && t->right == 0){//one son
				t0->left=t->left;
			}
			else{//two son
				TreeNode *origin=t;//record the original position
				TreeNode *temp=t;//temp represent the parent of t(updating)
				t=t->right;
				if(t->left!=0){
					while(t->left!=0){
						temp=t;t=t->left;
					}
					temp->left=0;
					t0->left=t;
					t->left=origin->left;
					t->right=origin->right;
				}
				else{
					t0->left=t;
					t->left=origin->left;
				}
				/*
				while(1){//to find the inorder succesor to replace the original position of 't'
					if(t->left!=0){
						temp=t;
						t=t->left;
						break;
					}
					if(t->right==0){break;}
					temp=t;
					t=t->right;
				}
				
				if(t==temp->right){//case 1
					t0->left=origin->right;
					origin->right->left=t0->left->left;
					
				}
				else{//case 2
					while(t->left!=0){
						temp=t;t=t->left;
					}
					//inorder succesor 't' replace the original position
					temp->left=0;
					t0->left=t;
					t->left=origin->left;
					t->right=origin->right;
				}
				*/
			}
		}
		else{//t is right subtree of t0
			if(t->left==0 && t->right == 0){//no son
				t0->right=0;
			} 
			else if(t->left==0 && t->right != 0){//one son
				t0->right=t->right;
			}
			else if(t->left!=0 && t->right == 0){//one son
				t0->right=t->left;
			}
			else{//two son
				TreeNode *origin=t;//record the original position
				TreeNode *temp=t;//temp represent the parent of t(updating)
				t=t->right;
				if(t->left!=0){
					while(t->left!=0){
						temp=t;t=t->left;
					}
					temp->left=0;
					t0->right=t; 
					t->left=origin->left;
					t->right=origin->right;
				}
				else{
					t0->right=t;
					t->left=origin->left;
				}
				/*
				while(1){//to find the inorder succesor to replace the original position of 't'
					if(t->left!=0){
						temp=t;
						t=t->left;
						break;
					}
					if(t->right==0){break;}
					temp=t;
					t=t->right;
				}
				
				if(t=temp->right){//case 1
					t0->right=origin->right;
					origin->right->left=t0->right->left;
				}
				else{//case 2
					while(t->left!=0){
						temp=t;t=t->left;
					}
					//inorder succesor 't' replace the original position
					temp->left=0;
					t0->right=t; 
					t->left=origin->left;
					t->right=origin->right;
				}
				*/
			}
		}
	}	
}
void Tree::Modify(int d,TreeNode *t){
	int search=0;
	if(t!=0){//serach for data d whether in this tree
		while(1){
			if(d < t->data){
				if(t->left==0){break;}
				else t=t->left;
			}
			else if(d>t -> data){
				if(t->right==0){break;}
				else t=t->right;
			}
			else{//d==t->data
				search = 1;//find the data
				break;
			}
		}	
	}
	if(search==0){//if it didn't find the data,then insert into the tree
		Insert(d,root);
	}
	else{//if it finds the data,then delete it from the tree
		Delete(d,root);
	}
}
void Tree::PrintNode(TreeNode *t){//Print the treenode(recursive)
	if(t!=0){
		if(t->left!=0) PrintNode(t->left);//go to the leftsubtree
		
		cout<<t->data<<" ";//print the node
		
		if(t->right!=0) PrintNode(t->right);//go to the right subtree
	}
}
void Tree::PrintLeft(TreeNode *t){//print the left child data of the treenode(recursive)
	if(t!=0){
		if(t->left!=0) PrintLeft(t->left);//go to the leftsubtree
		
		if(t->left==0) cout<<0<<" ";//if the left child is null node,then print 0
		else cout<<t->left->data<<" ";//print the left child data of the node
		
		if(t->right!=0) PrintLeft(t->right);//go to the rightsubtree
	}
}
void Tree::PrintRight(TreeNode *t){//print the right child data of the treenode(recursive)
	if(t!=0){
		if(t->left!=0) PrintRight(t->left);//go to the leftsubtree
		
		if(t->right==0) cout<<0<<" ";//if the right child is null node,then print 0
		else cout<<t->right->data<<" ";//print the right child data of the node
		
		if(t->right!=0) PrintRight(t->right);//go to the leftsubtree
	}
}
void Tree::Print(TreeNode *t){//print the tree
	if(t!=0){
		cout<<"node: ";
		PrintNode(root);
		cout<<endl<<"left: ";
		PrintLeft(root);
		cout<<endl<<"right: ";
		PrintRight(root);
		cout<<endl;
	}
	else{
		cout<<"node: ";
		cout<<endl<<"left: ";
		cout<<endl<<"right: ";
		cout<<endl;
	}//empty tree
}

int main(){
	int number;
	
	Tree A;//create a tree
	
	while(cin>>number){//read data until end of file
		if(number==-1){//if the number is -1 , then print the tree
			A.Print(A.root);
			cout<<endl;
			A.Reset(A.root);//reset	
		}
		else{//if the number is not -1 then modify the tree
			A.Modify(number,A.root);
		}
	}
} 
