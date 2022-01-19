/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:58:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/19 01:25:43 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contacts.hpp"

Contacts PhoneBook::add()
{
    Contacts user;
    std::string input;

    std::cout << "Add first Name: ";
    std::getline(std::cin, input);
    user.setName(input);
    std::cout << "Add last Name: ";
    std::getline(std::cin, input);
    user.setLastName(input);
    std::cout << "Add nickname: ";
    std::getline(std::cin, input);
    user.setNickName(input);
    std::cout << "Add phone number: ";
    std::getline(std::cin, input);
    user.setPhoneNumber(input);
    std::cout << "Add your darkest secret: ";
    std::getline(std::cin, input);
    user.setDarkestSecret(input);
    return (user);
}

void PhoneBook::resize_string(std::string str)
{
     if (str.size() > 10)
        std::cout << "|" << std::setw(9) << str.substr(0, 9) << ".";
    else
        std::cout << "|" << std::setw(10) << str.substr(0, 10);
    return ;
}

void PhoneBook::search(int limit)
{
    int index = 1;
    std::string input;

    if (limit == 0)
        std::cout << "No contacts in the phonebook" << std::endl;
    else
    {
        std::cout << "+----------+----------+----------+----------+\n";
        std::cout << "|  INDEX   |   NAME   | SURNAME  | NICKNAME |\n";
        std::cout << "+----------+----------+----------+----------+\n";
        while (index <= limit)
        {
            std::cout << "|" << std::setw(10) << index;
            resize_string(user[index - 1].getName());
            resize_string(user[index - 1].getLastName());
            resize_string(user[index - 1].getNickName());
            std::cout << "|\n";
            index++;
        }
        std::cout << "+----------+----------+----------+----------+\n";
        std::cout << "Search for an existing index (" << 1 << "-" << limit << "): ";
        std::getline(std::cin, input);
        index = std::atoi(input.c_str());
        if (index <= 0 || index > limit)
            std::cout << "Invalid index." << std::endl;
        else
        {
            std::cout << "First Name: " << user[index - 1].getName() << std::endl;
            std::cout << "Last Name: " << user[index - 1].getLastName() << std::endl;
            std::cout << "Nickname: " << user[index - 1].getNickName() << std::endl;
            std::cout << "Phone Number: " << user[index - 1].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << user[index - 1].getDarkestSecret() << std::endl;
        }
    }
}