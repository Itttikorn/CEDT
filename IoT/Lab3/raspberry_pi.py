import serial
import time


baudrate = 115200
ser = serial.Serial('/dev/ttyAMA0', baudrate, timeout=1)

def send_command(cmd):
    try:
        ser.write(cmd.encode() + b'\n') # ส่งคำสั่งพร้อมขึ้นบรรทัดใหม่
        print(f"ส่งคำสั่ง: {cmd}")
        time.sleep(0.5) # รอให้ ESP32 ประมวลผล
        while ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            print(f"รับข้อมูล: {line}")
    except serial.SerialException as e:
        print(f"ข้อผิดพลาดในการเชื่อมต่อ: {e}")

if __name__ == "__main__":
    time.sleep(2) # รอการเชื่อมต่อ

    print(f"baudrate: {baudrate}")
    
    # ทดสอบส่งคำสั่ง "status"
    send_command("increment")
    
    # ทดสอบส่งคำสั่ง "blink"
    send_command("increment")
    
    send_command("status")

    send_command("decrement")
    
    ser.close()
    print("ปิดการเชื่อมต่อ Serial")
