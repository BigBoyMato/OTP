#include "DatabaseManager.h"

#include <string>
#include <iostream>
#include <fstream>

namespace otp{

	DBManager::DBManager(const int access_password)
		: access_password_(access_password)
	{}

	DBManager::GetPassword() const{
		return access_password_;
	}

	void DBManager::IntaractWithDb(){
		std::string instruction;
		std::cout << "Enter instruction: ";
		std::cin >> instruction;
		std::cout << std::endl;
		std::ofstream db;
		db.open("file_to_access.txt");
		db << instruction << std::endl;
	}
}
