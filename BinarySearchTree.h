#ifndef BINARY_SEARCH_TREE_H_INCLUDE
#define BINARY_SEARCH_TREE_H_INCLUDE

#include "TreeNode.h"
#include <stack>

using namespace std;

class BinarySearchTree
{
public:
    // Konstruktor
    BinarySearchTree()
    {
        this->mAnker = nullptr;
    }
    // Hier gehoert eigentlich ein Copy Konstruktor hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)

    // Deconstructor
    ~BinarySearchTree()
    {
        std::stack<TreeNode*> nodes;
        nodes.push(mAnker);
        while (!nodes.empty())
        {
            TreeNode* node = nodes.top();
            nodes.pop();

            if (node == nullptr) continue;

            nodes.push(node->left);
            nodes.push(node->right);

            delete node;
        }
    }

    // Fuegt einen Knoten zum Baum hinzu
    void add(const int& key) { mAnker =  m_add(key, mAnker); }

    // Guckt ob ein key im Baum vorhanden ist
    bool exists(const int& key) { return m_search(key, mAnker) != nullptr; }

    // 3. Rekursive Methode die alle Knoten in Postorder ausgibt
    void print_postorder() const;

    // 4. Iterative Methode die alle Knoten -Niveauweise ausgibt
    void print_Niveau() const;

    // 5. Loescht einen beliebigen Knoten im BST und setzt an dessen Stelle das Maximum vom linken Teilbaum
    bool delete_node(const int& key);

    // Gibt den maximalen Key Wert zurueck
    bool max(int& max) {
        if (mAnker == nullptr) return false;
        else
        {
            max = m_max(mAnker)->key;
            return true;
        }
    }

    // Hier gehoert eigentlich ein Assignment (copy) Operator hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)
private:
    TreeNode* mAnker;
    // 1. Fuegt einen Knoten als Nachfolger eines gegeben Knoten ein
    TreeNode* m_add(const int& key, TreeNode* parent);

    // 2. Sucht einen Knoten im BST
    TreeNode* m_search(const int& key, TreeNode* parent);

    // Hilfsmethode fuer 3.
    void m_print_postorder(TreeNode* node) const;

    // 6. Recursive Methode die den maximalen Knoten zurueck gibt
    TreeNode* m_max(TreeNode* node) const;
};

#endif /* BINARY_SEARCH_TREE_H_INCLUDE */
