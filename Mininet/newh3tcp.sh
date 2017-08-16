#!/bin/sh
cat h3_tcp | grep sec | head -15 | tr - " " | awk '{print $4,$8}' > newh3tcp