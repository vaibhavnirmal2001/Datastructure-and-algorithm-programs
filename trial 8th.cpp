
//practcal no : 8th
//BST


#include <bits/stdc++.h> 
using namespace std; 
  
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
struct node *newNode(int item) 
{ 
    struct node *temp =  new node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
  void postorder(struct node *root) {
   if (root != NULL) {
      postorder(root->left);
      postorder(root->right);
      cout<<root->key<<" ";
   }
}
vector<struct node *> constructTrees(int start, int end) 
{ 
    vector<struct node *> list; 
  
    
    if (start > end) 
    { 
        list.push_back(NULL); 
        return list; 
    } 
  
    for (int i = start; i <= end; i++) 
    { 
        vector<struct node *> leftSubtree  = constructTrees(start, i - 1); 
  
        vector<struct node *> rightSubtree = constructTrees(i + 1, end); 
  
        for (int j = 0; j < leftSubtree.size(); j++) 
        { 
            struct node* left = leftSubtree[j]; 
            for (int k = 0; k < rightSubtree.size(); k++) 
            { 
                struct node * right = rightSubtree[k]; 
                struct node * node = newNode(i);// making value i as root 
                node->left = left;              // connect left subtree 
                node->right = right;            // connect right subtree 
                list.push_back(node);           // add this tree to list 
            } 
        } 
    } 
    return list; 
} 
  
int main() 
{ 
    int n;
    
    printf("\n-------------Pactical No : 8-------------\n\n");

    cout<<"\nenter value of n :";
    cin>>n;
    vector<struct node *> totalTreesFrom1toN = constructTrees(1, n); 
  
  
    cout << "\npostorder traversals of all possible BSTs are \n"; 
    for (int i = 0; i < totalTreesFrom1toN.size(); i++) 
    { 
        postorder(totalTreesFrom1toN[i]); 
        cout << endl; 
    } 
    return 0; 
} 




