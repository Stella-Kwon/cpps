/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:44:33 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 21:31:49 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>


class Zombie{
    private:
        std::string _name;
    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie();
        void announce(void) const;
        void setName(std::string& name);
};

Zombie* zombieHorde( int N, std::string name );
#endif
