#include "pin.hpp"

#include <avr/io.h>

namespace atmega8
{
	pin::pin(e_pin_id pin_id, e_pin_mode mode)
	:
		m_id(pin_id),
		m_mode(mode)
	{
		if (m_id == port_none)
			return;
		
		int	 l_port = (int)m_id / 8;
		char l_pin_mask = (1 << m_id);
		switch (m_mode)
		{
			case read_mode:
			{
				switch (l_port)
				{
					case 0: { DDRB &= ~l_pin_mask; } break;
					case 1: { DDRC &= ~l_pin_mask; } break;
					case 2: { DDRD &= ~l_pin_mask; } break;
				}
			} break;
			case write_mode:
			{
				switch (l_port)
				{
					case 0: { DDRB |= l_pin_mask; } break;
					case 1: { DDRC |= l_pin_mask; } break;
					case 2: { DDRD |= l_pin_mask; } break;
				}
			} break;
		}
	}

	void pin::set_state(bool state)
	{
		if (m_id == port_none)
			return;
		
		int	 l_port = (int)m_id / 8;
		char l_pin_mask = (1 << m_id);
		if (state)
		{
			switch (l_port)
			{
				case 0: { PORTB |= l_pin_mask; } break;
				case 1: { PORTC |= l_pin_mask; } break;
				case 2: { PORTD |= l_pin_mask; } break;
			}
		} else {
			switch (l_port)
			{
				case 0: { PORTB &= ~l_pin_mask; } break;
				case 1: { PORTC &= ~l_pin_mask; } break;
				case 2: { PORTD &= ~l_pin_mask; } break;
			}
		}
	}

	bool pin::get_state()
	{
		if (m_id == port_none)
			return false;
		
		int	 l_port = (int)m_id / 8;
		char l_pin_mask = (1 << m_id);
		
		switch (l_port)
		{
			case 0: { return PORTB & l_pin_mask; };
			case 1: { return PORTC & l_pin_mask; };
			case 2: { return PORTD & l_pin_mask; };
		}
		return false;
	}

	pin_id_t pin::get_id()
	{
		return m_id;
	}
	e_pin_mode pin::get_mode()
	{
		return m_mode;
	}
}