#ifndef START_HPP
#define START_HPP
#include "hashtable.hpp"
#include "storage.hpp"
#include <iostream>
#include <string>
#include <iomanip>
class Start{
	private:
		Storage program; // by calling storage I bassically read and write every file in directory and have access to it
		HashTable Encrypt;
	public:
		Start();
		void working();

					

};
#endif
