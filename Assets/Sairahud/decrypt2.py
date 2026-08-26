with open("hint.o", "rb") as f:
    raw = f.read()

print("--- กำลังสแกนหาข้อความที่ถูกต้อง ---")
for offset in range(len(raw) - 28):
    buf = bytearray(raw[offset:offset + 28])
    
    # Stage 1: XOR 18 ไบต์แรกด้วย 0xaa
    for i in range(18):
        buf[i] ^= 0xaa
        
    # Stage 2: XOR ไบต์ที่ 18..27 ด้วย buf[0..9]
    for i in range(10):
        buf[i + 18] ^= buf[i]
        
    # เช็คว่าผลลัพธ์เป็นตัวอักษร ASCII ที่อ่านออกหรือไม่
    s = buf.decode('latin1')
    if all(32 <= ord(c) < 127 for c in s[:18]):
        print(f"เจอข้อมูลที่ File Offset: {hex(offset)}")
        print(f"Result (18 chars): {s[:18]}")
        print(f"Full Buffer:       {s}")
        print("-" * 35)
