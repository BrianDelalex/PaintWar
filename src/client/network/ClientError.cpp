/*
** EPITECH PROJECT, 2019
** ClientError.cpp
** File description:
** 
*/

#include "client/network/ClientError.hpp"

ClientError::ClientError(const std::string &msg, const std::string &comp)
{
    this->_msg = msg;
    this->_comp = comp;
}

std::string const &ClientError::getComponent() const
{
    return (this->_comp);
}
