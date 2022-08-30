#include<iostream>
#include"TreeNode.h"
#include<queue>
using namespace std;

TreeNode<int>* takeInput(){
	int rootData;
	cout << "Enter root Data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter number of children : ";
	cin >> n;
	
	for(int i=0;i<n;i++){
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "Enter the root data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cout << "Enter the number of children of " << front->data << ":";
		cin >> numChild;
		for(int i=0;i<numChild;i++){
			int childData;
			cout << "Enter the "<<i<<"th child of "<<front->data<<" :";
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	
	return root;
}

void printTree(TreeNode<int>* root){
	cout << root->data << ":";
	for(int i=0;i<root->children.size();i++){
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for(int i=0;i<root->children.size();i++){
		printTree(root->children[i]);
	}
}

void printTreeLevelWise(TreeNode<int>* root){
	
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty()){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front->data << ":";
		
		for(int i=0;i<front->children.size();i++){
			cout << front->children[i]->data << ",";
			pendingNodes.push(front->children[i]);
		}
		cout << endl;
	}
}

int numNodes(TreeNode<int>* root){
	int ans = 1;
	for(int i=0;i<root->children.size();i++){
		ans += numNodes(root->children[i]);
	}
	return ans;
}

int sumOfNodes(TreeNode<int>* root){
	int sum = root->data;
	for(int i=0;i<root->children.size();i++){
		sum += sumOfNodes(root->children[i]);
	}
	return sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root){
	if(root == NULL){
		return root;
	}
	
	TreeNode<int>* maxNode = root;
	for(int i=0;i<root->children.size();i++){
		TreeNode<int>* child = maxDataNode(root->children[i]);
		if(child->data > maxNode->data){
			maxNode->data = child->data;
		}
	}
	return maxNode;
}

int getHeight(TreeNode<int>* root){
	int ans = 0;
	
	for(int i=0;i<root->children.size();i++){
		int h = getHeight(root->children[i]);
		ans = max(ans,h);
	}
	
	return ans+1;
}

void printAtLevelK(TreeNode<int>* root,int k){
	if(k==0){
		cout << root->data << endl;
		return;
	}
	for(int i=0;i<root->children.size();i++){
		printAtLevelK(root->children[i],k-1);
	}
}

int countLeafNodes(TreeNode<int>* root){
	
	if(root->children.size() == 0){
		return 1;
	}
	
	int ans = 0;
	for(int i = 0; i < root->children.size(); i++){
		ans += countLeafNodes(root->children[i]);
	}
	
	return ans;
}

void printPreOrder(TreeNode<int>* root){
	cout << root->data << " ";
	for(int i=0;i<root->children.size();i++){
		printPreOrder(root->children[i]);
	}
}

void printPostOrder(TreeNode<int>* root){
	for(int i=0;i<root->children.size();i++){
		printPostOrder(root->children[i]);
	}
	cout << root->data << " ";
}

int main(){
	/*
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	
	TreeNode<int>* root = takeInputLevelWise();
	printTreeLevelWise(root);
	
	cout << "Number of nodes in the generic tree : "<< numNodes(root) << endl;
	cout << "Sum of nodes of the generic tree : "<< sumOfNodes(root) << endl;
	
	TreeNode<int>* maxNode = maxDataNode(root);
	cout << "Maximam data node in the generic tree : " << maxNode->data << endl;
	cout << "Height of the tree : " << getHeight(root) << endl;
	printAtLevelK(root,2);
	cout << "Number of leaf nodes in the tree : " << countLeafNodes(root) << endl;
	printPreOrder(root);
	cout << endl;
	printPostOrder(root);
	cout << endl;
	return 0;
}
