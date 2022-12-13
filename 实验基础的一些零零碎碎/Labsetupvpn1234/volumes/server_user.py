#!/usr/bin/env python3
#coding = utf-8

import fcntl
import struct
import os
import time
import datetime
import paramiko
import threading
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
<!DOCTYPE html><html><body><h1>This is zcy2022.com!</h1></body></html>
"""

SERVER_CERT = './server-certs/server.crt'
SERVER_PRIVATE = './server-certs/server.key'
#Create Linux
class Linux(object):
    def _init_(self,ip,username,password,port=443,timeout=30):
        self.ip = ip
        self.port = port
        self.uesrname = username
        self.timeout = timeout
        self.t = ""
        self.chan = ""
        self.try_times = 3
    def create_sshclient(self,myusername,mypasswd):
        sshclient = paramiko.SSHClient()
        sshclient.load_system_host_keys()
        sshclient.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        while True:
            try:
                sshclient.connect(hostname=self.ip,port=self.port,username=myusername,password=mypasswd)
                return sshclient
        expect Exception:
            if self.try_times != 0:
                print('The connectinon is false,please try again!')
                self.try_times -= 1
            else:
                print('Three times over!')
                exit(1)
    def close(self):
        if self.chan:
            self.chan.close()
        if self.t:
            self.t.close()
    def exec_cmd(self,mysshclient,cmd):
        return mysshclient.exec_command(cmd)

    def create_user(self,mysshclient,new_username,new_passwd,salt='any_str_here'):
        cmd = 'useradd -= 'openssl passwd -1 -salt \""+salt+'\"'+new_passwd+'`'+new_username
        self.exec_cmd(mysshclient,cmd)

    def sftp_get(self,remotefile,localfile):
        self.t=paramiko.Transport(sock=(self.ip,self.port))
        self.t.connect(username=self.username,password=self.password)
        sftp=paramiko.SFTPClient.from_transport(self.t)
        sftp.get(remotefile,localfile)
        self.t.close()

    def sftp_put(self,localfile,remotefile):
        self.t=paramiko.Transport(sock=(self.ip,self.port))
        self.t.connect(username=self.username,password=self.password)
        sftp=paramiko.SFTPClient.from_transport(self.t)
        sftp.put(localfile,remotefile)
        self.t.close()

    def winpath2linuxpath(winpath):
        return winpath.replace('\\','/')

    def linuxpath2winpath(linuxpath):
        return linuxpath.replace('/','\\')

    def isdir(sftp,filename):
        try:
            sftp.listdir(filename)
            return True
        except Exception:
            return False

class
# Create the tun interface
tun = os.open("/dev/net/tun", os.O_RDWR)
ifr = struct.pack('16sH', b'zcy%d', IFF_TUN | IFF_NO_PI)
ifname_bytes  = fcntl.ioctl(tun, TUNSETIFF, ifr)

# Get the interface name
ifname = ifname_bytes.decode('UTF-8')[:16].strip("\x00")
os.system("ip addr add 192.168.53.11/24 dev {}".format(ifname))
os.system("ip link set dev {} up".format(ifname))
print("Interface Name: {}".format(ifname))

context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)  # For Ubuntu 20.04 VM
# context = ssl.SSLContext(ssl.PROTOCOL_TLSv1_2)      # For Ubuntu 16.04 VM
context.load_cert_chain(SERVER_CERT, SERVER_PRIVATE)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
sock.bind(('0.0.0.0', 443))
sock.listen(5)


while True:
    newsock, fromaddr = sock.accept()
    try:
        ssock = context.wrap_socket(newsock, server_side=True)
        print("TLS connection established")
        data = ssock.recv(1024)              # Read data over TLS
        pprint.pprint("Request: {}".format(data))
        ssock.sendall(html.encode('utf-8'))  # Send data over TLS
        ssock.shutdown(socket.SHUT_RDWR)     # Close the TLS connection
        ssock.close()

    except Exception:
        print("TLS connection fails")
        continue
