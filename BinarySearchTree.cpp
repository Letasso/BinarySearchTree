#include <iostream>
#include "BinarySearchTree.h"

// 1. Schreiben Sie eine Methode, die einen neuen Knoten erzeugt und als Nachfolger eines gegebenen Knoten einfügt:
TreeNode* BinarySearchTree::m_add(const int& key, TreeNode* parent)
{
    // Ihre Loesung hier:
      // Return a new node if the tree is empty
    if (parent == NULL) {
        parent = new TreeNode(); // (struct node *)malloc(sizeof(node));
        
        parent->key = key;

        parent->left = parent->right = nullptr;
        
        return parent;
    }

    // Traverse to the right place and insert the node
    if (key < parent->key)
    {
        parent->left =  m_add(key, parent->left);
    }
    else
    {
        parent->right = m_add(key, parent->right);
    }
    return parent;
}

// 2. Schreiben Sie eine Methode, die einen Knoten im BST sucht:
TreeNode* BinarySearchTree::m_search(const int& key, TreeNode* parent) 
{
    if (parent == NULL || parent->key == key)
    {
        return parent;
    }
    else if (parent->key < key)
    {
        return m_search(key, parent->right);
    }
    else
    {
        return m_search(key, parent->left);
    }
    return nullptr;
}

// 3. Schreiben Sie eine Methode, die alle Knoten mit einer rekursiven Methode von den Blattknoten bis zur Wurzel ausgibt (Postorder-Methode) (Sie können dafür die Hilfsmethode m_print_postorder nutzen.):
void BinarySearchTree::m_print_postorder(TreeNode* node) const
{
    if (node == NULL)
    {
        return;
    }

    // first recur on left subtree
    m_print_postorder(node->left);

    // then recur on right subtree
    m_print_postorder(node->right);

    // now deal with the node
    std::cout << node->key<< " -> ";
}

void BinarySearchTree::print_postorder() const
{
    m_print_postorder(mAnker);
}

// 4. Schreiben Sie eine iterative Methode, die alle Knoten im BST -Niveauweise ausgibt:
void BinarySearchTree::print_Niveau() const
{
    // Ihre Loesung hier:
}

// 5. Schreiben Sie eine Methode, die einen beliebigen Knoten im BST löscht. Dabei soll der zu löschende Knoten gesucht werden und durch das Maximum im linken Teilbaum ersetzt werden
bool BinarySearchTree::delete_node(const int& key)
{
    // Ihre Loesung hier:
    return false;
}

// 6.Schreiben Sie eine rekursive Methode, die den maximalen Knoten im BST zurück gibt:
TreeNode* BinarySearchTree::m_max(TreeNode* node) const
{
    // Ihre Loesung hier:
    return nullptr;
}
