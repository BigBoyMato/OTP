#include "User.h"

#include <iostream>

void RunSession(){
	std::cout << "session created" << std::endl;

	// ---------- Admin Access ---------- //
	// initiall DB
	const auto db = otp::DB({{"login", "password"}, {}});

	// creating gate
	generator::PasswordGenerator pg;
	otp::DBManager manager(pg.GetPassword());
	otp::Server server(manager);

	// sending otp
	otp::sender::SendMessageToUser(pg);
	// ---------- ------------ ---------- //


	// ---------- User Access ---------- //
	// creating access try
	otp::User user(db);
	user.TryAccessServer(server);
	// ---------- ----------- ---------- //

	std::cout << "session expired" << std::endl;
}

int main(){
	RunSession();

	return 0;
}
