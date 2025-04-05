#ifndef ITEMOBSERVER_H
#define ITEMOBSERVER_H

class Item;  // ǰ������ Item ��

class ItemObserver
{
public:
	virtual ~ItemObserver() = default;

	//���ţ�����������չ����״̬�仯
	virtual void on_door_state_changed(int x, int y, bool is_open) = 0;  // ���麯��

	// ��Ʒ��ʰȡ
	virtual void on_item_picked_up(const Item& item) = 0;
};


#endif // !ITEMOBSERVER_H