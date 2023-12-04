# Q3: Create a box plot of the horsepower (hp) in the mtcars dataset. 
# Use different shapes to represent the number of gears (gear). Add appropriate title, 
# labels, and legend to the plot. Identify and label any outliers on the plot.

# Load the ggplot2 library
library(ggplot2)

# Create a box plot of 'horsepower' with different shapes for 'gear'
ggplot(mtcars, aes(x = factor(gear), y = hp, shape = factor(gear))) +
  geom_boxplot(outlier.colour = "red", outlier.shape = 16) +
  labs(
    title = "Box Plot of Horsepower by Number of Gears",
    x = "Number of Gears",
    y = "Horsepower (hp)"
  ) +
  scale_shape_manual(values = c(1, 2, 3)) +
  theme_minimal() +
  guides(shape = guide_legend(title = "Number of Gears"))  # Add legend title

