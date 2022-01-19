/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:53:20 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/18 23:59:34 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>
#include <iostream>

class Contacts
{
    std::string  name;
    std::string  lastName;
    std::string  nickname;
    std::string  phonenumber;
    std::string  secret;
    
    public:
        // void    setter(std::string type, std::string value);
        // std::string  getter(std::string type);
        void    setName(std::string value);
        void    setLastName(std::string value);
        void    setNickName(std::string value);
        void    setPhoneNumber(std::string value);
        void    setDarkestSecret(std::string value);

        std::string getName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};

#endif