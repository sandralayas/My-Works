
data(mtcars)

str(mtcars)

# Perform Pearson correlation test
cor_test_result <- cor.test(mtcars$hp, mtcars$mpg, method = "pearson")
cat("\n--------PEARSON CORRELATION TEST--------","\n")
cat("Pearson correlation coefficient: ", cor_test_result$estimate, "\n")
cat("P-value: ", cor_test_result$p.value, "\n")


if (cor_test_result$p.value < 0.05) {
  cat("The correlation is statistically significant.\n")
} else {
  cat("There is no significant correlation.\n")
}
