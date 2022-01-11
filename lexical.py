data = {"int":"keyword","void":"keyword","(":"character",")":"character","+":"operator","-":"operator","=":"operator","*":"operator","/":"operator","a":"Identifier","b":"Identifier","c":"Identifier","d":"Identifier","1":"Number","2":"Number","3":"Number","4":"Number","5":"Number","6":"Number","7":"Number","8":"Number","9":"Number"}
f = open("code.txt")
a=0
resultKey = []
resID = []
resNum = []
resChar = []
for line in f:
    for k in data.keys():
        str = line.split() 
        for word in str:
            if(word == k):
                str = word + " is a " + data[k]
                flag = 0
                for test in resultKey:
                    if(test == str):
                        flag = 1
                if(flag == 0):
                    resultKey.append(str)
                    break
for i in resultKey:
    print(i)
             

