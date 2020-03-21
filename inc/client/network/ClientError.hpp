/*
** EPITECH PROJECT, 2019
** ClientError.hpp
** File description:
** 
*/

#ifndef CLIENTERROR_HPP_
#define CLIENTERROR_HPP_

#include "exception"
#include "iostream"

class ClientError : public std::exception
{
public:
    ClientError(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override { return (this->_msg.data()); }
private:
    std::string _msg;
    std::string _comp;
};

#endif
