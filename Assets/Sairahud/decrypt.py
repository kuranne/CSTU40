with open("hint.o", "rb") as f:
    data = f.read()

# ตำแหน่งของ symbol 'msg' อยู่ที่ offset 0x80
# ดึงข้อมูลออกมาอย่างน้อย 28 ไบต์ (18 + 10)
msg = bytearray(data[0x80:0x80 + 28])

# Stage 1: XOR 18 ไบต์แรกด้วย 0xaa
for i in range(18):
    msg[i] ^= 0xaa

# Stage 2: XOR ไบต์ที่ 18..27 ด้วย msg[0..9]
for i in range(10):
    msg[i + 18] ^= msg[i]

# แสดงผลลัพธ์ 18 ไบต์แรกตามที่ syscall write สั่งพิมพ์
print("Stage 1 Output (Printed):", msg[:18].decode('utf-8', errors='replace'))
print("Full Decoded Buffer:", msg.decode('utf-8', errors='replace'))
