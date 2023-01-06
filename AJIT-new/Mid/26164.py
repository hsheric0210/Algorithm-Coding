if __name__=="__main__":
  x,y=map(int,input().split())
  y-=x
  pig=[0 for i in range(y+1)]
  n=int(input())
  for i in range(n):
    p,w=map(int,input().split())
    if pig[w]==0 or p<pig[w]:
      pig[w]=p
    for j in range(w+1,y+1):
      if pig[j-w]==0:
        continue
      elif pig[j-w]+p<pig[j] or pig[j]==0:
        pig[j]=pig[j-w]+p
  if pig[y]==0:
    print('-1')
  else:
    print(pig[y])