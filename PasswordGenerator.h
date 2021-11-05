#pragma once

namespace generator{

	class PasswordGenerator{
	public:
		PasswordGenerator();

	public:
		void GeneratePassword();
		int GetPassword() const;
	private:
		int current_password_;
	};
}
