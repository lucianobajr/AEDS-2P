import random
t=int(input())
arq=open("%d.txt"%t,"w")
valor=[random.randint(0,50)for i in range(t)]
arq.write("%d\n"%t)
for i in range(t):
    arq.write("%d \n"%(valor[i]))
arq.close()