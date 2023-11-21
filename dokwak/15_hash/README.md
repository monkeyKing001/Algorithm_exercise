# 15_hash
## String
```java
String.format("%.4f", por);
```

## set 
* c++
```c++
	s.insert(num);
	s.clear();
	s.erase(num);
	s.find() == s.end();
``` 
* java 
```java
	Set<Integer> s = new HashSet<>();
	s.add(num);
	s.remove(num);
	s.contains(num); //returns true or false
	s.clear();
``` 

## treeSet
* c++
```c++
	//same with set
```
* java
```Java
	TreeSet<Integer> set = new TreeSet<Integer>();
	set.add(num);
	Iterator<Integer> it = set.iterator();
		while (it.hasNext())
		{
			System.out.print(it.next());
		}
```
## Map
* c++
```c++
	//init
	map<int, int> m;

	//insert
	m.insert({k, v});//pair

	//iterator
	map<int, int>::iterator it = m.begin();
	for (; it != m.end(); it++)
	{
		int k = m -> first;
		int v = m -> second;
	}

	//getter
	m[k];
```
* Java
```Java
	//init
	Map<Integer, Integer> map = new HashMap<Integer, Integer>();
	map.put(k, v);
	map.containsKey(k) == true
	map.remove(k);
	for (Map.Entry<Integer, Integer> e: map.entrySet()){
		int k = e.getKey();
		int v = e.getValue();
	}
```

## TreeMap
* c++
```c++
	//same with map
```

* java
```java
	TreeMap<Integer, Integer> map = new TreeMap<>();
	map.put(k, v);
	map.put(k, map.get(k) + 1);
	map.containsKey(k) == true
	map.remove(k);
	for (Map.Entry<Integer, Integer> e: map.entrySet()) {
		int k = e.getKey();
		int v = e.getValue();
	}

```

| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| easy | [7785](https://www.acmicpc.net/problem/7785) | [7785.cpp](./7785/7785.cpp) |  |
| easy | [1620](https://www.acmicpc.net/problem/1620) | [1620.cpp](./1620/1620.cpp) | use stoi in try catch |
| easy | [11723](https://www.acmicpc.net/problem/11723) | [11723.cpp](./11723/11723.cpp) | |
| easy | [18870](https://www.acmicpc.net/problem/18870) | [18870.cpp](./18870/18870.cpp) |  |
| easy | [17219](https://www.acmicpc.net/problem/17219) | [17219.cpp](./17219/17219.cpp) | use hashMap |
| easy | [4358](https://www.acmicpc.net/problem/4358) | [4358.cpp](./4358/4358.cpp) |  |
| ? | [1316](https://www.acmicpc.net/problem/1316) | [1316.cpp](./1316/1316.cpp) |  |
| ? | [25192](https://www.acmicpc.net/problem/25192) | [25192.cpp](./25192/25192.cpp) |  |
| ? | [1339](https://www.acmicpc.net/problem/1339) | [1339.cpp](./1339/1339.cpp) |  |
