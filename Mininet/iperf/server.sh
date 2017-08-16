#!/bin/sh
iperf -sp 5002 -i 0.5 > tcp & iperf -sp 5003 -u -i 0.5 > udp & python -m SimpleHTTPServer 8080