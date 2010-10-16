// gcc -g `pkg-config --cflags --libs dbus-1` emitter.c
// gdb a.out

#include <assert.h>
#include <stdio.h>
#include <dbus/dbus.h>

void send_message_through_connection(const char msg[], DBusConnection *pdbconn)
{
	assert(msg != NULL);
	assert(pdbconn != NULL);
	DBusMessage *pdbmsg;
	const char **pp = &msg;

	pdbmsg = dbus_message_new_signal("/com/xldz/test","com.xldz.test","TestSignal");
	if (pdbmsg == NULL)
	{
		fprintf(stderr, "%s:%d:%s()\n", __FILE__, __LINE__, __func__);
		return;
	}
	dbus_message_append_args(pdbmsg, DBUS_TYPE_STRING, pp, DBUS_TYPE_INVALID);
	dbus_connection_send(pdbconn, pdbmsg, NULL);
	dbus_message_unref(pdbmsg);
}

void send_message(const char msg[], DBusBusType session, DBusError *pdberr)
{
	assert(pdberr != NULL);
	DBusConnection *pdbconn;

	pdbconn = dbus_bus_get(session, pdberr);
	if (dbus_error_is_set(pdberr))
	{
		fprintf(stderr, "%s:%d:%s()\n", __FILE__, __LINE__, __func__);
		return;
	}
	send_message_through_connection(msg, pdbconn);
	dbus_connection_unref(pdbconn);
	return;
}

int main()
{
	const char msg[] = "Hello there! This is liuqun speeking...\n";
	DBusError dberr;
	dbus_error_init(&dberr);
	send_message(msg, DBUS_BUS_SESSION, &dberr);
	dbus_error_free(&dberr);
	return (0);
}
