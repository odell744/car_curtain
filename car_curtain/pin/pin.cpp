#include "pin.hpp"

#include <avr/io.h>

namespace atmega8
{
	pin::pin(e_pin_id pin_id, e_pin_mode mode)
	:
		m_id(pin_id),
		m_mode(mode)
	{
		int	 l_port = (int)m_id / 8;
		char l_pin_mask = (1 << m_id);
		switch (m_mode)
		{
			case read_mode:
			{
				switch (l_port)
				{
					case PORTB: { DDRB &= ~l_pin_mask; } break;
					case PORTC: { DDRC &= ~l_pin_mask; } break;
					case PORTD: { DDRD &= ~l_pin_mask; } break;
				}
			} break;
			case write_mode:
			{
				switch (l_port)
				{
					case PORTB: { DDRB |= l_pin_mask; } break;
					case PORTC: { DDRC |= l_pin_mask; } break;
					case PORTD: { DDRD |= l_pin_mask; } break;
				}
			} break;
		}
	}

	void pin::set_state(bool state)
	{
		int	 l_port = (int)m_id / 8;
		char l_pin_mask = (1 << m_id);
		if (state)
		{
			switch (l_port)
			{
				case PORTB: { PORTB |= l_pin_mask; } break;
				case PORTC: { PORTC |= l_pin_mask; } break;
				case PORTD: { PORTD |= l_pin_mask; } break;
			}
			} else {
			switch (l_port)
			{
				case PORTB: { PORTB &= ~l_pin_mask; } break;
				case PORTC: { PORTC &= ~l_pin_mask; } break;
				case PORTD: { PORTD &= ~l_pin_mask; } break;
			}
		}
	}

	bool pin::get_state()
	{
		int	 l_port = (int)m_id / 8;
		char l_pin_mask = (1 << m_id);
		
		switch (l_port)
		{
			case PORTB: { return PORTB & l_pin_mask; };
			case PORTC: { return PORTC & l_pin_mask; };
			case PORTD: { return PORTD & l_pin_mask; };
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