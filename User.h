#pragma once
#include "Server.h"
#include "user_db.h"

namespace otp{

	class User{
	public:
		User() = default;
		User(const otp::DB& db);

	public:
		int InputOtp() const;
		void TryAccessServer(otp::Server& server);

	private:

	};
}
