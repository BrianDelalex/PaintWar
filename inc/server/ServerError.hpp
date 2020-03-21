/*
** EPITECH PROJECT, 2019
** ServerError.hpp
** File description:
** 
*/

#ifndef SERVERERROR_HPP_
#define SERVERERROR_HPP_

#include "exception"
#include "iostream"

class ServerError : public std::exception
{
public:
    ServerError(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override { return (this->_msg.data()); }
private:
    std::string _msg;
    std::string _comp;
};

#endif
