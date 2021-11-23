#include "storage.hpp"

//calling all functions
Storage::Storage(){
	In();
	GeneratePassword(); 
	OutRaw();
	readRaw();
	Encrypt();
	OutEn();
}

//inputting using substring to userID vector
void Storage::In(){
	std::string word; 
        std::ifstream readFile;
        readFile.open("names.txt"); // opening names.txt
        while(std::getline(readFile, word)){ // get whole line using getline
		userID.push_back(word.substr(0, word.find(' '))); // substring subtract everything after space from line
	}
	readFile.close();
	
}

//generate a password through random character
void Storage::GeneratePassword(){
	std::string RandomPassword = "";
	int alphabetSize = 26;
	char alphabet;
	int alphabetInitial;
	srand(time(NULL)); // to produce different result
	for(int i = 0; i < SIZE; i++){
		for(int i=0;i<9; i++){
			alphabetInitial = rand() % alphabetSize;
			alphabet = 'a' + alphabetInitial; //character is chosen from different random number from 1 - 26 
		       	RandomPassword+=alphabet;	// add up to 9 characters to a string
        	}
		password.push_back(RandomPassword); //pass the string into password vector
		RandomPassword = ""; //return the string to default for different result

	}
}	

//Passing name and password to rawdata
void Storage::OutRaw(){
	std::ofstream writeFile;
	writeFile.open("rawdata.txt");
	for(int i = 0; i < SIZE; i++){
		writeFile << userID.at(i) << " " << password.at(i) << std::endl;
	}
	writeFile.close();
}

//read in the raw data, I don't know if we supposed to read the raw data, or we can just use the vector so I'm doing this in case
void Storage::readRaw(){
	std::string word1;
	std::string word2; 
        std::ifstream readFile;
        readFile.open("rawdata.txt"); // opening names.txt
        while(readFile >> word1 >> word2){ // get whole line using getline
		userIDRaw.push_back(word1);
		passwordRaw.push_back(word2);
	}
	readFile.close();

}

//using the vector password to generate encrypted password using vigenere cipher
void Storage::Encrypt(){
	std::string word;
	std::string key = "skyrocket"; // key to be used for vigenere cipher
	std::string fullEncryption = "";
	int passwordSize = 9;
	int alphabetSize = 26;
	int a = 97; // ascii for character before alphabet
	
	//made for better understanding of where key and password character is store
	char firstL;
	char secondL;
	
	//generate encrypted password for all password
	for(int i = 0; i < SIZE; i++){
		word = passwordRaw.at(i);
		
		for(int h = 0; h < passwordSize; h++){
			firstL = key.at(h);
			secondL = word.at(h);
			
			//using ASCII if both character is greater than size of alphabet
			if((int)(firstL + secondL) % a  > alphabetSize - 1){
				fullEncryption += ((int)(firstL + secondL) - alphabetSize) - a; //this would generate the character
			}
			else{ 
				fullEncryption += (int)(firstL + secondL) - a; //else this
			}
		}
			
		EncryptPassword.push_back(fullEncryption);
		fullEncryption = "";
		
	}
	
}

//write to encryptteddata.txt userID and encrypted password
void Storage::OutEn(){
	std::ofstream writeFile;
        writeFile.open("encrypteddata.txt");
        for(int i = 0; i < SIZE; i++){
                writeFile << userIDRaw.at(i) << " " << EncryptPassword.at(i) << std::endl;
        }
        writeFile.close();

}

//return userid vector
std::vector<std::string> Storage::User(){
	return userID;
}

//return password vector
std::vector<std::string> Storage::Password(){
	return password;
}

//return encryptedpassword vector
std::vector<std::string> Storage::EnPassword(){
	return EncryptPassword;
}
