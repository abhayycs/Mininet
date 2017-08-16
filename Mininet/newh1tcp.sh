#!/bin/sh
cat tcp | grep sec | head -60 | tr - " " | awk '{print $4,$8}' > newtcp