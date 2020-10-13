#include<iostream>
using namespace std;

struct node
{
	int data;
	node *right;
	node *left;
};

node *getNewnode(int num)
{
	node *temp = new node();
	temp->data = num;
	temp->left = temp->right = NULL;
	return temp;
}

node *insert(node *root, int num)
{
	if(root==NULL)
		root=getNewnode(num);
	else if(root->data>num)
		root->left = insert(root->left,num);
	else
		root->right = insert(root->right,num);

	return root;
}

void inorder(node *root,int n)
{
	//cout<<n<<endl;
	static int count = 0;			//there is only one copy of a static variable in a program
	if(root==NULL)
		return;

	if(count<=n)
	{
	inorder(root->left,n);
	count++;
	if(count==n)
		cout<<root->data;
	
	inorder(root->right,n);
}
}


int main()
{
	node *root = NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,12);
	root=insert(root,17);
	root=insert(root,25);
	root=insert(root,6);
	root=insert(root,11);
	root=insert(root,16);
	root=insert(root,27);
	inorder(root,5);
}