import pandas as pd
from sklearn.model_selection import train_test_split

"""
    ASSIGNMENT 2 (STUDENT VERSION):
    Using pandas to explore Titanic data from Kaggle (titanic.csv) and answer the questions.
"""


def Q1(e):
    """
        Problem 1:
            How many rows are there in the “titanic.csv?
            Hint: In this function, you must load your data into memory before executing any operations. To access titanic.csv, use the path /data/titanic.csv.
    """
    # TODO: Code here
    df = pd.read_csv('/data/titanic.csv')
    return df.shape[0]


def Q2(df):
    '''
        Problem 2:
            Drop unqualified variables
            Drop variables with missing > 50%
            Drop categorical variables with flat values > 70% (variables with the same value in the same column)
            How many columns do we have left?
    '''
    # TODO: Code here
    df = df.drop(columns=df.columns[df.isnull().mean() > 0.5])
    flat_value = [col for col in df.select_dtypes(include='object').columns if df[col].value_counts(normalize=True).max() > 0.7]
    df = df.drop(columns=flat_value)
    return df.shape[1]


def Q3(df):
    '''
       Problem 3:
            Remove all rows with missing targets (the variable "Survived")
            How many rows do we have left?
    '''
    # TODO: Code here
    df=df.dropna(subset=['Survived'])
    return df.shape[0]
    return None


def Q4(df):
    '''
       Problem 4:
            Handle outliers
            For the variable “Fare”, replace outlier values with the boundary values
            If value < (Q1 - 1.5IQR), replace with (Q1 - 1.5IQR)
            If value > (Q3 + 1.5IQR), replace with (Q3 + 1.5IQR)
            What is the mean of “Fare” after replacing the outliers (round 2 decimal points)?
            Hint: Use function round(_, 2)
    '''
    # TODO: Code here
    fare_q1 = df['Fare'].quantile(0.25)
    fare_q3 = df['Fare'].quantile(0.75)
    fare_iqr = fare_q3 - fare_q1
    def fare_outlier(fare):
        if fare < (fare_q1 - 1.5*fare_iqr): return round(fare_q1 - 1.5*fare_iqr,2)
        elif fare > (fare_q3 + 1.5*fare_iqr): return round(fare_q3 + 1.5*fare_iqr,2)
        else : return fare
    df['Fare'] = df['Fare'].apply(fare_outlier)
    return round(df['Fare'].mean(),2)


def Q5(df):
    '''
       Problem 5:
            Impute missing value
            For number type column, impute missing values with mean
            What is the average (mean) of “Age” after imputing the missing values (round 2 decimal points)?
            Hint: Use function round(_, 2)
    '''
    # TODO: Code here
    for col in df.columns:
        if(df[col].dtype == 'object' ):
            df[col] = df[col].fillna(df[col].mode()[0])
        else:
            df[col] = df[col].fillna(df[col].mean())
            
    return round(df['Age'].mean(),2)


def Q6(df):
    '''
        Problem 6:
            Convert categorical to numeric values
            For the variable “Embarked”, perform the dummy coding.
            What is the average (mean) of “Embarked_Q” after performing dummy coding (round 2 decimal points)?
            Hint: Use function round(_, 2)
    '''
    # TODO: Code here
    df = pd.get_dummies(data=df,columns=['Embarked'],drop_first=True)
    return round(df['Embarked_Q'].mean(),2)


def Q7(df):
    '''
        Problem 7:
            Split train/test split with stratification using 70%:30% and random seed with 123
            Show a proportion between survived (1) and died (0) in all data sets (total data, train, test)
            What is the proportion of survivors (survived = 1) in the training data (round 2 decimal points)?
            Hint: Use function round(_, 2), and train_test_split() from sklearn.model_selection
    '''
    # TODO: Code here
    y = df.pop('Survived')
    X = df

    X_train, X_test, y_train, y_test = train_test_split(X,y,stratify=y,test_size=0.3,random_state=123)
    return round(y_train.value_counts()[1]/y_train.shape[0],2)

