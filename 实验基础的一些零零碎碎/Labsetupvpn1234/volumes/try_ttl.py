#!/usr/bin/env python3
from scapy.all import*

for i in range(1,30):
    a=IP()
    a.det='202.108.2.5'
    a.ttl=i
    b=ICMP()
    p=a/b
    send(p)
