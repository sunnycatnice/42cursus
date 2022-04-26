/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:34:29 by dmangola          #+#    #+#             */
/*   Updated: 2022/04/19 14:35:04 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed3.hpp"
#include "Point.hpp"

int main()
{
    Point a(1.0f, 1.0f);
    Point b(1.0f, 5.0f);
    Point c(5.0f, 1.0f);
    Point pt(1.1f, 2.0f);

    //check if pt is in triangle
    if (pt.bsp(a, b, c, pt))
        std::cout << "pt is in triangle" << std::endl;
    else
        std::cout << "pt is not in triangle" << std::endl;

    return (0);
}
