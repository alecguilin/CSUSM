from socket import *
import uuid
import re
serverName = '192.168.1.53'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
OFFER = "OFFER"
ACKNOWLEDGE = "ACKNOWLEDGE"
REQUEST = "REQUEST"
RELEASE = "RELEASE"
RENEW = "RENEW"
QUIT = "QUIT"
DISCOVER = "DISCOVER"

def displayMenu(ipRecieved) :
	#DISPLAY MENU
	while 1 :
		print("\n----IP CONFIG MENU----")
		print("(1) Release")
		print("(2) Renew")
		print("(3) Quit\n")
		selection = input("Please Select: ")
		if selection ==  '1':
			print("Client: Sending RELEASE msg to server...")
			print("Server: Recieves RELEASE msg to server...")
			print("Server: Attempting to release IP...")
			#sending RELEASE msg
			clientSocket.sendto(RELEASE.encode(), (serverName, serverPort))
			#payload
			clientSocket.sendto(macAddr.encode(), (serverName, serverPort))
			clientSocket.sendto(ipRecieved, (serverName, serverPort))
			msgType, serverAddress = clientSocket.recvfrom(2048)
			if msgType.decode() == "SUCCESS" :
				print("Server: IP successfully released back into pool.")
				print("Client: Sucessfully released IP.")
				continue
			elif msgType.decode()  == "FAIL" :
				print("Server: IP release failed, not in list of current clients.")
				print("Client: Failed, IP already released.")
				continue

		elif selection == '2' :
			print("Client: Sending RENEW msg to server...")
			print("Server: Recieves RENEW msg...")
			print("Server: Attempting to rewnew IP...")
			#sending RENEW msg
			clientSocket.sendto(RENEW.encode(), (serverName, serverPort))
			#payload
			clientSocket.sendto(macAddr.encode(), (serverName, serverPort))
			msgType, serverAddress = clientSocket.recvfrom(2048)
			if msgType.decode() == "FAIL" :
				print("Server: IP already assigned.")
				print("Client: IP is already assigned, IP is", ipRecieved.decode())
			elif msgType.decode() == "SUCCESS" :
				print("Server: Assigning new IP...")
				#recieves offer request
				print("Server: Sending OFFER msg...")
				print("Client: Recieves OFFER msg from server...")
				msgType, serverAddress = clientSocket.recvfrom(2048)
				macAddrRecieved, serverAddress = clientSocket.recvfrom(2048)
				ipRecieved, serverAddress = clientSocket.recvfrom(2048)

				print("Client: Sends REQUEST msg to server...")
				print("Server: Recieves REQUEST msg...")
				clientSocket.sendto(REQUEST.encode(),(serverName, serverPort))
				#payload
				clientSocket.sendto(macAddr.encode(),(serverName, serverPort))
				clientSocket.sendto(ipRecieved,(serverName, serverPort))
				print("Server: Sending ACKNOWLEDGE msg...")
				print("Client: Recieves ACKNOWLEDGE msg...")
				#recieves ack message
				ack, serverAddress = clientSocket.recvfrom(2048)
				macAddrRecieved, serverAddress = clientSocket.recvfrom(2048)
				ipRecieved, serverAddress = clientSocket.recvfrom(2048)
				print("Client: IP Obtained: ", ipRecieved.decode())


		elif selection == '3' :
			clientSocket.sendto(QUIT.encode(),(serverName, serverPort))
			print("Quitting...")
			break

		else :
			print("\n***Invalid Option***\nPlease try again...")

#stores extracted mac address into macAddr
macAddr = ':'.join(re.findall('..', '%012x' % uuid.getnode()))

print('Client: DISCOVER msg is being sent...')
clientSocket.sendto(DISCOVER.encode(),(serverName, serverPort))
print('Client: Current MAC address', macAddr, 'is being sent...')
clientSocket.sendto(macAddr.encode(),(serverName, serverPort))
print("Server: Recieved DISCOVER msg...")
print("Server: Recieved MAC address...")
print("Server: Checking if MAC Address has already been assigned...")
msgType, serverAddress = clientSocket.recvfrom(2048)
if msgType.decode() == OFFER :
	print("Server: Checking if any IP's are available...")
	print("Server: IP available, sending OFFER msg...")
	print("Client: OFFER msg recieved...")
	macAddrRecieved, serverAddress = clientSocket.recvfrom(2048)
	ipRecieved, serverAddress = clientSocket.recvfrom(2048)
	print("Client: Server offered IP ", ipRecieved.decode())
	if macAddrRecieved.decode() == macAddr :
		#msg type
		print("Client: REQUEST msg is being sent...")
		clientSocket.sendto(REQUEST.encode(),(serverName, serverPort))
		#payload
		clientSocket.sendto(macAddr.encode(),(serverName, serverPort))
		clientSocket.sendto(ipRecieved,(serverName, serverPort))
		print("Server: Recieved REQUEST msg...")
		print("Server: Checking if IP is still available...")
		print("Server: Storing MAC address ", macAddr)
		#recieve ack msg
		print("Client: ACKNOWLEDGE msg recieved...")
		ack, serverAddress = clientSocket.recvfrom(2048)
		macAddrRecieved, serverAddress = clientSocket.recvfrom(2048)
		ipRecieved, serverAddress = clientSocket.recvfrom(2048)
		#check is mac addr is mine, if it is, display the newly obtained IP
		if macAddrRecieved.decode() == macAddr :
			print("Client: IP Obtained:" , ipRecieved.decode())
			displayMenu(ipRecieved)


		else :
			print("mac address is invalid, terminating program")
			#terminate program
else : 
	ipRecieved, serverAddress = clientSocket.recvfrom(2048)
	print("Server: MAC address has already been assigned")
	print("Client: This machine has already been assigned an IP:", ipRecieved.decode())
	displayMenu(ipRecieved)

clientSocket.close()
