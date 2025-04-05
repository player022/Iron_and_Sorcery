#ifndef DEBUG_H
#define DEBUG_H

#include "bn_sprite_text_generator.h"
#include "source_han_sans_jp_sprite_font.h"
#include "bn_vector.h"
#include "bn_string.h"
#include "bn_sprite_ptr.h"
#include "bn_log.h"

class Debug
{
public:
	Debug(int time, int cursor_x, int cursor_y) : 
		_text_generator(source_han_sans_jp_sprite_font)
	{
		update(time, cursor_x, cursor_y);
	}

	void update(int time, int cursor_x, int cursor_y)
	{
		_text_sprites0.clear();
		_time_text = "TIME: " + bn::to_string<16>(time);
		_text_generator.generate(45, -70, _time_text, _text_sprites0);

		_text_sprites1.clear();
		_cursor_x_text = "cursor_x: " + bn::to_string<16>(cursor_x);
		_text_generator.generate(45, -60, _cursor_x_text, _text_sprites1);

		_text_sprites2.clear();
		_cursor_y_text = "cursor_y: " + bn::to_string<16>(cursor_y);
		_text_generator.generate(45, -50, _cursor_y_text, _text_sprites2);
	}

private:
	bn::sprite_text_generator _text_generator;
	bn::vector<bn::sprite_ptr, 128> _text_sprites0;
	bn::vector<bn::sprite_ptr, 128> _text_sprites1;
	bn::vector<bn::sprite_ptr, 128> _text_sprites2;
	bn::string<32> _time_text;
	bn::string<32> _cursor_x_text;
	bn::string<32> _cursor_y_text;
};


#endif // !DEBUG_H

