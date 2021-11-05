#include "User.h"

#include <iostream>
#include <exception>

namespace otp{

	User::User(const otp::DB& db)
	{
		std::string login, password;
		std::cout << "Enter login: ";
		std::cin >> login;
		std::cout << std::endl;
		std::cout << "Enter password: ";
		std::cin >> password;
		std::cout << std::endl;

		const auto logins_to_passwords = db.Get();
		if (logins_to_passwords.find(login) != logins_to_passwords.end()){
			if (logins_to_passwords.at(login) == password){
				std::cout << "user is authorized" << std::endl;
			}else{
				throw std::logic_error("wrong user password");
			}
		}else{
			throw std::logic_error("user login not found");
		}
	}

	int User::InputOtp() const{
		int OTP;
		std::cout << "Enter otp: ";
		std::cin >> OTP;
		std::cout << std::endl;
		return OTP;
	}

	void User::TryAccessServer(otp::Server& server){
		const auto access_password = InputOtp();
		try{
			auto db = server.GetAccessToDB(access_password);
			db.IntaractWithDb();
		}catch(...){
			std::cerr << "wrong OTP" << std::endl;
			return;
		}
	}
}
