//Copyright (c) Vikram Ojha 2017
//Program Information:
// This Program calculates the density of Binary Tree
// Density of BT = Size/Height

#include<iostream>
using namespace std;
//Node Represent the Node of Binary Tree (BT). \
  @Elements: \
    info:  Data Part of BT. \
    lc: Represents the left child of BT. \
    rc: Represents the right of BT.

//#define nullptr NULL
typedef int HRESULT;
#define S_OK 0
#define E_FAIL 1
struct Node
{
  int info;
  Node* lc;
  Node* rc;
};

HRESULT CreateNode(Node* &root)
{
  root = new Node;
  if(nullptr==root)
    return E_FAIL;
  return S_OK;
}

HRESULT InsertNode(Node* &root, int info)
{
  HRESULT rc = E_FAIL;
  if(!root)
  {
    rc = CreateNode(root);
    if(E_FAIL==rc)
    {
      cout<<"Memory could be allocated";
      return rc;
    }
    root->info = info;
    root->lc = nullptr;
    root->rc = nullptr;
    return rc;
  }
  else if(nullptr == root->lc)
     rc = InsertNode(root->lc, info);
  else
     rc = InsertNode(root->rc, info);
  return rc;
}
      
int main()
{
   int rc = E_FAIL;
   struct Node* root = nullptr;
   int arr[] = {1,2,3,4,5,6,7,8,9};
   int size = sizeof(arr)/sizeof(arr[0]);
   for(int i=0; i < size; i++)
   {
      rc = InsertNode(root,arr[i]);
      if(E_FAIL == rc)
      {
        cout<<"Binary Tree could not be created";
        return rc;
      }
   }
   return S_OK;
}
