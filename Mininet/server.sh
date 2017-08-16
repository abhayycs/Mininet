#!/bin/sh
cd iperf
iperf -sp 5002 -i 4 > tcp & iperf -sp 5003 -u -i 4 > udp & python -m SimpleHTTPServer 8080