#!/bin/sh
iperf -c 10.0.0.4 -p 5002 -t 120 > h1tcp & iperf -c 10.0.0.4 -u -p 5003 -t 80 -b 512M > h1udp