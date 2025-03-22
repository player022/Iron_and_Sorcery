#include "item.h"

Item::Item(int x, int y, int columns, int rows) :
	_x(columns - x), _y(rows - y)
{

}

// ͳһ�� update_position ����
bool Item::update_position(int x, int y)
{
	int new_x = (_x + x) * 8;
	int new_y = (_y + y) * 8;

	// �������������¾���
	update_sprites(new_x, new_y);

	// ����Ƿ񿿽���Ʒ
	int dist_x = abs(-_x - x);
	int dist_y = abs(-_y - y);
	return (dist_x <= 1 && dist_y <= 1);
}