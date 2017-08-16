*************************************MiniNet**************************************

terminal1>
	sudo mn --topo=single,4 --link=tc,bw=1000 --controller=remote --mac
terminal2>
	sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:01,action=output:1
	sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:02,action=output:2
	sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:03,action=output:3
	sudo ovs-ofctl add-flow s1 dl_dst=00:00:00:00:00:04,action=output:4
	sudo ovs-ofctl add-flow s1 dl_dst=ff:ff:ff:ff:ff:ff,action=flood
	sudo ovs-ofctl dump-flows s1
	watch -n.5 "sudo ovs-ofctl dump-flows s1"

	****install gnuplot****
	sudo apt-get install gnuplot-nox
	sudo apt-get install gnuplot-x11
	***********************
	//currnetly no use
	tcpdump -Xnnc 20 -w capture.txt /* to capture the tcp flow -n: no ip resolution
	-nn: no ip and port resolution -c: no of packets -w: <file_name> */

	gnuplot
	gnuplot>
		plot "new_h1_tcp_result" title "h1 tcp flow" with linespoints
		set xrange [1:15]
		set xtics 1,1,15
		set yrange [0:1000]	//or [900:1000] or [ymin:ymax]
		set ytics 0,2,1000
		replot

		//currently of no use
		set terminal <terminal_type>		//set terminal command is optional to display

terminal1/mini>
		net
		xterm h1 h2 h3 h4	//tcp
		xterm h1 h2 h3 h4	//udp
		xterm h4	//3
	h4>	//tcp
		iperf -s 
	h4>	//udp
		iperf -s -u
	h4>	//http
		cd <folder_name> //packet here resides. take minsize(10MB)
		python -m SimpleHTTPServer 8080
	h1>	//tcp
		iperf -c 10.0.0.4 -i 1 -t 25 > h1_tcp_result
		cat h1_tcp_result | grep sec | head -15 | tr - " " | awk '{print $4,$8}' > new_h1_tcp_result
	h1> //udp
		iperf -c 10.0.0.4 -u -i 1 -t 20 -b 512M > h1_upd_result
		cat h1_udp_result | grep sec | head -15 | tr - " " | awk '{print $4,$8}' > new_h1_udp_result
	h2>	//http
		wget -r 10.0.0.4:8080
	h3>	//tcp
		iperf -c 10.0.0.4 -i 1 -t 25 > h3_tcp_result
		cat h3_tcp_result | grep sec | head -15 | tr - " " | awk '{print $4,$8}' > new_h3_tcp_result
	h3> //udp
		iperf -c 10.0.0.4 -u -i 1 -t 20 -b 512M > h3_upd_result
		cat h3_udp_result | grep sec | head -15 | tr - " " | awk '{print $4,$8}' > new_h3_udp_result
//
sudo ovs-vsctl -- set port s1-eth4 qos=@defaultqos -- --id=@defaultqos create qos type=linux-htb other-config:max-rate=100000000 queues:0=@q0 -- --id=@q0 create queue other-config:min-rate=100000000 other-config:max-rate=100000000
//