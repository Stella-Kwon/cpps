/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:44:33 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 20:59:08 by skwon2           ###   ########.fr       */
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
        Zombie();
        ~Zombie();
        Zombie(std::string name);
        void announce(void) const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif
