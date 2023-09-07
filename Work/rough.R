repeat{
  a<-readline('Enter the first number : ')
  b<-readline('Enter the second number : ')
  a<-as.integer(a)
  b<-as.integer(b)
  
  if(a==0 & b==0){
    break
  }else if(a>b){
    print(paste(a,'is greater than',b))
  }else if(b>a){
    print(paste(b,'is greater than',a))
  }else if(a==b){
    print(paste(a,'is equal to',b))
  }
}
  
switch(a,1,2,3,4,5)

for(i in 1:5){
  print(i)
}