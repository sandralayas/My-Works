# Q7: EDA on "Iris Dataset"
# a)For the Iris dataset, which contains measurements of various iris flowers, conduct  an EDA.
# b) Determine if there are statistically significant differences in sepal lengths between different species using a suitable statistical test.
# c)Create a pair plot to visualize the relationships between all variables.

data <- read.csv('iris.csv')

print(data)

print(summary(data))
data[is.na(data)] <-5.800

x1 <- subset(data, data$species %in% c("Iris-setosa"))
x2 <- subset(data, data$species %in% c("Iris-versicolor"))
x3 <- subset(data, data$species %in% c("Iris-virginica"))

Iris_setosa <- x1$sepal_length
Iris_versicolor <- x2$sepal_length
Iris_virginica <- x3$sepal_length

new_data <- data.frame(Iris_setosa,Iris_versicolor,Iris_virginica)

pairs(new_data)
