/*
** EPITECH PROJECT, 2019
** ServerError.cpp
** File description:
** 
*/

#include "ServerError.hpp"

ServerError::ServerError(const std::string &msg, const std::string &comp)
{
    this->_msg = msg;
    this->_comp = comp;
}

std::string const &ServerError::getComponent() const
{
    return (this->_comp);
}
