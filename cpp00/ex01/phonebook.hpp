/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:42:41 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/02 15:57:39 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

# define TABLE " ___________________________________________ \n" \
				"|     INDEX|   F. NAME|   L. NAME|  NICKNAME|\n" \
				"|___________________________________________|\n"

class PhoneBook {
	private:
		Contact contact[8]; 
		int 	count;

	public:
		void 	addContact();
		void 	searchContact();
};

#endif