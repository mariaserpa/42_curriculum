/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:42:41 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/04 17:45:14 by mrabelo-         ###   ########.fr       */
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
		PhoneBook(void);
		~PhoneBook(void);


		void 	addContact();
		void 	searchContact();
};

#endif
