#!/usr/bin/env python

def my_func(message):
    print "somebody said:", message, "\n"

import dbus, gobject
from dbus.mainloop.glib import DBusGMainLoop
dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
bus = dbus.SessionBus()

bus.add_signal_receiver(my_func,
                        dbus_interface="com.xldz.test",
                        signal_name="TestSignal")

loop = gobject.MainLoop()
loop.run()
