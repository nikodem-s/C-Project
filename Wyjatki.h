//
// Created by nikos on 05.01.2022.
//

#ifndef SALANIKODEM_ETAP1_WYJATKI_H
#define SALANIKODEM_ETAP1_WYJATKI_H
#include <string>

struct IdError : std::exception {
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit IdError(const std::string & msg = "Wrong ID, should be INT between [1-255]"){
        message = msg;
    };
};
struct intError : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit intError( const std::string& msg = "Wrong type, shoud be INT >= 1!"){
        message = msg;
    }
};
struct stringError : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit stringError(const std::string &msg = "Error, use letters A-Z or a-z"){
        message = msg;
    }
};
struct IdDuplicate : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit IdDuplicate(const std::string &msg = "Error, person with that ID already exists"){
        message = msg;
    }
};
struct SaveError : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit SaveError(const std::string &msg = "Error, couldn't save file - check if you had added Employee"){
        message = msg;
    }
};
struct ReadError : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit ReadError(const std::string &msg = "Error, couldn't read file - check if it exists. If not use save option"){
        message = msg;
    }
};
struct NoID : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit NoID(const std::string &msg = "Error, person with that ID is not in database"){
        message = msg;
    }
};
struct EmptyBase : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit EmptyBase(const std::string &msg = "Error, database is empty!"){
        message = msg;
    }
};
struct AlreadyInWork : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit AlreadyInWork(const std::string &msg = "Error, this person is already in work!"){
        message = msg;
    }
};
struct NoInWork : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit NoInWork(const std::string &msg = "Error, this person is not in the work!"){
        message = msg;
    }
};
struct HasDaysOffError : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit HasDaysOffError(const std::string &msg = "Error, this person has vacation!"){
        message = msg;
    }
};
struct L4_Error : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit L4_Error(const std::string &msg = "ERROR, THIS PERSON IS ON L4 END IT IN ORDER TO DO ANYTHING ELSE"){
        message = msg;
    }
};
struct TooMuchMonthsError : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit TooMuchMonthsError(const std::string &msg = "Error, you can work max 12 months on time!"){
        message = msg;
    }
};
struct NoMoreL4 : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit NoMoreL4(const std::string &msg = "Error, you don't have enough sick days"){
        message = msg;
    }
};
struct NoMoreDaysOff : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit NoMoreDaysOff(const std::string &msg = "Error, you don't have enough daysOff"){
        message = msg;
    }
};
struct isNotOnL4 : std::exception{
    std::string message;
    const char *what() const noexcept override{
        return message.c_str();
    }
    explicit isNotOnL4(const std::string &msg = "Error, this person is not on L4"){
        message = msg;
    }
};
#endif //SALANIKODEM_ETAP1_WYJATKI_H
