data <- read.csv('titanic.csv')

print(data)

a <- data$Parch
hist(a, xlim = c(0,5), ylim = c(0,500), xlab = 'Number of parents and children of the passenger aboard')

print(summary(data))
data[is.na(data)] <- 27.00

x <- data$Survived
y <- data$Age

boxplot(x,y,labels = c('survived','died'))
axis(1, at = 1:2, labels = c('survived','died'))
