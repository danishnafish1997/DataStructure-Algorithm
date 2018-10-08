#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  node *left,*right;
  node(int x){
    val = x;
    left = right = NULL;
    }
 };
 unordered_map<node*, int>cnt;
 void traversal_trick(node *root){
    //Postorder
    
    stack<node*> s;
    s.push(root);
    while(!s.empty){
      node *curr = s.top();
      if(curr == NULL){s.pop();continue;}
      if(cnt[curr] == 0) s.push(curr->left);
      else if(cnt[curr] == 1)s.push(curr->right);
      else if(cnt[curr] == 2)cout<<curr->val<<endl;
      else s.pop();
      cnt[curr]++;
  }
 
 int main(){
   node *root = new node(7);
   root->left = new node(3);root->right = new node(10);
   root->left->left = new node(2);root->left->right = new node(5);
   
   traversal_trick(root);
