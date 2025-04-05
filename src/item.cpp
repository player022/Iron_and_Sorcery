#include "item.h"
#include "bn_keypad.h"

Item::Item(int x, int y) :
	_x(x), _y(y), _interactable(false)
{

}

// ͳһ�� update_position ����
void Item::update_position(int x, int y)
{
	int new_x = (_x - x) * 8;
	int new_y = (_y - y) * 8;

	// �������������¾���
	update_sprites(new_x, new_y);

	// ����Ƿ񿿽���Ʒ
	int dist_x = x - _x;
	int dist_y = y - _y;
	int abs_dist_x = abs(dist_x);
	int abs_dist_y = abs(dist_y);

	//���ȶȸ���
	if (abs_dist_x <= 15 && abs_dist_y <= 10) {
		update_priority(true);
	}
	else {
		update_priority(false);
	}

	// �������
	_interactable = (abs_dist_x <= 1 && abs_dist_y <= 1); // �ڽ�����Χ��

	auto occlusion = get_occlusion_range();
	if (!occlusion) return;  // û���ڵ���Χ�������м��

	auto[left, right, top, bottom] = *occlusion;

	bool inside = (dist_x >= left && dist_x <= right) && (dist_y >= top && dist_y <= bottom);

	on_occlusion(inside);
}