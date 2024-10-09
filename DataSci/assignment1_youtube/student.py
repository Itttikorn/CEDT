import pandas as pd
import json

"""
    ASSIGNMENT 1 (STUDENT VERSION):
    Using pandas to explore youtube trending data from GB (GBvideos.csv and GB_category_id.json) and answer the questions.
"""

def Q1():
    """
        1. How many rows are there in the GBvideos.csv after removing duplications?
        - To access 'GBvideos.csv', use the path '/data/GBvideos.csv'.
    """
    # TODO: Paste your code here
    vdo_df = pd.read_csv('/data/GBvideos.csv')
    vdo_df.drop_duplicates(inplace=True)
    return vdo_df.shape[0]

def Q2(vdo_df):
    '''
        2. How many VDO that have "dislikes" more than "likes"? Make sure that you count only unique title!
            - GBvideos.csv has been loaded into memory and is ready to be utilized as vdo_df
            - The duplicate rows of vdo_df have been removed.
    '''
    # TODO: Paste your code here
    return vdo_df[vdo_df['dislikes']>vdo_df['likes']].title.nunique()

def Q3(vdo_df):
    '''
        3. How many VDO that are trending on 22 Jan 2018 with comments more than 10,000 comments?
            - GBvideos.csv has been loaded into memory and is ready to be utilized as vdo_df
            - The duplicate rows of vdo_df have been removed.
            - The trending date of vdo_df is represented as 'YY.DD.MM'. For example, January 22, 2018, is represented as '18.22.01'.
    '''
    # TODO: Paste your code here
    return vdo_df[(vdo_df['trending_date'] == "18.22.01") & (vdo_df['comment_count'] > 10000)].video_id.nunique()

def Q4(vdo_df):
    '''
        4. Which trending date that has the minimum average number of comments per VDO?
            - GBvideos.csv has been loaded into memory and is ready to be utilized as vdo_df
            - The duplicate rows of vdo_df have been removed.
    '''
    # TODO:  Paste your code here
    return vdo_df.groupby('trending_date')['comment_count'].mean().idxmin()

def Q5(vdo_df):
    '''
        5. Compare "Sports" and "Comedy", how many days that there are more total daily views of VDO in "Sports" category than in "Comedy" category?
            - GBvideos.csv has been loaded into memory and is ready to be utilized as vdo_df
            - The duplicate rows of vdo_df have been removed.
            - You must load the additional data from 'GB_category_id.json' into memory before executing any operations.
            - To access 'GB_category_id.json', use the path '/data/GB_category_id.json'.
    '''
    # TODO:  Paste your code here
    category_json = json.load(open('/data/GB_category_id.json'))
    category_list = []
    for items in category_json['items']:
        category_list.append((int(items['id']),items['snippet']['title']))
    category_df = pd.DataFrame(category_list,columns=['id','category'])
    vdo_df = vdo_df.merge(category_df, left_on='category_id', right_on='id')
    sport = vdo_df[vdo_df['category'] == 'Sports'].groupby('trending_date')['views'].sum().reset_index(name="sport_views")
    comedy = vdo_df[vdo_df['category'] == 'Comedy'].groupby('trending_date')['views'].sum().reset_index(name="comedy_views")
    compare = sport.merge(comedy, on='trending_date', how='inner')
    compare['check'] = compare['sport_views'] > compare['comedy_views']
    return compare['check'].sum()