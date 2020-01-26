import sys
newFile = open(sys.argv[1] + "file_data_in.bin", "ab")
for i in range(0,65534):
	newFile.write(bytearray.fromhex('00000000'))
newFile.close()

newFile = open(sys.argv[1] + "file_reg_in.bin", "wb")
for i in range(0,34): 
	newFile.write(bytearray.fromhex('00000000'))
newFile.close()

