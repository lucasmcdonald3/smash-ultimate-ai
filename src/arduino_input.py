import serial

serial_char = {
    'start': 's',
    'dup' : 'u',
    'ddown' : 'd',
    'dright' : 't',
    'dleft' : 'k',
    'xAxis' : 'j',
    'yAxis' : 'i',
    'cxAxis' : 'c',
    'cyAxis' : 'v'
}

class ArduinoSerialCommunicator:
    def __init__(self):
        self.s = serial.Serial(port='/dev/tty.usbmodem14201', baudrate=9600)

    def send_change(self, button):
        if button not in serial_char:
            self.s.write(button)
        else:
            self.s.write(serial_char[button])

    def send_joystick(self, stick_name, value):
        if stick_name not in serial_char:
            self.s.write(stick_name)
        else:
            self.s.write(serial_char[stick_name])
        self.s.write(value)

    def read(self):
        return self.s.read(100)