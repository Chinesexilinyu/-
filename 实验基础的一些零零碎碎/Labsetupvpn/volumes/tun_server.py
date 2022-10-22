#!/usr/bin/env python3

import fcntl
import struct
import os
import time
from scapy.all import*
import select
import socket
import ssl
import pprint

TUNSETIFF = 0x400454ca
IFF_TUN   = 0x0001
IFF_TAP   = 0x0002
IFF_NO_PI = 0x1000

html = """
HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n
<!DOCTYPE html><html><body><h1>This is Bank32.com!</h1></body></html>
"""

SERVER_CERT = './server-certs/server.crt'
SERVER_PRIVATE = './server-certs/server.key'

# Create the tun interface
tun = os.open("/dev/net/tun", os.O_RDWR)
ifr = struct.pack('16sH', b'zcy%d', IFF_TUN | IFF_NO_PI)
ifname_bytes  = fcntl.ioctl(tun, TUNSETIFF, ifr)

# Get the interface name
ifname = ifname_bytes.decode('UTF-8')[:16].strip("\x00")
os.system("ip addr add 192.168.53.11/24 dev {}".format(ifname))
os.system("ip link set dev {} up".format(ifname))
print("Interface Name: {}".format(ifname))

#IP_A = "0.0.0.0"
#PORT = 9090
#sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
#sock.bind((IP_A,PORT))
#while True:
 #   ready,_,_ = select.select([sock,tun],[],[])
  #  for fd in ready:
   #     if fd is sock:
    #        data,(ip,port) = sock.recvfrom(2048)
     #       print("{}:{} --> {}:{}".format(ip,port,IP_A,PORT))
      #      pkt = IP(data)
            #print(" Inside: {} --> {}".format(pkt.src,pkt.dst))
       #     os.write(tun,bytes(pkt))
       # if fd is tun:
        #    packet = os.read(tun,2048)
         #   pkt = IP(packet)
          #  print("Return {} -> {}".format(pkt.src,pkt.dst))
           # sock.sendto(packet,(ip,port))

context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)  # For Ubuntu 20.04 VM
# context = ssl.SSLContext(ssl.PROTOCOL_TLSv1_2)      # For Ubuntu 16.04 VM
context.load_cert_chain(SERVER_CERT, SERVER_PRIVATE)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
sock.bind(('0.0.0.0', 443))
sock.listen(5)

#IP_A = "0.0.0.0"
#PORT = 9090
#sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
#sock.bind((IP_A,PORT))
#fds = [sock,tun]

while True:
    newsock, fromaddr = sock.accept()
    try:
        ssock = context.wrap_socket(newsock, server_side=True)
        print("TLS connection established")
        data = ssock.recv(1024)              # Read data over TLS
        pprint.pprint("Request: {}".format(data))
        ssock.sendall(html.encode('utf-8'))  # Send data over TLS
       # ready,_,_ = select.select([sock,tun],[],[])
       # for fd in ready:
        #    if fd is sock:
         #       data,(ip,port) = sock.recvfrom(2048)
          #      print("{}:{} --> {}:{}".format(ip,port,IP_A,PORT))
           #     pkt = IP(data)
                    #print(" Inside: {} --> {}".format(pkt.src,pkt.dst))
            #    os.write(tun,bytes(pkt))
           # if fd is tun:
            #    packet = os.read(tun,2048)
             #   pkt = IP(packet)
              #  print("Return {} -> {}".format(pkt.src,pkt.dst))
               # sock.sendto(packet,(ip,port))

        ssock.shutdown(socket.SHUT_RDWR)     # Close the TLS connection
        ssock.close()

    except Exception:
        print("TLS connection fails")
        continue
