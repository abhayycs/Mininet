#!/bin/sh
sudo mn --topo=single,4 --link=tc,bw=1000 --controller=remote --mac
