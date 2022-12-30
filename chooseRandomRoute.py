import random
#input file
fin = open("v2Run.sumo.cfg", "rt")
#output file to write the result to
fout = open("v3Run.sumo.cfg", "wt")
randomNum = random.randint(1,20)
#for each line in the input file
for line in fin:
	#read replace the string and write to output file
	
	replaceValue = "cross.rou.xml"
	replaceToValue = "cross_"+str(randomNum) +".rou.xml"
	fout.write(line.replace(replaceValue,replaceToValue ))
#close input and output files
fin.close()
fout.close()


#input file
fin = open("vs2.launchd.xml", "rt")
#output file to write the result to
fout = open("vs3.launchd.xml", "wt")
#randomNum = random.randint(1,20)
#for each line in the input file
for line in fin:
	#read replace the string and write to output file
	
	replaceValue1 = "cross.rou.xml"
	replaceToValue1 = "cross_"+str(randomNum) +".rou.xml"
	fout.write(line.replace(replaceValue1,replaceToValue1 ))
#close input and output files
fin.close()
fout.close()


