import rarfile
import glob
import os
passwords = ("23333333","123","2333","hahahah")
rarfiles = glob.glob(".//*.rar")
for rar in rarfiles:
	path = os.path.split(rar)[1].split(".")[0]
	f = rarfile.RarFile(rar)
	for password in passwords:
		try:
			f.extractall(path,None,password)
		except:
			continue
		break
