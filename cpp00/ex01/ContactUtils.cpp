/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:21:14 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 00:37:45 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//already std::string initialized "" for you
// so dont have to 
// Contact::Contact()
//     : first_name(""), last_name(""), nick_name(""),
//       phone_number(""), darkest_secret("") {
//     std::cout << "Default Constructor Called!" << std::endl;
// }
// or
// Contact::Contact()
//     : Contact("", "", "", "", "") { 
//     std::cout << "Creating Contact" << std::endl;
// }

Contact::Contact()
{
    // std::cout << "Creating Contact" << std::endl;
}

Contact::~Contact()
{
    // std::cout << "Destroying Contact" << std::endl;
}
