/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:33:59 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/06 16:38:02 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl h;

    std::cout << "Test DEBUG level:" << std::endl;
    h.complain("DEBUG");

    std::cout << "\nTest INFO level:" << std::endl;
    h.complain("INFO");

    std::cout << "\nTest WARNING level:" << std::endl;
    h.complain("WARNING");

    std::cout << "\nTest ERROR level:" << std::endl;
    h.complain("ERROR");

    std::cout << "\nTest an unknown level:" << std::endl;
    h.complain("UNKNOWN");

    std::cout << "\nTest an unknown level:" << std::endl;
    h.complain("");
    return 0;
}
