#include "node.hpp"

//store userid and password in constructor
Node::Node(std::string userid, std::string password){
	this->userid = userid;
	this->password = password;
}

//test where the current node
void Node::getCurrent(){
	std::cout << userid;
	std::cout << password;
	std::cout << next;
}
