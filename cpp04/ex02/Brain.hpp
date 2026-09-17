/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:59:19 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:20:04 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		~Brain();
		void	setIdea(int i, const std::string& idea);
		const std::string& getIdea(int i) const ;
		
	protected:
		std::string ideas[100];
};

#endif
