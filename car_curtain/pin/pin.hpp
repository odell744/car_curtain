#ifndef PIN_WORKER_H_
#define PIN_WORKER_H_

#include <avr/io.h>

#define PIN_WRITE_MODE 1
#define PIN_READ_MODE  0

namespace atmega8
{
	enum e_pin_mode
	{
		write_mode = 1,
		read_mode = 0,
	};
	enum e_pin_id
	{
		port_b_0 = 0,
		port_b_1 = 1,
		port_b_2 = 2,
		port_b_3 = 3,
		port_b_4 = 4,
		port_b_5 = 5,
		port_b_6 = 6,
		port_b_7 = 7,
		port_c_0 = 8,
		port_c_1 = port_c_0 + 1,
		port_c_2 = port_c_0 + 2,
		port_c_3 = port_c_0 + 3,
		port_c_4 = port_c_0 + 4,
		port_c_5 = port_c_0 + 5,
		port_c_6 = port_c_0 + 6,
		port_c_7 = port_c_0 + 7,
		port_d_0 = 16,
		port_d_1 = port_d_0 + 1,
		port_d_2 = port_d_0 + 2,
		port_d_3 = port_d_0 + 3,
		port_d_4 = port_d_0 + 4,
		port_d_5 = port_d_0 + 5,
		port_d_6 = port_d_0 + 6,
		port_d_7 = port_d_0 + 7,
	};
	typedef uint8_t pin_id_t;

	class pin
	{
		private:
		e_pin_id	m_id;
		e_pin_mode	m_mode;
		public:
		pin(e_pin_id pin_id, e_pin_mode mode);

		void	   set_state(bool state);
		bool	   get_state();
		
		e_pin_mode get_mode();
		pin_id_t   get_id();
	};
}

#endif /* !PIN_WORKER_H_ */