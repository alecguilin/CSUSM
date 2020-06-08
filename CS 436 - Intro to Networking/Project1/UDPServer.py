from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
OFFER = "OFFER";
ACKNOWLEDGE = "ACKNOWLEDGE"
SUCCESS = "SUCCESS"
FAIL = "FAIL"
i = 0
#creates an empty list (2D array) for mac addresses and their IP's
mac_list = [[]]


#function for creating an ip pool
def ipPool(start_ip, end_ip):
   start = list(map(int, start_ip.split(".")))
   end = list(map(int, end_ip.split(".")))
   temp = start
   ip_range = []
   
   ip_range.append(start_ip)
   while temp != end:
      start[3] += 1
      for i in (3, 2, 1):
         if temp[i] == 256:
            temp[i] = 0
            temp[i-1] += 1
      ip_range.append(".".join(map(str, temp)))    
      
   return ip_range

def menu() :
	while 1 :
		msgType, clientAddress = serverSocket.recvfrom(2048)
		if msgType.decode() == "RELEASE" :
			#print("Server: Releasing IP...")
			macAddrRecieved, clientAddress = serverSocket.recvfrom(2048)
			ipRecieved, clientAddress = serverSocket.recvfrom(2048)

			if macAddr.decode() in mac_list :
				ip_pool.append(ipRecieved.decode())
				mac_list.pop()
				#send success message
				serverSocket.sendto(SUCCESS.encode(), clientAddress)
				#print("Server: IP successfully released back into pool.")

			else :
				#error send fail message
				serverSocket.sendto(FAIL.encode(), clientAddress)
				#$print("Server: IP release failed, not in list of current clients.")
		elif msgType.decode() == "RENEW" :
			#print("Server: Renewing IP...")
			macAddrRecieved, clientAddress = serverSocket.recvfrom(2048)
			if macAddrRecieved.decode() in mac_list :
				serverSocket.sendto(FAIL.encode(), clientAddress)
				#print("Server: IP already assigned.")
				#send message back saying IP is already assigned, it is x.x.x.x
			else : 
				serverSocket.sendto(SUCCESS.encode(), clientAddress)

				#send offer msg
				serverSocket.sendto(OFFER.encode(), clientAddress)
				#payload
				serverSocket.sendto(macAddr, clientAddress)
				serverSocket.sendto(ip_pool.pop().encode(), clientAddress)

				msgType, clientAddress = serverSocket.recvfrom(2048)
				if msgType.decode() == "REQUEST" :
					#print("Server: Recieved REQUEST msg...")
					macAddrRecieved, clientAddress = serverSocket.recvfrom(2048)
					ipRecieved, clientAddress = serverSocket.recvfrom(2048)

					#sends ACKNOWLEDGE msg
					serverSocket.sendto(ACKNOWLEDGE.encode(), clientAddress)
					#payload
					serverSocket.sendto(macAddr, clientAddress)
					serverSocket.sendto(ipRecieved, clientAddress)

					#store in current clients
					mac_list.append(macAddr.decode())
		else :
			break

print("Creating IP pool...")
#creates a pool of IP's
ip_pool = ipPool("192.168.1.1", "192.168.1.254")
ip_pool.reverse()
print("IP pool created")
print ('The server is ready to receive')


while 1:

	#recieving mac address from client(DISCOVER msg)
	msgType, clientAddress = serverSocket.recvfrom(2048)
	#print("Server: Recieved DISCOVER msg...")
	macAddr, clientAddress = serverSocket.recvfrom(2048)
	#print("Server: Recieved MAC address...")

	#print("Server: Checking if MAC Address has already been assigned...")
	#checks if mac adress is already in list
	if macAddr.decode() in mac_list :
		#print("Server: MAC address has already been assigned")
		serverSocket.sendto(FAIL.encode(), clientAddress)
		#display menu
		serverSocket.sendto(mac_list[i][i].encode(), clientAddress)
		#send IP!!!!
		menu()
	else :
		#print("Server: Checking if any IP's are available...")
		#check if ip pool is available
		if ip_pool :
			#print("Server: IP available, sending OFFER msg...")
			#sends OFFER msg
			serverSocket.sendto(OFFER.encode(), clientAddress)
			#payload
			serverSocket.sendto(macAddr, clientAddress)
			serverSocket.sendto(ip_pool.pop().encode(), clientAddress)

			#print("Server: Recieved REQUEST msg...")
			#recieves REQUEST msg
			msgType, clientAddress = serverSocket.recvfrom(2048)
			#payload
			macAddrRecieved, clientAddress = serverSocket.recvfrom(2048)
			ipRecieved, clientAddress = serverSocket.recvfrom(2048)

			#print("Server: Checking if IP is still available...")
			#if ip is still avail
			if ipRecieved.decode() not in ip_pool :

				#print("Server: Storing MAC address ", macAddr.decode())
				#store in current clients
				mac_list.append(macAddr.decode())
				mac_list[i].append(ipRecieved.decode())

				#sends ACKNOWLEDGE msg
				serverSocket.sendto(ACKNOWLEDGE.encode(), clientAddress)
				#payload
				serverSocket.sendto(macAddr, clientAddress)
				serverSocket.sendto(ipRecieved, clientAddress)

				#at this point, client is looking at menu
				menu()

			else :
				print("Assign new IP")
				#assign new ip
				#then send ack msg, mac addr, ip

		else :
			print('DECLINED')