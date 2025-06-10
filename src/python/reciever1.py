import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque

# === Configuration ===
SERIAL_PORT = 'COM3'  
BAUD_RATE = 115200      
BUFFER_SIZE = 3000     


ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)


x_data = deque(maxlen=BUFFER_SIZE)
y_data = deque(maxlen=BUFFER_SIZE)
z_data = deque(maxlen=BUFFER_SIZE)
t_data = deque(maxlen=BUFFER_SIZE)

fig, ax = plt.subplots()
line_x, = ax.plot([], [], label='X')
line_y, = ax.plot([], [], label='Y')
line_z, = ax.plot([], [], label='Z')
ax.set_ylim(-160, 160) 
ax.set_xlim(0, BUFFER_SIZE)
ax.set_title("Real-time Accelerometer Data")
ax.set_xlabel("Sample")
ax.set_ylabel("Acceleration")
ax.legend(loc="upper right")


def update(frame):
    print("here")
    try:
        line = ser.readline().decode('utf-8').strip()
        print(line)
        parts = line.split()
        if len(parts) == 3:
            x, y, z = map(float, parts)
            x_data.append(x)
            y_data.append(y)
            z_data.append(z)
            t_data.append(len(t_data))

            line_x.set_data(range(len(x_data)), x_data)
            line_y.set_data(range(len(y_data)), y_data)
            line_z.set_data(range(len(z_data)), z_data)
    except Exception as e:
        print("Read error:", e)

    return line_x, line_y, line_z

ani = animation.FuncAnimation(fig, update, interval=30)
plt.tight_layout()
plt.show()
