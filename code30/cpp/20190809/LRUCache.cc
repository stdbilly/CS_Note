 ///
 /// @file    LRUCache.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-09 10:11:03
 ///
 
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
	LRUCache(size_t capacity)
	: _capacity(capacity)
	{}

	int get(int key)
	{
		auto it = _hashList.find(key);//O(1)
		if(it != _hashList.end()) {
			//查找到元素
			int ret = it->second->value;
			_nodes.splice(_nodes.begin(), _nodes, it->second);//O(1)
			_hashList[key] = _nodes.begin();//O(1)
			return ret;
		} else {
			return -1;
		}
	}

	void put(int key, int value)
	{
		auto it = _hashList.find(key);
		if(it == _hashList.end()) {
			//新节点
			if(_nodes.size() == _capacity) {
				//淘汰节点
				int k = _nodes.back().key;
				_nodes.pop_back();
				_hashList.erase(k);
			}
			_nodes.push_front(CacheNode(key, value));
			_hashList[key] = _nodes.begin();
		} else {
			//更新节点值
			it->second->value = value;
			_nodes.splice(_nodes.begin(), _nodes, it->second);
			_hashList[key] = _nodes.begin();
		}
	}
private:
	struct CacheNode {
		CacheNode(int k, int v)
		: key(k), value(v) 
		{}
		int key;
		int value;
	};

private:
	size_t _capacity;
	list<CacheNode> _nodes;
	unordered_map<int, list<CacheNode>::iterator> _hashList;
};
 
int main(void)
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cache.put(4, 4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cache.put(5, 5);
	cout << cache.get(3) << endl;
 
	return 0;
}
