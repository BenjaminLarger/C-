/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/19 11:57:48 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main () {
  Bureaucrat  Spencer("Spencer", 1);
  Bureaucrat  Scott(0);
  Bureaucrat  Rick("Rick", 151);

  std::cout << std::endl << "-------------------------------" << std::endl;
  Spencer.incrementGrade();
  Spencer.decrementGrade();
  std::cout << "-------------------------------" << std::endl;

  std::cout << Spencer << std::endl << std::endl;
  return 0;
}