# Print square of a number

square<-function(n){
  n<-as.integer(n)
  cat('The square of',n,'is',n*n)
}
n<-readline('Enter the number : ')
square(n)

# Accept your name and find the length

length<-function(name){
  cat('The length of',name,'is',nchar(name))
}
name<-readline('Enter your name : ')
length(name)

# Accept a vector

sum_min_max<-function(v){
  cat('sum :',sum(v),'\nmax :',max(v),'\nmin',min(v))
}
size<-readline('Enter the size of vector : ')
size<-as.integer(size)

print('Enter the vector')
n<-readline()
n<-as.integer(n)
v<-c(n)
for(i in 2:size){
  n<-readline()
  n<-as.integer(n)
  v<-c(v,n)
}
cat('The vector is :',v,'\n')
sum_min_max(v)

# Data Validation and User Input

size<-readline('Enter the number of students : ')
size<-as.integer(size)

print('Enter the details of student 1')
name<-readline('Enter the name : ')
age<-readline('Enter the age : ')
age<-as.integer(age)
grade<-readline('Enter the grade : ')
student<-c(name,age,grade)
details<-matrix(student,ncol=3,byrow=TRUE)
if(size>1){
  for(i in 2:size){
    cat('Enter the details of student',i,'\n')
    name<-readline('Enter the name : ')
    repeat{
      age<-readline('Enter the age : ')
      age<-as.integer(age)
      if(age<1){
        cat(age,'is not a vaild age\n')
      }else{break}
    }
    repeat{
      grade<-readline('Enter the grade : ')
      if(grade %in% c('a','b','c','d','f','A','B','C','D','F')){
        break
      }else{
        cat(grade,'is not a vaild grade\n')
      }
    }
    student<-c(name,age,grade)
    details<-rbind(details,student)
  }
}
colnames(details)<-c('Name   ','Age   ','Grade')
rownames(details)<-c()
print(details)