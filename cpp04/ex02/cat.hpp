/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:44 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/22 12:45:32 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "aanimal.hpp"
# include "brain.hpp"

class Cat : public AAnimal{
    private :
            Brain* brain;
    protected :
        std::string type;
    public :
        Cat();
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        const std::string& getType() const override;
        void makeSound() const override;
        Brain* getBrain() const;
        //즉, 포인터 자체는 복사되지만 가리키는 객체(Brain)는 하나이고, 그 객체의 소유권은 여전히 Dog가 가지고 있습니다.
};

#endif