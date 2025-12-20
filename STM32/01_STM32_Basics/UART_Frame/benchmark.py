import serial
import struct
import time

PORT = 'COM5'     # 修改为你的串口号
BAUD = 115200     # 与 MCU 一致
FRAME_SIZE = 11   # 2 + 4 + 2 + 2 + 1
HEADER = 0xAAAA

def calculate_checksum(data_bytes):
    xor_sum = 0
    for b in data_bytes:
        xor_sum ^= b
    return xor_sum

def sync_and_read_frame(ser):
    """简单的帧同步：找 0xAA 0xAA，然后读剩余字节"""
    while True:
        b1 = ser.read(1)
        if not b1:
            continue
        if b1[0] != 0xAA:
            continue
        b2 = ser.read(1)
        if not b2:
            continue
        if b2[0] != 0xAA:
            # 如果第二个不是 0xAA，就把第二个当成第一个继续
            b1 = b2
            continue
        # 头对齐后，读取剩余帧
        rest = ser.read(FRAME_SIZE - 2)
        if len(rest) == FRAME_SIZE - 2:
            return b'\xAA\xAA' + rest

def main():
    ser = serial.Serial(PORT, BAUD, timeout=1)
    print(f"Listening on {PORT} @ {BAUD}...")

    stats = {
        'total_bytes': 0,
        'valid_frames': 0,
        'crc_errors': 0,
        'header_errors': 0,
        'lost_packets': 0,
        'last_seq': -1
    }

    start_time = time.time()

    try:
        while True:
            raw_data = sync_and_read_frame(ser)
            if raw_data is None:
                continue

            stats['total_bytes'] += FRAME_SIZE

            try:
                # < = 小端; H=uint16, I=uint32, h=int16, h=int16, B=uint8
                header, seq, val1, val2, checksum = struct.unpack('<HIhhB', raw_data)
            except struct.error:
                continue

            calc_sum = calculate_checksum(raw_data[:-1])
            if calc_sum != checksum:
                stats['crc_errors'] += 1
                print(f"CRC Error! Seq: {seq}")
                continue

            if header != HEADER:
                stats['header_errors'] += 1
                continue

            if stats['last_seq'] != -1:
                diff = seq - stats['last_seq']
                if diff != 1:
                    lost = diff - 1
                    stats['lost_packets'] += lost
            stats['last_seq'] = seq
            stats['valid_frames'] += 1

            if stats['valid_frames'] % 1000 == 0:
                elapsed = time.time() - start_time
                fps = stats['valid_frames'] / elapsed
                print(f"\rFPS: {fps:.1f} | Total: {stats['valid_frames']} | "
                      f"Lost: {stats['lost_packets']} | CRC Err: {stats['crc_errors']}", end="")

    except KeyboardInterrupt:
        print("\n\n=== Final Report ===")
        print(f"Duration: {time.time() - start_time:.2f} s")
        print(f"Valid Frames: {stats['valid_frames']}")
        print(f"Packet Loss: {stats['lost_packets']}")
        print(f"CRC Errors: {stats['crc_errors']}")
        ser.close()

if __name__ == '__main__':
    main()