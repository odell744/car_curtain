#include "remote.hpp"

namespace atmega8
{
	remote::remote(atmega8::e_pin_id pin_a, atmega8::e_pin_id pin_b, atmega8::e_pin_id pin_c, atmega8::e_pin_id pin_d)
		:
		m_button_a(pin_a, atmega8::read_mode),
		m_button_b(pin_b, atmega8::read_mode),
		m_button_c(pin_c, atmega8::read_mode),
		m_button_d(pin_d, atmega8::read_mode)
	{
		m_button_a.set_state(false);
		m_button_b.set_state(false);
		m_button_c.set_state(false);
		m_button_d.set_state(false);
	};
	
	bool remote::is_button_a_pressed()
	{
		return m_button_a.get_state();
	}
	bool remote::is_button_b_pressed()
	{
		return m_button_b.get_state();
	}
	bool remote::is_button_c_pressed()
	{
		return m_button_c.get_state();
	}
	bool remote::is_button_d_pressed()
	{
		return m_button_d.get_state();
	}
}