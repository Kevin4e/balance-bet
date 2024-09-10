#include <iostream>
#include <cstdlib>
#include <ctime>

bool BetWin(unsigned int n) {
	if (n == 1) {
		return true;
	}
	return false;
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	unsigned long long currentBal = 1000;

	std::cout << "Current balance: ";
	std::cout << currentBal;

	std::cout << std::endl;

	while (currentBal > 0) {
		unsigned long long userBet;

		std::cout << "Enter your bet: ";
		std::cin >> userBet;

		if (userBet < 0) {
			std::cerr << "Error! You cannot bet on negative!" << std::endl;
		}
		else if (userBet > currentBal) {
			std::cerr << "Error! You cannot bet more than your current balance!" << std::endl;
		}
		else {

			unsigned int fate = rand() % 2;

			if (BetWin(fate)) {
				std::cout << "You won!" << std::endl;
				currentBal += userBet;

			}
			else {
				std::cout << "You lost!" << std::endl;
				currentBal -= userBet;
			}

			std::cout << std::endl;

			std::cout << "Your new balance: ";
			std::cout << currentBal;
		}
		
		std::cout << std::endl;
	}

	std::cout << "You lost!" << std::endl;

	return 0;
}