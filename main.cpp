#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(/*int argc, const char* argv[]*/)
{
	cout << "Hallo Serge!" << endl;
	int Keys[10] = { 0,9,1,8,2,7,3,6,4,5 };

	BinarySearchTree bst;
	for (int var : Keys)
	{
		bst.add(var);
	}

	if (bst.exists(5))
	{
		cout << "Den Key 5 existiert!" << endl;
	}
	else
	{
		cout << "Den Key 5 don't existiert!" << endl;
	}

	bst.print_postorder();

	return 0;
}