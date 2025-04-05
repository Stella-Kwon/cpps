/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:10:36 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/22 12:37:05 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <array>

class Brain {
    private : 
        // std::string ideas [100]; // c style
        std::array<std::string, 100>ideas; // c++ style
    public : 
        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);

        std::string getIdeas() const;
        std::string getAnIdea(int index) const;
        void setIdeas(int index, std::string& idea);
};
#endif
