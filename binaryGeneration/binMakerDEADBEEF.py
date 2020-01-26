import sys
adres = (0, 2, 1, 3, 65535, 9, 65534)
newFile = open(sys.argv[1] + "file_data_in.bin", "wb")
for i in range(0,65536):
	if i == adres[int(sys.argv[2])]:
		newFile.write(bytearray.fromhex('DEADBEEF'))
	else:
		newFile.write(bytearray.fromhex('00000000'))
newFile.close()

newFile = open(sys.argv[1] + "file_reg_in.bin", "wb")
for i in range(0,31):
	newFile.write(bytearray.fromhex('00000000'))
newFile.close()

