#include <iostream>
#include <string>
#include <stdexcept>

#include "RBTree.h"

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	RBTree<int, std::string> tree1;
	
	tree1.insert(45, "A"); // Top Node - black
	tree1.insert(70, "B"); // level 1 - red
	tree1.insert(30, "C"); // level 1 - red
	tree1.insert(25, "D"); // level 2 - black
	tree1.insert(36, "E"); // level 2 - black
	tree1.insert(60, "F"); // level 2 - black
	tree1.insert(80, "G"); // level 2 - black
	tree1.insert(10, "H"); // level 3 - red
	tree1.insert(28, "I"); // level 3 - red
	tree1.insert(40, "J"); // level 3 - red
	tree1.insert(50, "K"); // level 3 - red
	tree1.insert(68, "L"); // level 3 - red
	tree1.insert(90, "M"); // level 3 - red
	tree1.insert(5, "N"); //  level 4 - black
	tree1.insert(29, "O"); // level 4 - black
	tree1.insert(48, "P"); // level 4 - black
	tree1.insert(65, "Q"); // level 4 - black
	tree1.insert(85, "R"); // level 4 - black
	tree1.insert(100, "S"); //level 4 - black
	tree1.insert(8, "T"); //  level 5 - red
	
	std::cout << tree1.NodeColor(45)<< "\n";
	std::cout << tree1.NodeColor(70)<< "\n";
	std::cout << tree1.NodeColor(30)<< "\n";
	std::cout << tree1.NodeColor(25)<< "\n";
	std::cout << tree1.NodeColor(36)<< "\n";
	std::cout << tree1.NodeColor(60)<< "\n";
	std::cout << tree1.NodeColor(80)<< "\n";
	std::cout << tree1.NodeColor(10)<< "\n";
	std::cout << tree1.NodeColor(28)<< "\n";
	std::cout << tree1.NodeColor(40)<< "\n";
	std::cout << tree1.NodeColor(50)<< "\n";
	std::cout << tree1.NodeColor(68)<< "\n";
	std::cout << tree1.NodeColor(90)<< "\n";
	std::cout << tree1.NodeColor(5)<< "\n";
	std::cout << tree1.NodeColor(29)<< "\n";
	std::cout << tree1.NodeColor(48)<< "\n";
	std::cout << tree1.NodeColor(65)<< "\n";
	std::cout << tree1.NodeColor(85)<< "\n";
	std::cout << tree1.NodeColor(100)<< "\n";
	std::cout << tree1.NodeColor(8)<< "\n";

	return 0;
}


