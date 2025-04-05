/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:45:58 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 00:28:36 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <limits>
#include <cctype> 
class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact(); // 기본 초기화. constructor
        ~Contact(); // 소멸자. deconstructor. 알아서 사용다하면 부르지않아도 사용되어짐.
        //& 하면 참조가되서 copy되는게 아니라 메모리 효율적으로 사용. :: nullptr가 아닐때사용 - 메모리 효율성을위해 참조를 많이사용
        //* 포인터를 쓸때는 nullptr일수 가능성이 높을때 사용. new 또는 포인터로 불러올때 필요. - 주로 많이 사용안함.

        //should be the same name as class to be called as constructor to initialize class.
        Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret);
        //if there is nothing to mention more inside of the function
        // Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret) 
        // : first_name(first), last_name(last), nick_name(nick), phone_number(phone), darkest_secret(secret){};
        // or
        // Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret) 
        // {
        //     first_name = first;
        //     last_name = last;
        //     nick_name = nick;
        //     phone_number = phone;
        //     darkest_secret = secret;
        // } will work too.
        //initialization list. : will compile during the initailizing the class : 
        //if variable member is initialize as const cannot be changing after the initialization.
        //For ex: all private member set as const;
        //   Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret) 
        // : first_name(first), last_name(last), phone_number(phone), darkest_secret(secret){}
        //only top will be allowed 
        
        // void Contact::setFirstName(const std::string& first);
        // void Contact::setLastName(const std::string& last);
        // void Contact::setNickname(const std::string& nick);
        // void Contact::setPhoneNumber(const std::string& phone);
        // void Contact::setDarkestSecret(const std::string& secret);
        
        const std::string& getFirstName()const;
        const std::string& getLastName()const;
        const std::string& getNickName()const;
        const std::string& getPhoneNumber()const;
        const std::string& getDarkestSecret()const;
        //함수 끝의 const :: 객체를 변경하지않겠다는. - 이 함수내에서 객체의 내용을 contents를 읽기만하지 변경하지는 않겠다라는 애기
};

#endif