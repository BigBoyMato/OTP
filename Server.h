#include "DatabaseManager.h"

#include <fstream>

namespace otp{

	namespace sender{

		void SendMessageToUser(const generator::PasswordGenerator& pg);
	}

	class Server{
	public:
		Server(otp::DBManager& db_manager);

	public:
		otp::DBManager& GetAccessToDB(const int password);

	private:
		otp::DBManager* db_manager_ = nullptr;
	};
}
