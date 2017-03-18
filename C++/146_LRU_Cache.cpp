
// TODO
// Hard

struct Item {
  int key;
  int value;
  Item(int k, int val) : key(k), value(val) { }
};

class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {
        
    }
    
    int get(int key) {
        if(cacheMap.find(key) != cacheMap.end()) {
            moveToHead(key);
            return cacheMap[key]->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->value = value;
            moveToHead(key);
        } else {
            if(cacheList.size() == m_capacity) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            Item item(key, value);
            cacheList.push_front(item);
            cacheMap[key] = cacheList.begin();
        }
    }
    
    void moveToHead(int key) {
        Item updateItem = *cacheMap[key];
        cacheList.erase(cacheMap[key]);
        cacheList.push_front(updateItem);
        cacheMap[key] = cacheList.begin();
    }
private:
    int m_capacity;
    list<Item> cacheList;
    unordered_map<int, list<Item>::iterator> cacheMap; 
};


class LRUCache {
public:
    struct CacheItem {
		int key;
		int value;
		CacheItem(int k, int v) : key(k), value(v) {}
	};

    LRUCache(int capacity) {
    	m_capacity = capacity;
    }

    int get(int key) {
    	if(m_map.find(key) == m_map.end()) {
    		return -1;
    	}

    	MoveToHead(key);
    	return m_map[key]->value;
    }

    void set(int key, int value) {
    	if(m_map.find(key) != m_map.end()) {
    		m_map[key]->value = value;
    		MoveToHead(key);
    	} else {
    		CacheItem newItem(key, value);
    		if(m_cache.size() == m_capacity) {
    			m_map.erase(m_cache.back().key);
    			m_cache.pop_back();
    		}

    		m_cache.push_front(newItem);
    		m_map[key] = m_cache.begin();
    	}
    }

private:
    unordered_map<int, list<CacheItem>::iterator> m_map;
    list<CacheItem> m_cache;
    int m_capacity;

    void MoveToHead(int key) {
    	CacheItem updateItem = *m_map[key];
    	m_cache.erase(m_map[key]);
    	m_cache.push_front(updateItem);
    	m_map[key] = m_cache.begin();
    }
};

