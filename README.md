# Kidney Disease Classification

This project implements various machine learning models to classify kidney disease based on a dataset. The dataset contains various features related to kidney health, and the goal is to predict whether a patient has chronic kidney disease (CKD) or not.

## Table of Contents
- [Dataset](#dataset)
- [Technologies Used](#technologies-used)
- [Data Preprocessing](#data-preprocessing)
- [Models Implemented](#models-implemented)
- [Model Evaluation](#model-evaluation)
- [Visualization](#visualization)
- [Usage](#usage)

## Dataset
The dataset used in this project is `kidney_disease.csv`, which contains various features related to kidney health. The target variable is `classification`, indicating whether a patient has CKD or not.

## Technologies Used
- Python
- Pandas
- NumPy
- Seaborn
- Matplotlib
- Scikit-learn

## Data Preprocessing
1. **Loading Data**: The dataset is loaded using Pandas.
2. **Handling Missing Values**: Missing values in categorical features are filled with the mode, while numerical features are filled with the mean.
3. **Encoding Categorical Features**: Categorical features are encoded into numerical values using `LabelEncoder`.
4. **Feature Scaling**: Numerical features are scaled using `StandardScaler` for better convergence in logistic regression.

## Models Implemented
1. **Random Forest Classifier**: A Random Forest model is trained and evaluated.
2. **Naive Bayes Classifier**: A custom implementation of the Naive Bayes algorithm is created and evaluated.
3. **Logistic Regression**: A logistic regression model is implemented using gradient descent.

## Model Evaluation
Each model's performance is evaluated using metrics such as:
- Accuracy
- Precision
- Recall
- F1-Score

The metrics for each model are saved to separate text files:
- `random_forest_metrics.txt`
- `naive_bayes_metrics.txt`
- `logistic_regression_metrics.txt`

## Visualization
- Kernel Density Estimation (KDE) plots are generated to visualize the distribution of numerical features with respect to the classification.
- A bar plot is created to compare the performance metrics of all models.

## Usage
1. Ensure you have the required libraries installed. You can install them using:
   ```bash
   pip install pandas numpy seaborn matplotlib scikit-learn
   ```
2. Place the `kidney_disease.csv` file in the same directory as the notebook.
3. Run the Jupyter Notebook to execute the code and visualize the results.

## Conclusion
This project demonstrates the application of machine learning techniques to classify kidney disease, showcasing data preprocessing, model training, evaluation, and visualization.
