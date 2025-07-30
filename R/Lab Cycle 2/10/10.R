# Q10:  10. Suppose you have a dataset containing information about house prices 
# (dependent variable, denoted as price) and the size of the houses (in square feet, independent variable, denoted as size).
# You want to build a linear regression model to predict house prices based on their size.

# Write an R code snippet to perform the following steps:

# Load the dataset https://www.kaggle.com/competitions/house-prices-advanced-regression-techniques
# Fit a simple linear regression model with price as the dependent variable and size as the independent variable.
# Calculate the regression coefficients (slope and intercept).
# Plot the regression line along with the scatter plot of the data points.

data <- read.csv('houseprice.csv')

x <- data$LotArea
y <- data$SalePrice

Model <- lm(y~x,data)
plot(Model)

