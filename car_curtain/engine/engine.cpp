#include "engine.hpp"

namespace atmega8
{
	engine::engine(atmega8::e_pin_id left_pin, atmega8::e_pin_id right_pin)
		:
		m_left_pin(left_pin, write_mode),
		m_right_pin(right_pin, write_mode),
		m_state(atmega8::engine_stopped)
	{
		m_left_pin.set_state(false);
		m_right_pin.set_state(false);
	}
	
	void engine::stop_engine()
	{
		m_left_pin.set_state(false);
		m_right_pin.set_state(false);
		m_state = engine_stopped;
	}
	
	e_engine_state engine::get_state()
	{
		return m_state;
	}
	
	void engine::turn_left_on()
	{
		switch (m_state)
		{
			case engine_neutral:
				stop_engine();
			break;
			
			case engine_turn_right:
				m_right_pin.set_state(false);
			case engine_stopped:
				m_left_pin.set_state(true);
				m_state = engine_turn_left;
			break;
			
			case engine_turn_left:
				m_left_pin.set_state(false);
				m_state = engine_stopped;
			break;
		}	
	}
	void engine::turn_right_on()
	{
		switch (m_state)
		{
			case engine_neutral:
				stop_engine();
			break;
			
			case engine_turn_left:
				m_left_pin.set_state(false);
			case engine_stopped:
				m_right_pin.set_state(true);
				m_state = engine_turn_right;
			break;
			
			case engine_turn_right:
				m_right_pin.set_state(false);
				m_state = engine_stopped;
			break;
		}
	}
}