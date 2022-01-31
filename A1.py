# Create HashTable
HashTable = [[] for _ in range(10)]
 # Display records 
def display_hash(hashTable):
	
	for i in range(len(hashTable)):
		print(i, end = " ")
		
		for j in hashTable[i]:
			if j !={}:
			    print("-->", end = " ")
			    print(j, end = " ")
			
		print()
 # Hash function    
def Hashing(key):
    hashsum = 0
    # For each character in the key
    for idx, c in enumerate(key):
        # Add (index + length of key) ^ (current char code)
        hashsum += (idx + len(key)) ** ord(c)
        hashsum = hashsum % len(HashTable)
    return hashsum

def find(Hashtable,keyvalue):
    hash_key = Hashing(keyvalue)
    key=Hashtable[hash_key]
    if key==[[],[]]:
        return []
    while key[0][0]!=keyvalue:
        hash_key =(hash_key+1)%len(HashTable)
        key=Hashtable[hash_key]
    return key
        
        
def insert(Hashtable, keyvalue, value):
	l=[keyvalue,value]
	hash_key = Hashing(keyvalue)
	key=hash_key
	while Hashtable[hash_key] !=[]:
	    hash_key =(hash_key+1)%len(HashTable)
	if Hashtable[hash_key] ==[]:
	    Hashtable[hash_key].append(l)
	    
def delete(Hashtable, keyvalue):
    hash_key = Hashing(keyvalue)
    key=Hashtable[hash_key]
    while key[0][0]!=keyvalue:
        hash_key =(hash_key+1)%len(HashTable)
        key=Hashtable[hash_key]
    Hashtable[hash_key]=[[],[]]
    return key
        
        
def main():
    n = int(input("Enter the number of clients : "))
    for i in range(n):
        data_name = input("Enter the name : ")
        data_tele = int(input("Enter the telephone number : "))
        #insert 
        insert(HashTable,data_name,data_tele)
    #users choice
    while(True):
        choice = int(input("Enter 1:Insert 2: Search 3: Delete "))
        if (choice==1):
            data_name = input("Enter the name : ");
            data_tele = int(input("Enter the telephone number : "));
            insert(HashTable,data_name,data_tele)
        elif (choice==2):
            data_name = input("Enter the name : ");
            key=find(HashTable,data_name)
            print("Value Retrived :", key)
        elif (choice==3):
            data_name = input("Enter the name : ");
            print("Value removed :",delete(HashTable,data_name))
        else:
            print("Invalid Choice")
        c=input("Do you want to continue:Y/N")
        if(c=='N'):
            break
if __name__ == "__main__":
    main()
