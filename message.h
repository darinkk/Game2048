#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

//This class can be changed :)
class Message{
public:
    Message(){isError = false;}
    Message(std::string newMessage, bool isErr = false);
    void printMessage();
    std::string getMessage(){return message;}

private:
    bool isError;
    std::string message;
    void changeMessage(std::string newMessage, bool isErr = false);
};

#endif // MESSAGE_H
