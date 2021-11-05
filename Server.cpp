#include "Server.h"

#include <exception>

using namespace std::string_literals;

namespace otp{

	namespace sender{

		void SendMessageToUser(const generator::PasswordGenerator& pg){
			std::ofstream message_to_user;
			message_to_user.open("password_message.txt");
			message_to_user.clear();
			message_to_user << pg.GetPassword();
		}
	}

	Server::Server(otp::DBManager& db_manager)
		: db_manager_(&db_manager)
	{}

	// protection to db acceess
	otp::DBManager& Server::GetAccessToDB(const int password){
		if (password == db_manager_->GetPassword()){
			return *db_manager_;
		}
		throw std::logic_error("wrong access password"s);
	}
}

