#include <iostream>
#include <random>
#include <chrono>
#include <ctime>

bool BetWin(unsigned int fate) {
	return fate == 1;
}

int main() {
	std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<unsigned int> range(0, 1);

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

			unsigned int fate = range(generator);

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

	std::cout << std::endl;
	std::cout << "Game over! You lost all your balance!" << std::endl;

	return 0;
}