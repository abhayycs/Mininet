#!/bin/sh
sudo ovs-vsctl -- set port s1-eth4 qos=@defaultqos -- --id=@defaultqos create qos type=linux-htb other-config:max-rate=100000000 queues:0=@q0 -- --id=@q0 create queue other-config:min-rate=100000000 other-config:max-rate=100000000
