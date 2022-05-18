import pandas as pd

ad_clicks = pd.read_csv('ad_clicks.csv')

#print(ad_clicks.head(10))

utm_source_table = ad_clicks.groupby('utm_source').user_id.count().reset_index()
print(utm_source_table)

ad_clicks['is_click'] = ~ad_clicks.ad_click_timestamp.isnull()

clicks_by_source = ad_clicks.groupby(['utm_source', 'is_click']).user_id.count().reset_index()

clicks_pivot = clicks_by_source.pivot(
  columns='is_click',
  index='utm_source',
  values='user_id').reset_index()
clicks_pivot['percent_clicked'] = clicks_pivot[True] / (clicks_pivot[True] + clicks_pivot[False])

ab_views = ad_clicks.groupby('experimental_group').user_id.count().reset_index()

a_or_b_click = ad_clicks.groupby(['experimental_group', 'is_click']).user_id.count().reset_index()

a_or_b_click_pivot = a_or_b_click.pivot(
  columns='is_click',
  index='experimental_group',
  values='user_id'
).reset_index()

a_clicks = ad_clicks[ad_clicks.experimental_group == 'A']
b_clicks = ad_clicks[ad_clicks.experimental_group == 'B']

a_clicks_by_day = a_clicks.groupby(['is_click','day']).user_id.count().reset_index()

a_clicks_by_day_pivot = a_clicks_by_day.pivot(
  columns='is_click',
  index='day',
  values='user_id'
).reset_index()

a_clicks_by_day_pivot['percent_clicked'] = a_clicks_by_day_pivot[True] / (a_clicks_by_day_pivot[True] + a_clicks_by_day_pivot[False])

b_clicks_by_day = b_clicks.groupby(['is_click','day']).user_id.count().reset_index()

b_clicks_by_day_pivot = b_clicks_by_day.pivot(
  columns='is_click',
  index='day',
  values='user_id'
).reset_index()

b_clicks_by_day_pivot['percent_clicked'] = b_clicks_by_day_pivot[True] / (b_clicks_by_day_pivot[True] + b_clicks_by_day_pivot[False])

print(ad_clicks.head(10))
#print(a_clicks.head(10))
#print(a_clicks_by_day)
print(a_clicks_by_day_pivot)
#print(b_clicks.head(10))
print(b_clicks_by_day_pivot)
print(ab_views)
print(a_or_b_click_pivot)
#print(clicks_by_source)
print(clicks_pivot)
#print(a_or_b_click)