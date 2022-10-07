#include <avr/io.h>
#include "remote/remote.hpp"

int main(void)
{
	atmega8::pin pp(atmega8::port_d_0, atmega8::write_mode);
	pp.set_state(true);
	
	
    while (1) 
    {
    }
}

