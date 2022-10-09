#include <avr/io.h>
#include "remote/remote.hpp"

#define F_CPU 8000000L

int main(void)
{
	atmega8::remote remote_contol(atmega8::port_c_2, // A 
								  atmega8::port_c_1, // B
								  atmega8::port_none, // C
								  atmega8::port_none);// D
    while (1) 
    {
		
    }
}

