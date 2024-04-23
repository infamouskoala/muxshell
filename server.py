import socket
import threading

s = socket.socket()
ip = "192.168.56.1"  # Change this
port = 4545   # Change this
s.bind((ip, port))

s.listen()
cons = []

def clientcom(message):
    for client in cons:
        client.send(message.encode())
        x = client.recv(1024)
        print(f"{client} response: {x.decode()}")

def handle_connections():
    while True:
        con, addr = s.accept()
        print(f"\n {addr} joined")
        cons.append(con)

def send_messages():
    while True:
        message = input("Sending Text To Machines\n")
        clientcom(message)


conn_thread = threading.Thread(target=handle_connections)
send_thread = threading.Thread(target=send_messages)

conn_thread.start()
send_thread.start()

conn_thread.join()
send_thread.join()

# No closing the sockets baka >:(