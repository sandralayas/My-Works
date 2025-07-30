# Load the mtcars dataset
data(mtcars)

# Set up the null and alternative hypotheses
H0 <- "There is no significant difference in the average displacement for different gear types."
HA <- "There is a significant difference in the average displacement for different gear types."

# Perform the one-way ANOVA test
aov_disp_gear <- aov(disp ~ gear, data = mtcars)

# View the results of the test
summary(aov_disp_gear)
