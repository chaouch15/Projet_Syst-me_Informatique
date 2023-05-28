def read_file_py(): 
    file1 = open('cross.txt', 'r')
    Lines = file1.readlines()
    file2 = open('cross_bytes.txt', 'w')
    
    count = 0
    # Strips the newline character
    for line in Lines:
        count += 1
        
        instru = line.strip().replace("-1", "0").replace(" ", "")
        instru = int(instru)
        instru_bytes = instru.to_bytes(4, 'big')  # 4 bytes representation, using big endian

        file2.write(instru_bytes.hex() + '\n')


read_file_py()