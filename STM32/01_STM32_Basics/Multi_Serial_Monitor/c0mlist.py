import serial.tools.list_ports

# 获取所有串口设备列表
ports_list = list(serial.tools.list_ports.comports())

if len(ports_list) <= 0:
    print("No serial port device found. Please check if the USB is plugged in tightly!")
else:
    print("The following serial port devices are found:")
    for port in ports_list:
        print(f"Port number:{port.device} - Description:{port.description}")