/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:02:52 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/01 10:53:43 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

// int main(int argc, char **argv)
// {
//     int i, j;
//     char out;
//     i = 0;
//     j = 0;
//     if (argc == 1)
//         std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
//     else
//     {
//         while (argv[++i])
//         {
//             j = 0;
//             while(argv[i][j])
//             {
//                 out = std::toupper(argv[i][j]);
//                 std::cout << out;
//                 j++;
//             }
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }

#include <algorithm>
#include <cstring>
int main(int argc, char **argv)
{
    int i;
    
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
       for(i = 1; i < argc; i++)
       {
        //first, last(until the '\0'), result, unary_op => i will affect each of element but not \0
            std::transform(argv[i], argv[i] + std::strlen(argv[i]), argv[i], ::toupper);
            std::cout << argv[i];
       }
        std::cout << std::endl;
    }
    return 0;
}