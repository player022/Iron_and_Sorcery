#ifndef DOOROBSERVER_H
#define DOOROBSERVER_H

class DoorObserver
{
public:
	virtual void on_door_state_changed(int x, int y, bool is_open) = 0;  // ´¿Ðéº¯Êý
	virtual ~DoorObserver() = default;
};


#endif // !DOOROBSERVER_H