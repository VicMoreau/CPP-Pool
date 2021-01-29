/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:45:52 by vmoreau           #+#    #+#             */
/*   Updated: 2021/01/28 17:15:47 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	_energy = 120;
	_max_energy = 120;
	_melee_attack_dmg = 60;
	std::cout << "Default Ninjatrap Constructor called" << std::endl;
}

NinjaTrap::NinjaTrap( std::string name )
{
	_name = name;
	_hp = 60;
	_max_hp = 60;
	_energy = 120;
	_max_energy = 120;
	_lvl = 1;
	_melee_attack_dmg = 60;
	_range_attack_dmg = 5;
	_armor = 0;
	std::cout << "NinjaTrap <" << this->_name << ">: \"A ninja is always invisible... *SHIOUUU*\"" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap <" << this->_name << ">: \"My shadow will never stop tracking you !!!\"" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & n)
{
	*this = n;
	std::cout << "NinjaTrap <" << this->_name << ">: \"You are my shadow!\"" << std::endl;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs)
{
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_max_hp = rhs._max_hp;
	this->_energy= rhs._energy;
	this->_max_energy = rhs._max_energy;
	this->_lvl = rhs._lvl;
	this->_melee_attack_dmg = rhs._melee_attack_dmg;
	this->_range_attack_dmg = rhs._range_attack_dmg;
	this->_armor = rhs._armor;

	return (*this);
}

void		NinjaTrap::ninjaShoebox( FragTrap const & target )
{
	std::cout << "NinjaTrap <" << this->_name << "> : Sneaks behind Fragtrap <" << target.get_name() << ">, and pulls his pants down!" << std::endl;
}

void		NinjaTrap::ninjaShoebox( ScavTrap const & target )
{
	std::cout << "NinjaTrap <" << this->_name << "> : Hides in the shadows and scares ScavTrap <" << target.get_name() << ">." << std::endl;
}

void		NinjaTrap::ninjaShoebox( NinjaTrap const & target )
{
	std::cout << "NinjaTrap <" << this->_name << "> : Provoke NinjaTrap <" << target.get_name() << ">, into a ninjustsu fight !" << std::endl;
}

int			NinjaTrap::rangedAttack(std::string const & target) const
{
	std::cout << "NinjaTrap <" << this->_name << "> ranged attack <" << target << ">: \"You can't see my shadows Shurikens\"" << std::endl;
	return (this->_range_attack_dmg);
}

int			NinjaTrap::meleeAttack(std::string const & target) const
{
	std::cout << "NinjaTrap <" << this->_name << "> attack <" << target << "> in melee: \"Take my shadow punch!\"" << std::endl;
	return (this->_melee_attack_dmg);
}