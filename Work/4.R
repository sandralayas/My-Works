num1<-readline('Enter the first number :')
num2<-readline('Enter the second number : ')
num1<-as.integer(num1)
num2<-as.integer(num2)

swap<-num1
num1<-num2
num2<-swap

cat('First number :',num1,'\n')
cat('Second number :',num2,'\n')