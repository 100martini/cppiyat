#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>
#include <limits>

std::string getInput(const std::string& prompt) {
    std::string input;
    
    std::cout << prompt;
    std::getline(std::cin, input);
    
    if (std::cin.eof()) {
        std::cin.clear();
        std::cout << "\nCTRL+D was pressed.\n";
        return "";
    }
    
    return trim(reduceMultipleSpacesToOne(input));
}

int addContact(PhoneBook& phoneBook) {
    std::string firstName = getInput("Enter first name: ");
    if (firstName.empty() && std::cin.eof()) return -1;
    
    std::string lastName = getInput("Enter last name: ");
    if (lastName.empty() && std::cin.eof()) return -1;
    
    if (containsDigit(firstName) || containsDigit(lastName)) {
        std::cout << "\n" << RED << "Ghalat: names should not contain digits." << RESET << std::endl;
        return 0;
    }
    
    std::string nickname = getInput("Enter nickname: ");
    if (nickname.empty() && std::cin.eof()) return -1;
    
    std::string phoneNumber = getInput("Enter phone number: ");
    if (phoneNumber.empty() && std::cin.eof()) return -1;
    
    if (!isValidPhoneNumber(phoneNumber)) {
        std::cout << "\n" << RED << "Ghalat: phone number format is incorrect." << RESET << std::endl;
        return 0;
    }
    
    std::string darkestSecret = getInput("Enter darkest secret: ");
    if (darkestSecret.empty() && std::cin.eof()) return -1;
    
    if (isNotEmptyOrWhitespace(firstName) && 
        isNotEmptyOrWhitespace(lastName) && 
        isNotEmptyOrWhitespace(nickname) && 
        isNotEmptyOrWhitespace(phoneNumber) && 
        isNotEmptyOrWhitespace(darkestSecret)) {
        
        Contact contact;
        contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        phoneBook.addContact(contact);
    } else {
        std::cout << "\n" << RED << "All fields must be filled and cannot contain only spaces." << RESET << std::endl;
    }
    
    return 0;
}

void displayMenu() {
    std::cout << PURPLISH << "\n.." << RESET << "PHONEBOOK MENU" << PURPLISH << "..\n" << RESET;
    std::cout << "Available commands:\n";
    std::cout << "  ADD    - Add a new contact\n";
    std::cout << "  SEARCH - Search for a contact\n";
    std::cout << "  EXIT   - Exit the program\n";
    std::cout << "Enter command: ";
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << PURPLE << "Hey friend, Welcome to my PhoneBook! <3" << RESET << std::endl;
    
    while (true) {
        displayMenu();
        std::getline(std::cin, command);
        
        if (handleInputError()) {
            break;
        }
        
        if (command == "ADD") {
            int result = addContact(phoneBook);
            if (result == -1) {
                break;
            }
        } else if (command == "SEARCH") {
            if (!phoneBook.searchContact()) {
                break;
            }
        } else if (command == "EXIT") {
            std::cout << "\n" << PURPLE << "Goodbye!" << RESET << std::endl;
            break;
        } else {
            std::cout << "\n" << RED << "Unknown command.. Please try again." << RESET << std::endl;
        }
    }
    
    return 0;
}
