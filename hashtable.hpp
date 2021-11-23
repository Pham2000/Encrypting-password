#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "node.hpp"
#include <iostream>
#include <string>

class HashTable{
	private:
		//members to be used for storing
		static const int TABLESIZE = 88799;
		Node* table[TABLESIZE];
	public:
		// create hashtable
		HashTable();
		
		//be able to put 2 string inside table
		void insert(std::string userID, std::string password);

		//lookup node with string
		Node* lookup(std::string id);
		
		//show all the userid and password in table together
		void showAll();
		
		//hash userid to create more dynamic memory location
		int hash(std::string key);
		

};
#endif

