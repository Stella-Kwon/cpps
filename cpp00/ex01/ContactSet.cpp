/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactSet.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:21:19 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/02 10:04:21 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// void Contract::setFirstName(const std::string& first_name) // parameter랑 멤머이름이 같으면 this->를 사용하여 정확히 뭐가 뭔지 명시
// {
//     this->first_name = first_name;
// }

// void Contact::setFirstName(const std::string& first)
// {
//     first_name = first;
// }
// void Contact::setLastName(const std::string& last)
// {
//     last_name = last;
// }
// void Contact::setNickname(const std::string& nick)
// {
//     nick_name = nick;
// }
// void Contact::setPhoneNumber(const std::string& phone)
// {
//     phone_number = phone;
// }
// void Contact::setDarkestSecret(const std::string& secret)
// {
//     darkest_secret = secret;
// }

Contact::Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret)
: first_name(first), last_name(last), nick_name(nick), phone_number(phone), darkest_secret(secret)
{
    std::cout << "Initializing contents of the Contact\n";
}