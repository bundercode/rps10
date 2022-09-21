import time
import serial

ser = serial.Serial('/dev/ttyS0', 9600, serial.EIGHTBITS, serial.PARITY_NONE, timeout=1)
ser.close()

time.sleep(1)
ser.open()
time.sleep(1)

#ser.write("\x02\x18\x18\x02\x18\x18*T\r")
ser.write([2,24,24,2,24,24,42,84,13])
try:
    while 1:
        response = ser.readline()
        print(response)
except KeyboardInterrupt:
    ser.close()
