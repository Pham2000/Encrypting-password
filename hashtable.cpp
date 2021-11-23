#include "hashtable.hpp"

//calling hashtable
HashTable::HashTable(){
	for(int i = 0; i < TABLESIZE; i++){
		table[i] = nullptr;
	}
	
}

// insert at front of the list
void HashTable::insert(std::string userID, std::string password)
{	
	int index = hash(userID);
	Node * tmp = new Node(userID, password);
	tmp->next = table[index];
	table[index] = tmp;
}

// use this to ensure you have built the table correctly
void HashTable::showAll()
{
  for(int i = 0; i < TABLESIZE;i++)
   {
     Node * current = table[i];
     while(current != nullptr)
     {
       std::cout << current->userid << current->password << std::endl;
       current = current->next;
     }
  }
}


// returns pointer to the item or nullptr
Node* HashTable::lookup(std::string id)
{
	int index = hash(id);
	Node * current = table[index];
	while(current != nullptr && current->userid != id)
		current = current->next;
  	return current;
}

//hash function
int HashTable::hash(std::string id){
	int hash = 0;
	for(std::size_t i = 0; i < id.length(); i++){
		hash += (int)id.at(i);
	}

	return hash % TABLESIZE;
}
