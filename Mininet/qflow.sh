#!/bin/sh
sudo ovs-ofctl add-flow s1 priority=65535,ip,nw_dst=10.0.0.4,tcp,tp_dst=5002,actions=enqueue:4:1
sudo ovs-ofctl add-flow s1 priority=65535,ip,nw_dst=10.0.0.4,udp,tp_dst=5003,actions=enqueue:4:2
sudo ovs-ofctl add-flow s1 priority=1,dl_dst=00:00:00:00:00:04,actions=output:4
sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:01,actions=output:1
sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:02,actions=output:2
sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:03,actions=output:3
sudo ovs-ofctl add-flow s1 dl_dst=ff:ff:ff:ff:ff:ff,actions=flood