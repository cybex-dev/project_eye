// Paranoid protocol uses a paranoid implementation of sending and receiving data. It assumes that data can always be manipulated, or changed by cause of an attack. Thus, all data is checked client & server side as far as possible
// Thus data sent from the client is always checked, stored and confirmed

Installation requirement:
	generate public & private key to use for communication. (Save this in settings directory)

Protocol Requirement:
	AES Encryption (256) provided by crypto++
	
	
NOTE:
	// data between server and client never send plain variables which can be manipulated. 
	i.e. Client: Are the credentials valid, Server: true/false
	
	Since these values can be manipulated, the server should respond with crucial information which cannot be manually created. 
	i.e. Client identifies itself, server responds with: public key if valid or an "INVALID" if not valid
			if id is unique: public key for encryption
			if not unique: 
	
Paranoid Conversation/Procedure(activates when client desires to login):
	1. 	C: Client greeting (identify client software id with randomly generated hash*)
		S: Server responds by sending a list of vpn ip
	
	*  see client documentation, a 16 char (128 bit) string generated with characters [a-zA-Z-9_+]

1. Client sends greeting when alive with public key: Either 
	"Hello, Stranger"  - Server stores public key as new client in database
	or 
	"I am XYZ" 	- ID is checked in database, if it exists, then the username can be confirmed. If a new user logs in, this client id is stored with the user login, can be used to determine who uses the same client
				- If no ID is found, most probably means a hack or attack may be occuring, since data loss in the database is less likely than someone faking an ID.

		Protocol has default public/private key (can be changed in program args). This is used to encrypt/decrypt initial data conversation (ID Greeting)

2. Client sends login details & public key, Check public key exists
	- If key exists, confirm same key as stored in database. 
			- If same, confirm login details
			- If not the same, store new ID with login details
	- If ID not exist
			- Confirm login details

	(Use AES Encrypting\Decryoting within paranoid protocol.)
	- Store ID with login username and time of login, ip, etc.
	- Generate server & client communication keys, send server's public key to client
	- Client generates 

3. 