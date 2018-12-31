import arduino_input
import sys

serial = arduino_input.ArduinoSerialCommunicator()

while True:
    c = sys.stdin.read(1)
    serial.send_change(bytes(c, 'utf8'))
    print(serial.read())