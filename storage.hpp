#ifndef STORAGE_HPP
#define STORAGE_HPP
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "hashtable.hpp"
//Class that have to do with userId, Password, and how it transfer
class Storage{
	private:
		//vector of the userID, password, encrypted to be store in txt;
		std::vector<std::string> userID;
		std::vector<std::string> password;
		
		std::vector<std::string> userIDRaw;
		std::vector<std::string> passwordRaw;
		std::vector<std::string> EncryptPassword;
		
		static const int SIZE = 88799; // all vector sizes


	public:
		//constructor to call all function
		Storage();

		//inputting in the name.txt
		void In();

		//generating password for each name
		void GeneratePassword();
		
		//outputing name and password to rawdata.txt seperate by space
		void OutRaw();

		//read rawdata.txt
		void readRaw();

		//encrypting password
		void Encrypt();

		//outputting the encrypt file
		void OutEn();

		//get userID
		std::vector<std::string> User();

		//get Password
		std::vector<std::string> Password();
		
		//get EncryptPassword
		std::vector<std::string> EnPassword();

		friend class HashTable;

};
#endif

