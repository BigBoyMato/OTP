#pragma once
#include "PasswordGenerator.h"

namespace otp{

	class DBManager{
	public:
		DBManager(const int access_password);

	public:
		int GetPassword() const;
		void IntaractWithDb();

	private:
		int access_password_;
	};
}
