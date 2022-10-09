#ifndef ENGINE_H_
#define ENGINE_H_

#include "../pin/pin.hpp"

namespace atmega8
{
	enum e_engine_state
	{
		engine_stopped = 0,
		engine_turn_left = 1,
		engine_turn_right = 2,
		engine_neutral = engine_turn_left + engine_turn_right
	};
	
	class engine
	{
		atmega8::pin	m_left_pin,
						m_right_pin;
						
		e_engine_state	m_state;
	public:
		engine(atmega8::e_pin_id left_pin, atmega8::e_pin_id right_pin);
		
		void			turn_left_on();
		void			turn_right_on();
		void			stop_engine();
		
		e_engine_state	get_state();
	};
	
	
}

#endif /* !ENGINE_H_ */