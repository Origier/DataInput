// Data Input
// By: Aaron McDonald
// Function for reading in a double value from the console

#include <string>
#include <iostream>
#include <limits>
#include <ios>

// Gets a double value from the user while ensuring that the data is valid
double get_double() {
	std::string valid_characters = "0123456789."; // Declaring all of the valid characters that are acceptable input
	std::string tester_string; // used for validating data
	bool has_decimal; // used for ensuring there is only one decimal 
	bool all_num;
	while (true) {
		std::cin.ignore();
		std::getline(std::cin, tester_string);
		all_num = true;
		has_decimal = false;
		// Looping over the string and testing to ensure that each charater is a part of the valid characters set
		for (int i = 0; i < tester_string.size(); i++) {
			if (valid_characters.find(tester_string[i]) == std::string::npos) {
				std::cout << "Please enter only numbers or a period, no characters: ";
				all_num = false;
				break;
			}

			// Ensuring that the string only contains one decimal point
			else if (tester_string[i] == '.') {
				if (has_decimal) {
					all_num = false;
					std::cout << "Please only enter one decimal point: ";
					break;
				}
				has_decimal = true;
			}
		}

		// Returning the string made double assuming all requirements are met
		if (all_num) {
			return stod(tester_string);
		}
		else {
			continue;
		}

	}
}