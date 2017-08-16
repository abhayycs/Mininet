#!/bin/sh
iperf -c 10.0.0.4 -p 5002 -i 10 -t 120 > h3tcp & iperf -c 10.0.0.4 -u -p 5003 -i 10 -t 80 -b 512M > h3udp