#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>

class Node{
	public:
		//functions and members of the node since everything is in public it is accessible
		std::string userid;
		std::string password;
		Node* next;
		
		Node(std::string userID, std::string password);
		void getCurrent();		
};
#endif
