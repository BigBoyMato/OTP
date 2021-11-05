#include "user_db.h"

namespace otp{

	DB::DB(const std::map<std::string, std::string>& logins_to_passwords_)
		: logins_to_passwords(logins_to_passwords_)
	{}

	std::map<std::string, std::string> DB::Get() const{
		return logins_to_passwords;
	}

}
