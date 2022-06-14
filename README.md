# Roach-Motel![Roach Main](https://user-images.githubusercontent.com/46026730/173674754-7c84a592-8c69-4b21-8bae-dd66eb7f1b00.jpg)

Zap roaches and other pests with high voltage.

This device generates a series of 600 volt pulses running on a 9 volt battery.  It features a large area of interleaved power and ground lines.  The pulses occur about every 4 seconds.

An ATtiny85 generates critically timed pulses that cause a 10 millihenry inductor to produce short (3 microsecond) high voltages spikes that are accumulated on a .02 microfarad capacitor.

The neon bulb is necessary to keep the battery voltage off of the grid array in between high voltage pulses.  This prevents insects from sensing the 9 volts and avoiding the device.

The Zip file contains a complete set of Gerber files.  Manufacuting was done by JLCPCB at a cost of about $2 per board.

