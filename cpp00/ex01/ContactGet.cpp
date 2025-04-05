/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactGet.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:46:00 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 00:12:13 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string& Contact::getFirstName() const
{
    return first_name;
}

const std::string& Contact::getLastName() const
{
    return last_name;
}

const std::string& Contact::getNickName() const
{
    return nick_name;
}

// // by giving it as an reference and type the fucntion as const would Violation of the rules :: have a chance to chage the value
// std::string& Contact::getPhoneNumber() const 
// {
//     return phone_number;
// }
// // by copying the value it is fine : no changes  will happen in original value
// std::string Contact::getPhoneNumber() const 
// {
//     return phone_number;
// }
// // this will let you have other behaviors that can have changes inside of this function without const traits off for the function
// const std::string& Contact::getPhoneNumber()
// {
//     return phone_number;
// }
// giving a const value return and function will be const aht it will not change any members values
const std::string& Contact::getPhoneNumber() const
{
    return phone_number;
}
const std::string& Contact::getDarkestSecret() const
{
    return darkest_secret;
}