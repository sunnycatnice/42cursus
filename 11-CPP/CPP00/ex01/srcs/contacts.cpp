/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:58:21 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/19 00:01:49 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

void Contacts::setName(std::string value)
{
    name = value;
}

void Contacts::setLastName(std::string value)
{
    lastName = value;
}

void Contacts::setNickName(std::string value)
{
    nickname = value;
}

void Contacts::setPhoneNumber(std::string value)
{
    phonenumber = value;
}

void Contacts::setDarkestSecret(std::string value)
{
    secret = value;
}

/*
** Those are getters, it means that they are neccessary to get the value of the
** private variables of the class contacts.
*/

std::string Contacts::getName()
{
    return (name);
}

std::string Contacts::getLastName()
{
    return (lastName);
}

std::string Contacts::getNickName()
{
    return (nickname);
}

std::string Contacts::getPhoneNumber()
{
    return (phonenumber);
}

std::string Contacts::getDarkestSecret()
{
    return (secret);
}