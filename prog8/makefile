all: first 

first: 
	javac *.java

s:
	java udp_copy_server 6789 

c:
	java udp_copy_client localhost 6788 ciliablue1920.jpg 

p:
	java udp_proxy	6788 localhost 6789 .05

clean:
	rm *.class
