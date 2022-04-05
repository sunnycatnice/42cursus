/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/04/05 17:20:56 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed2.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << std::endl << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl << std::endl;

    std::cout << "a is " << a.to_int() << " as integer" << std::endl;
    std::cout << "b is " << b.to_int() << " as integer" << std::endl;
    std::cout << "c is " << c.to_int() << " as integer" << std::endl;
    std::cout << "d is " << d.to_int() << " as integer" << std::endl << std::endl;

    std::cout << "a is " << a.to_float() << " as float" << std::endl;
    std::cout << "b is " << b.to_float() << " as float" << std::endl;
    std::cout << "c is " << c.to_float() << " as float" << std::endl;
    std::cout << "d is " << d.to_float() << " as float" << std::endl << std::endl;

    return 0;
}
