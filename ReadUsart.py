！python3
import serial

ser = serial.Serial(
    port='COM4',
    baudrate=115200,
    parity=serial.PARITY_NONE,  # 校验位
    stopbits=serial.STOPBITS_ONE,  # 停止位
    bytesize=serial.EIGHTBITS  # 数据位
)



while 1:
    a=input('输入编号:')
    if a=='':
        break
    else:
        path='D:\desktop\杂项\校赛\data\\real\\'+str(a)+'.txt'  #a can be 1-5
        print(path)
        data = ''
        Count=0

    with open(path, 'a') as file:
        file.truncate(0)


    while True:
        data = ser.readline()
        print(data)

        f = open(path, 'a')
        f.writelines(str(data))
        f.writelines('\n')


        Count=Count+1
        if Count==10:
            f.writelines('\n')
            f.close()
            break
