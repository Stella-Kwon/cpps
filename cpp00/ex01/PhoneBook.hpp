/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:48:03 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/02 21:54:20 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define MAX_CONTACT 8
class PhoneBook {
    private:
        Contact _contact[MAX_CONTACT];
        int     _currentPosition;
    public:
        PhoneBook();
        ~PhoneBook();
        
        void addContact(std::string& first_name, std::string& last_name, std::string& nick_name,
			std::string& phone_number, std::string& darkest_secret);
        int getPosition() const;
        Contact& getElementContact(int i);
};

#endif