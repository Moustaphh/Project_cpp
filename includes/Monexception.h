#ifndef MONEXCEPTION_H_INCLUDED
#define MONEXCEPTION_H_INCLUDED

#include <iostream>
#include <exception>

namespace monXception{


class MonException:public std::exception
{
    private:
        std::string cause;

    public:
        MonException(std::string c) throw()
        {
            cause = c;
        }

        ~MonException() throw() //Interdit le fait que cette fonction renvoie une exception
        {

            std::cout << std::endl << "Dtor MonException" << std::endl;
        }

        const char* what() const  throw()
        {
            //c_str() Convertit un string en const char *;
            return cause.c_str();
        }

};
}



#endif // MONEXCEPTION_H_INCLUDED