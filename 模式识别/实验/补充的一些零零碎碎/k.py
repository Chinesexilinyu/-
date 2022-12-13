
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.cluster import KMeans
import numpy as np
import re
import string
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
from sklearn.datasets import fetch_20newsgroups
from wordcloud import WordCloud
#%matplotlib inline
dataset = fetch_20newsgroups(
    download_if_missing=True, remove=('headers', 'footers', 'quotes'))
#dataset.target_names

targets, frequency = np.unique(dataset.target, return_counts=True)
targets_str = np.array(dataset.target_names)
fig = plt.figure(figsize=(10, 5), dpi=80, facecolor='w', edgecolor='k')
plt.bar(targets_str, frequency)
plt.xticks(rotation=90)
plt.title('Class distribution of 20 Newsgroups Training Data')
plt.xlabel('News Group')
plt.ylabel('Number')
plt.show()
dataset_df = pd.DataFrame({'data': dataset.data, 'target': dataset.target})

def alphanumeric(x):
    return re.sub(r"""\w*\d\w*""", ' ', x)
def punc_lower(x):
    return re.sub('[%s]' % re.escape(string.punctuation), ' ', x.lower())
dataset_df['data'] = dataset_df.data.map(alphanumeric).map(punc_lower)
#dataset_df.da
texts = dataset.data
target = dataset.target
vectorizer = TfidfVectorizer(stop_words='english')
X = vectorizer.fit_transform(texts)
number_of_clusters = 20
model = KMeans(n_clusters=number_of_clusters,
               init='k-means++',
               max_iter=100,
               n_init=1)
model.fit(X)
KMeans(max_iter=100, n_clusters=20, n_init=1)
dict_list = []
order_centroids = model.cluster_centers_.argsort()[:, ::-1]
terms = vectorizer.get_feature_names()
for i in range(number_of_clusters):
    dict = {}
    print("Cluster %d:" % i),
    for ind in order_centroids[i, :20]:
        print(' %s' % terms[ind])
        dict[terms[ind]] = model.cluster_centers_[i][ind]
    dict_list.append(dict)

X = vectorizer.transform([texts[400]])
cluster = model.predict(X)[0]

count_target = dataset_df['target'].value_counts()
plt.figure(figsize=(8, 4))
sns.barplot(count_target.index, count_target.values, alpha=0.8)
plt.ylabel('Number', fontsize=12)
plt.xlabel('Target', fontsize=12)
for i in range(20):
    wordcloud = WordCloud(background_color="white", relative_scaling=0.5,
                          normalize_plurals=False).generate_from_frequencies(dict_list[i])
    fig = plt.figure(figsize=(8, 6))
    plt.axis('off')
    plt.title('Cluster %d:' % i, fontsize='15')
    plt.imshow(wordcloud)
    plt.show()

