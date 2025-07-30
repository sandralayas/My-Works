# Q4: Create a scatter plot of the displacement (disp) versus the weight (wt) in the mtcars dataset.
# Use different colors and sizes to represent the number of carburetors (carb).
# Add appropriate title, labels, and legend to the plot. Add a smooth line to show the trend of the relationship.

data <- read.csv('mtcars.csv')

x <- data$disp
y <- data$wt

plot(x,y,main = 'MTCARS DATASET', xlab = 'displacement', ylab = 'weight')
model <- lm(y~x)
plot(model)
