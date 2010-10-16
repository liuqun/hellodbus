// gcc `pkg-config --cflags --libs dbus-1` emitter.c

//#include <stdlib.h>
#include <dbus/dbus.h>

int main()
{
	DBusError dberr;
	dbus_error_init(&dberr);
	dbus_error_free(&dberr);
	return (0);
}
