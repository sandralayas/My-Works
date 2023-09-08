age  <- readline('Enter your age : ')
age  <- as.numeric(age)

if(age<18){
  cat('You are',age,'and a minor')
}else{
  cat('You are',age,'and not a minor')
}