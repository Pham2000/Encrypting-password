#include "start.hpp"

Start::Start(){
	working();
}
void Start::working(){
			// vector to store rawdata and encrypt from storage
			std::vector<std::string> encryptData; 
			std::vector<std::string> userID;
			int arraySize = 5; // array size to input easier

			std::string inputU[arraySize];
			std::string inputP[arraySize];
			std::string inputPC[arraySize];

			int VSize = 88799; // size of the vector in storage

	
			//setting main vector to storage vector
			encryptData = program.EnPassword(); 
			userID = program.User();

			//Hashtable able to encrypt the vectors
			for(int i = 0; i < VSize; i++){
				Encrypt.insert(userID.at(i), encryptData.at(i));
			}

			//1-5 user input
			for(int i = 0; i < arraySize; i++){
				inputU[i] = userID.at(i);
				inputP[i] = encryptData.at(i);
				inputPC[i] = encryptData.at(i);
			}
	
			//setting the first character of the illegal password as 'w'
			for(int i = 0; i < arraySize; i++){
				inputPC[i].front() = 'w';
			}

			//printing out legal since raw and encrypt txt share same userid
			std::cout << "Legal: " << std::endl;
			std::cout << "UserId		Password	Result" << std::endl;
			for(int i = 0; i < arraySize; i++){
				if(Encrypt.lookup(inputU[i]) != nullptr){
					if(inputP[i].compare(Encrypt.lookup(inputU[i])->password) == 0){
						std::cout << inputU[i] <<std::setw(20) << inputP[i] << std::setw(12) << "match" << std::endl;
					}
					else{
						std::cout << inputU[i] << std::setw(20) << inputPC[i] << std::setw(15) << "no match" << std::endl;
					}
			
				}
			}
	
			//print out illegal
			std::cout << std::endl << "Illegal: " << std::endl;
			std::cout << "UserId		Password	Result" << std::endl;
	
			for(int i = 0; i < arraySize; i++){
		
				if(Encrypt.lookup(inputU[i]) != nullptr){
					if(inputPC[i].compare(Encrypt.lookup(inputU[i])->password) == 0){
						std::cout << inputU[i] << std::setw(20) << inputP[i] << std::setw(12) << "match" << std::endl;
					}
					else{ 
						std::cout << inputU[i] << std::setw(20) << inputPC[i] << std::setw(15) << "no match" << std::endl;
					}
			
				}
			}
		}

