import pandas as pd

def main():
    file = input()
    func = input()

    df = pd.read_csv(file)
    if func == 'Q1':
        print(df.shape)
    elif func == 'Q2':
        print(df['score'].max())
    elif func == 'Q3':
        print(df[df['score']>=80]['score'].count())
    else:
        print('No Output')

if __name__ == "__main__":
    main()