import serial.tools.list_ports

# 获取所有串口设备列表
ports_list = list(serial.tools.list_ports.comports())

if len(ports_list) <= 0:
    print("没发现串口设备，请检查 USB 是否插紧！")
else:
    print("发现以下串口设备：")
    for port in ports_list:
        # port.device 就是 COM号 (如 COM3)
        # port.description 是设备的详细描述 (如 USB-SERIAL CH340)
        print(f"端口号: {port.device} - 描述: {port.description}")