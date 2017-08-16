# mininet
TCP_UDP behaviour analysis

In order to understand the behaviour of TCP and UDP. How the traffic affect, how the bandwidth utilization.
TCP is highly reliable protocol while UDP is fast transmission protocol (maximum throughput).
Here, we will see the behaviour of TCP and UDP by setting up the network topology, flow rules, and do iperf using mininet 
and then observe. The goal is to analyse the changes happen in bandwidth being allocated for TCP and UDP at each interval, 
while traffic is being sent to and from different hosts, and to analyse the behaviour of TCP and UDP, when they share same 
queue for data transmission and when they uses different queues for data transmission. 
Observe what happens when we stop UDP traffic, what changes occur in TCP flow.
