// Copyright (c) 2019 Andrei Chirilov All rights reserved.
//
// Created by: Andrei Chirilov
// Created on: November 2019
// This program takes in input and outputs a canada post address


#include <iostream>
#include <string>

std::string CanadaAddress(std::string name,
                        std::string address,
                        std::string city,
                        std::string province,
                        std::string PostalCode,
                        std::string apartment = "") {
    // This function turns inputs into a proper proper canada post address

    // Variables
    std::string mail;

    // Process
    if (apartment.size() != 0) {
         mail = name + "\n" + apartment + " " + address \
                + "\n" + city + " " + province + " " + PostalCode;
    } else {
        mail = name + "\n" + address + "\n" + city + " " + province + \
               " " + PostalCode;
    }
    return mail;
}

int main() {
    // This function gets the input

    // Variables
    std::string name;
    std::string address;
    std::string apt_checker;
    std::string city;
    std::string province;
    std::string PostalCode;
    std::string post;
    std::string apartment = "";

    // Input
    std::cout << "Enter the recipient's full name:" << std::endl;
    std::getline(std::cin, name);
    std::cout << "Enter the destination address:" << std::endl;
    std::getline(std::cin, address);
    std::cout << "Does the recipient live in an apartment (y/n):" << std::endl;
    std::getline(std::cin, apt_checker);
    if (apt_checker == "y" || apt_checker == "yes") {
        std::cout << "Enter the recipient's apartment number:" << std::endl;
        std::getline(std::cin, apartment);
    }
    std::cout << "Enter the recipient's city:" << std::endl;
    std::getline(std::cin, city);
    std::cout << "Enter the recipient's province/territory:" << std::endl;
    std::getline(std::cin, province);
    std::cout << "Enter the recipient's postal code:" << std::endl;
    std::getline(std::cin, PostalCode);;

    // Call CanadaAddress function
    if (apartment != "") {
        post = CanadaAddress(name, address, city,
                              province, PostalCode,
                              apartment);
    } else {
        post = CanadaAddress(name, address, city,
                              province, PostalCode);
    }

    // Output
    std::cout << "" << std::endl;
    std::cout << post << std::endl;
}
