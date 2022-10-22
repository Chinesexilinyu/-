#!/usr/bin/env python3

import fcntl
import struct
import os
import time
import socket
import ssl
import sys
import pprint
from scapy.all import*
import select

TUNSETIFF = 0x400454ca
IFF_TUN   = 0x0001
IFF_TAP   = 0x0002
IFF_NO_PI = 0x1000

# Create the tun interface
tun = os.open("/dev/net/tun", os.O_RDWR)
ifr = struct.pack('16sH', b'zcy%d', IFF_TUN | IFF_NO_PI)
ifname_bytes  = fcntl.ioctl(tun, TUNSETIFF, ifr)

hostname = sys.argv[1]
port = 443
#cadir = '/etc/ssl/certs'
cadir = './client-certs'

# Get the interface name
ifname = ifname_bytes.decode('UTF-8')[:16].strip("\x00")
os.system("ip addr add 192.168.53.99/24 dev {}".format(ifname))
os.system("ip link set dev {} up".format(ifname))
print("Interface Name: {}".format(ifname))

#Create UDP socket
#sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
#SERVER_IP = "10.9.0.11"
#SERVER_PORT = 9090
#fds = [sock,tun]
#while True:
 #   ready,_,_ = select.select([sock,tun],[],[])
  #  for fd in ready:
   #     if fd is sock:
    #        data,(ip,port) = sock.recvfrom(2048)
     #       pkt = IP(data)
      #      print("From socket: {} --> {}".format(pkt.src,pkt.dst))
       #     os.write(tun,data)
       # if fd is tun:
        #    packet = os.read(tun,2048)
         #   if packet:
          #      pkt = IP(packet)
           #     print(pkt.summary())
            #    sock.sendto(packet,(SERVER_IP, SERVER_PORT))
      # os.write(tun,bytes("Hello"))
     #time.sleep(10)
# Set up the TLS context
context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)  # For Ubuntu 20.04 VM
#context = ssl.SSLContext(ssl.PROTOCOL_TLSv1_2)      # For Ubuntu 16.04 VM

context.load_verify_locations(capath=cadir)
context.verify_mode = ssl.CERT_REQUIRED
context.check_hostname = False

# Create TCP connection
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((hostname, port))
input("After making TCP connection. Press any key to continue ...")

# Add the TLS
ssock = context.wrap_socket(sock, server_hostname=hostname,
                            do_handshake_on_connect=False)
ssock.do_handshake()   # Start the handshake
print("=== Cipher used: {}".format(ssock.cipher()))
print("=== Server hostname: {}".format(ssock.server_hostname))
print("=== Server certificate:")
pprint.pprint(ssock.getpeercert())
pprint.pprint(context.get_ca_certs())
input("After TLS handshake. Press any key to continue ...")
# Send HTTP Request to Server  
request = b"GET / HTTP/1.0\r\nHost: " + \
        hostname.encode('utf-8') + b"\r\n\r\n"  
ssock.sendall(request)

# Read HTTP Response from Server  
response = ssock.recv(2048)
while response:
    pprint.pprint(response.split(b"\r\n"))
    response = ssock.recv(2048)

#Create UDP socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
SERVER_IP = "10.9.0.11"
SERVER_PORT = 9090
fds = [sock,tun]
while True:
    ready,_,_ = select.select([sock,tun],[],[])
    for fd in ready:
        if fd is sock:
            data,(ip,port) = sock.recvfrom(2048)
            pkt = IP(data)
            print("From socket: {} --> {}".format(pkt.src,pkt.dst))
            os.write(tun,data)
        if fd is tun:
            packet = os.read(tun,2048)
            if packet:
                pkt = IP(packet)
                print(pkt.summary())
                sock.sendto(packet,(SERVER_IP, SERVER_PORT))
      # os.write(tun,bytes("Hello"))
     #time.sleep(10)

# Close the TLS Connection
ssock.shutdown(socket.SHUT_RDWR)
ssock.close()
