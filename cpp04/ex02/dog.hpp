/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:44 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/22 12:45:19 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "aanimal.hpp"
# include "brain.hpp"
# include <memory> // std::unique_ptr
class Dog : public AAnimal{
    private :
        // Brain* brain;
        std::unique_ptr<Brain> brain; // unique ptr
    protected :
        std::string type;
    public :
        Dog();
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        const std::string& getType() const override;
        void makeSound() const override;
        const std::unique_ptr<Brain>& getBrain() const;
        // Unique pointer cannot copied, so it has to be returned with &
//This method returns referenced value but as it is const methods, this is not allowed.
//becasue
// class Dog {
//       std::unique_ptr<Brain> brain;
//       public:
//          // const 메서드에서 non-const 레퍼런스 반환 (컴파일 에러가 나는 코드)
//          std::unique_ptr<Brain>& getBrain() const {
//               return brain;
//             }
// };

// int main() {
//     const Dog dog;        // dog는 const 객체
    
//     // getBrain()이 non-const 레퍼런스를 반환한다면:
//     auto& brain_ref = dog.getBrain();  
    
//     // brain_ref를 통해 dog의 brain을 수정할 수 있게 됨:
//     brain_ref.reset(new Brain());  // dog의 brain이 변경됨!
//     // 이는 dog가 const인데도 내용이 변경된다는 것을 의미
// }



//// 일반 포인터 반환 - OK
// Brain* Dog::getBrain() const {
//     return brain;
// }

// // 레퍼런스 반환 - 에러
// std::unique_ptr<Brain>& Dog::getBrain() const {
//     return brain;  // Error!
// }
// 차이가 나는 이유:

// 포인터 반환

// 포인터는 값이 복사되어 반환됨
// 반환된 포인터로 원본 데이터를 수정할 수 있지만, 포인터 자체는 복사본


// 레퍼런스 반환

// 레퍼런스는 원본에 대한 직접적인 참조
// const 메서드에서 non-const 레퍼런스를 반환하면 const 객체의 내용을 변경할 수 있게 됨
// 따라서 const 메서드에서는 const 레퍼런스로 반환해야 함



// 간단히 말해서, 레퍼런스로 반환할 때만 이런 제약이 있고, 포인터나 값 반환의 경우에는 이런 제약이 없습니다.
};

#endif