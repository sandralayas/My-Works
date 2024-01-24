# Hold out Method

def load_csv(filepath):
    data =  []
    col = []
    checkcol = False
    with open(filepath) as f:
        for val in f.readlines():
            val = val.replace("\n","")
            val = val.split(',')
            if checkcol is False:
                col = val
                checkcol = True
            else:
                data.append(val)
    df = pd.DataFrame(data=data, columns=col)
    return df

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

# Assuming 'X' is your feature matrix and 'y' is your target variable
# Replace this with your actual data
# For example, X, y = load_your_data_function()

# Generate a fictional dataset for illustration
import numpy as np
np.random.seed(42)
X = np.random.rand(100, 5)  # 100 samples, 5 features
y = (X[:, 0] + X[:, 1] + X[:, 2] > 1.5).astype(int)  # Binary classification

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a logistic regression model
model = LogisticRegression()

# Train the model on the training set
model.fit(X_train, y_train)

# Make predictions on the test set
y_pred = model.predict(X_test)

# Evaluate the model's performance using accuracy
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy on the test set: {accuracy:.2f}")


# Leave p-out Method

def load_csv(filepath):
    data =  []
    col = []
    checkcol = False
    with open(filepath) as f:
        for val in f.readlines():
            val = val.replace("\n","")
            val = val.split(',')
            if checkcol is False:
                col = val
                checkcol = True
            else:
                data.append(val)
    df = pd.DataFrame(data=data, columns=col)
    return df

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

# Assuming 'X' is your feature matrix and 'y' is your target variable
# Replace this with your actual data
# For example, X, y = load_your_data_function()

# Generate a fictional dataset for illustration
import numpy as np
np.random.seed(42)
X = np.random.rand(100, 5)  # 100 samples, 5 features
y = (X[:, 0] + X[:, 1] + X[:, 2] > 1.5).astype(int)  # Binary classification

# Choose the proportion of data for testing (e.g., p = 0.2 for 20% testing)
p = 0.2

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=p, random_state=42)

# Create a logistic regression model
model = LogisticRegression()

# Train the model on the training set
model.fit(X_train, y_train)

# Make predictions on the test set
y_pred = model.predict(X_test)

# Evaluate the model's performance using accuracy
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy on the test set: {accuracy:.2f}")


# Leave 1-out Method

def load_csv(filepath):
    data =  []
    col = []
    checkcol = False
    with open(filepath) as f:
        for val in f.readlines():
            val = val.replace("\n","")
            val = val.split(',')
            if checkcol is False:
                col = val
                checkcol = True
            else:
                data.append(val)
    df = pd.DataFrame(data=data, columns=col)
    return df

from sklearn.model_selection import LeaveOneOut
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

# Assuming 'X' is your feature matrix and 'y' is your target variable
# Replace this with your actual data
# For example, X, y = load_your_data_function()

# Generate a fictional dataset for illustration
import numpy as np
np.random.seed(42)
X = np.random.rand(100, 5)  # 100 samples, 5 features
y = (X[:, 0] + X[:, 1] + X[:, 2] > 1.5).astype(int)  # Binary classification

# Create a leave-one-out cross-validator
loo = LeaveOneOut()

# Create a logistic regression model
model = LogisticRegression()

# Initialize variables to store predictions and true labels
y_true = []
y_pred = []

# Perform leave-one-out cross-validation
for train_index, test_index in loo.split(X):
    X_train, X_test = X[train_index], X[test_index]
    y_train, y_test = y[train_index], y[test_index]

    # Train the model on the training set
    model.fit(X_train, y_train)

    # Make predictions on the test set
    y_pred.append(model.predict(X_test)[0])
    y_true.append(y_test[0])

# Evaluate the model's performance using accuracy
accuracy = accuracy_score(y_true, y_pred)
print(f"Accuracy using leave-one-out: {accuracy:.2f}")


# KFold Method

from sklearn import datasets
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import KFold, cross_val_score

X, y = datasets.load_iris(return_X_y=True)

clf = DecisionTreeClassifier(random_state=42)

k_folds = KFold(n_splits = 5)

scores = cross_val_score(clf, X, y, cv = k_folds)

print("Cross Validation Scores: ", scores)
print("Average CV Score: ", scores.mean())
print("Number of CV Scores used in Average: ", len(scores))
