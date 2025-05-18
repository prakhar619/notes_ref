# Temp Data 
Twitter Architecture
2 main ops:
1. Post Tweet
    4.6k requests/sec [Avg]
    12k requests/sec  [Peak]
2. Home Timeline 
    300k requests/sec 

Method 1:  
Single large Tweet Pool.  
When a user requests their home timeline, look up all people they follow, then find all tweets for each of those users, merge them sort them, filter them

Method 2: 
Maintain a cache for each user's home timeline. When a user post, look up all the people that follow him/her/it and insert the post in their cache. [FANOUT strategy]

Currently Method 3: 
Combination of both. Some account  uses method 1, most method 2.

Fact:  
Avg rate of published tweets is lower by order of 2 in magnitude then rate of home timelines reads.

More follower more fanout become difficult.











More time is taken to load accounts of heavy usage-users.  
But those are most valuable customers.  
1s delay reduces customer satisfaction by 16%.
1s increase in speed increases satisfaction by 1%

    



