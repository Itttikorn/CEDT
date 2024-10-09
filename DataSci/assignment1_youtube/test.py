import pandas as pd
import json
vdo_df = pd.read_csv('data/USvideos.csv')
vdo_df.drop_duplicates(inplace=True)
print(int(vdo_df.shape[0]))
print(int(vdo_df[vdo_df['dislikes']>vdo_df['likes']].video_id.nunique()))
print(int(vdo_df[(vdo_df['trending_date'] == "18.22.01") & (vdo_df['comment_count'] > 10000)].video_id.nunique()))
print(str(vdo_df.groupby('trending_date')['comment_count'].mean().idxmin()))

category_json = json.load(open('data/US_category_id.json'))
category_list = []
for items in category_json['items']:
    category_list.append((int(items['id']),items['snippet']['title']))
category_df = pd.DataFrame(category_list,columns=['id','category'])
vdo_df = vdo_df.merge(category_df, left_on='category_id', right_on='id')
sport = vdo_df[vdo_df['category'] == 'Sports'].groupby('trending_date')['views'].sum().reset_index(name="sport_views")
comedy = vdo_df[vdo_df['category'] == 'Comedy'].groupby('trending_date')['views'].sum().reset_index(name="comedy_views")
compare = sport.merge(comedy, on='trending_date', how='inner')
compare['check'] = compare['sport_views'] > compare['comedy_views']
print(int(compare['check'].sum()))

#print(df[df['dislikes']>df['likes']].video_id.nunique())
#print(df[(df['trending_date'] == "18.22.01") & (df['comment_count'] > 10000)].video_id.nunique())
#print(df.groupby('trending_date')['comment_count'].mean().idxmin())
# category_json = json.load(open('data/US_category_id.json'))
# categories_id = {}
# for items in category_json['items']:
#     if(items['snippet']['assignable'] == True):
#         categories_id[items['snippet']['title']] = items['id']
# sport = df[df['category_id'] == int(categories_id['Sports'])].groupby('trending_date')['views'].sum().reset_index(name="sport_views")
# comedy = df[df['category_id'] == int(categories_id['Comedy'])].groupby('trending_date')['views'].sum().reset_index(name="comedy_views")
# compare = sport.merge(comedy, on='trending_date', how='inner')
# compare['check'] = compare['sport_views'] > compare['comedy_views']
# print(compare['check'].sum())

#print(len(comedy))
#print(categories_id)

