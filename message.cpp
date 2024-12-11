#include "message.h"

Message::Message(std::string newMessage, bool isErr){
    message = newMessage;
    isError = isErr;
}

void Message::printMessage(){
    if(isError){
        std::cerr << "Error: " << message;
    }
    else{
        std::cout << message;
    }

}

void Message::changeMessage(std::string newMessage, bool isErr){
    message = newMessage;
    isError = isErr;
}
