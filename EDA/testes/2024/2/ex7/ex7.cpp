/***************************
Considere a representação de àrvores binárias BST dada nas aulas TPs. Implemente uma função booleana bool isBST(Node * root) que recebe a raíz de uma árvore binária com a estrutura de uma BST e verifica se é uma árvore binária de pesquisa (devolve true) ou não (devolve false).

***************************/

  
#include <iostream>
#include <stdlib.h>
#include "tree.hpp"


using namespace std;

bool isBST(Node * root){
  int lastValue = -100;
  if(root == nullptr) return true;
  if(!isBST(root->left)) return false;
  if(root->item < lastValue) return false;
  lastValue = root->item;
  return isBST(root->right);
}


// Driver code
int main()
{
  vector<int> vecTree1 = {-1, 3, 5, 2, 20,-1, 0, -1, 9, -1, -1, -1, -1, 14, -1, -1};  // NO
  vector<int> vecTree2 = {-1, 10, 5, 20, 2, 6, 15, 23};  // YES
  vector<int> vecTree3;  // YES


  Tree t1(vecTree1);
  cout << "Tree 1 " << std::boolalpha << isBST(t1.getRoot()) << endl;
  Tree t2(vecTree2);
  cout << "Tree 2 " << std::boolalpha << isBST(t2.getRoot()) << endl;
  Tree t3(vecTree3);
  cout << "Tree 3 " << std::boolalpha << isBST(t3.getRoot()) << endl;
 
  return 0;
}
