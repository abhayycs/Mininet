#!/bin/sh
cat h1_udp | grep sec | head -10 | tr - " " | awk '{print $4,$8}' > newh1udp