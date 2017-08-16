#!/bin/sh
sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:01,action=output:1
sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:02,action=output:2
sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:03,action=output:3
sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:04,action=output:4
sudo ovs-ofctl add-flow s1 dl_dst=ff:ff:ff:ff:ff:ff,action=flood
sudo ovs-ofctl dump-flows s1
