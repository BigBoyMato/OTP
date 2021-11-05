#include "PasswordGenerator.h"

#include <random>

namespace generator{

	PasswordGenerator::PasswordGenerator()
	{
		GeneratePassword();
	}

	void PasswordGenerator::GeneratePassword(){
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(1000,9999);
		current_password_ = dist6(rng);
	}

	int PasswordGenerator::GetPassword() const{
		return current_password_;
	}

}
