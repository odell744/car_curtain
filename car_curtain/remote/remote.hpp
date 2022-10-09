#ifndef REMOTE_H_
#define REMOTE_H_

#include "../pin/pin.hpp"

namespace atmega8
{
	class remote
	{
		pin m_button_a, 
			m_button_b, 
			m_button_c, 
			m_button_d;
	public:
		remote(atmega8::e_pin_id pin_a, atmega8::e_pin_id pin_b, atmega8::e_pin_id pin_c, atmega8::e_pin_id pin_d);


		bool is_button_a_pressed();
		bool is_button_b_pressed();
		bool is_button_c_pressed();
		bool is_button_d_pressed();
	};
}

#endif /* !REMOTE_H_ */