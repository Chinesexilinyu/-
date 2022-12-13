from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.datasets import fetch_20newsgroups
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
 

news = fetch_20newsgroups(subset='all')     
 

train_data, test_data, train_target, test_target = train_test_split(news.data, news.target)
 

transfer = TfidfVectorizer()
train_data = transfer.fit_transform(train_data)
test_data = transfer.transform(test_data)
 
estimstor = MultinomialNB()
estimstor.fit(train_data, train_target)
 

predict = estimstor.predict(test_data)
print(test_target == predict)

score = estimstor.score(test_data, test_target)
print('准确率', score)
