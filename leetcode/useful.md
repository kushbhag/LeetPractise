How to add custom function for sort, or priority queue

This will make the numbers in descending order for sort. For the priority_queues the top() is the min element (Min Heap).
```
struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs > rhs;
    }
}
```
And then it can be used as follows
```
priority_queue<int,vector<int>, CustomCompare > pq;
sort(v.begin(), v.end(), CustomCompare())
```
You can also inline your function like this
```
sort( values.begin( ), values.end( ), [ ]( const MyStruct& lhs, const MyStruct& rhs )
{
   return lhs.key < rhs.key;
});
```