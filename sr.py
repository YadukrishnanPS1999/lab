prod = {"E+E":"E","E-E":"E","E*E":"E","E/E":"E"}

stack = []
stTop = -1
flag = 0
stack.append('$')
stTop+=1
inPut = input("Enter the input") 
leninpE = len(inPut)
leninpS = 0
print("Stack \t\t Input \t\t Action")
for i in inPut:
  leninpS+=1
  inpStr = ""
  for tk in range(leninpS,leninpE):
    inpStr = inpStr+inPut[tk]
  if(stack[stTop]=="E" and i == '$'):
    print("Accepted")
    flag = 1
    exit(0)
  if(i == 'a'):
    stack.append(i)
    stTop+=1
    temst = ""
    for st in stack:
      temst = temst+st
    print(temst+" \t\t"+inpStr+" \t\t"+"a shifted")
    
    stack[stTop] = "E"
    temst1 =""
    for st in stack:
      temst1 = temst1+st
    print(temst1+" \t\t"+inpStr+" \t\t"+"a reduced with E")
    temp = ""
    stTop1 = stTop
    while(stack[stTop1] != '$'):
      temp=temp+stack[stTop1]
      stTop1-=1
    for k in prod.keys():
      if(temp == k):
        for p in range(stTop,0,-1):
          stack.pop()
          stTop-=1
        stack.append(prod[k])
        stTop+=1
        temst2 = ""
        for st in stack:
          temst2 = temst2+st
        print(temst2+" \t\t"+inpStr+" \t\t"+k+" reduced by "+prod[k])

  else:
    stack.append(i)
    stTop+=1
    temst3 = ""
    for st in stack:
      temst3 = temst3 + st
    print(temst3 +" \t\t "+ inpStr +" \t\t"+i+" Shifted")
print(stack)
if(flag == 0):
  print("Rejected")



    