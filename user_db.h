#include <map>
#include <string>

namespace otp{

	class DB{
	public:
		DB(const std::map<std::string, std::string>& logins_to_passwords_);

		std::map<std::string, std::string> Get() const;

	private:
		std::map<std::string, std::string> logins_to_passwords;
	};

}
