# Function to validate age as a positive integer
validate_age <- function(age) {
  if (!is.numeric(age) || age < 0 || !is.integer(age)) {
    cat("Invalid age. Please enter a positive integer for age.\n")
    return(FALSE)
  }
  return(TRUE)
}

# Function to validate grade as a valid letter grade (A, B, C, D, F)
validate_grade <- function(grade) {
  valid_grades <- c("A", "B", "C", "D", "F")
  if (!is.character(grade) || !grade %in% valid_grades) {
    cat("Invalid grade. Please enter a valid letter grade (A, B, C, D, F).\n")
    return(FALSE)
  }
  return(TRUE)
}

# Function to read and validate student records
read_student_records <- function(num_students) {
  student_records <- list()  # Initialize an empty list
  
  for (i in 1:num_students) {
    cat("\nEnter details for Student", i, ":\n")
    
    name <- readline("Enter student name: ")
    
    age_input <- readline("Enter student age: ")
    age <- as.integer(age_input)
    
    if (!validate_age(age)) {
      i <- i - 1
      next
    }
    
    grade <- readline("Enter student grade: ")
    
    if (!validate_grade(grade)) {
      i <- i - 1
      next
    }
    
    student <- list(name = name, age = age, grade = grade)
    student_records[[i]] <- student  # Store the student record in the list
  }
  return(student_records)
}

# Main program
num_students <- as.integer(readline("Enter the number of students: "))

if (is.na(num_students) || num_students <= 0) {
  cat("Invalid input. Please enter a positive integer for the number of students.\n")
} else {
  cat("\nEnter student records for", num_students, "students:\n")
  student_records <- read_student_records(num_students)
  
  cat("\nStudent Records:\n")
  for (i in 1:num_students) {
    student <- student_records[[i]]
    cat("Student", i, ":\n")
    cat("Name:", student$name, "\n")
    cat("Age:", student$age, "\n")
    cat("Grade:", student$grade, "\n\n")
  }
}
