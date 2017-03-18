
// Hard

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if(points.empty()) {  // !
			return 0;
		}

		int max = 0;
		for(int i = 0; i < points.size(); ++i) {
			int cur = 0;
			int vertical = 0;
			int same = 1;
			map<double, int> m;
			for(int j = 0; j < points.size(); ++j) {
				if(j == i) {
					continue;
				}
				double slope;
				if(points[j].x != points[i].x) {  // !
					slope = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);

					if(m.find(slope) != m.end()) {
						++m[slope];
					} else {
						m[slope] = 1;
					}
					if(m[slope] > cur) {
						cur = m[slope];
					}
				} else if(points[j].x == points[i].x && points[j].y == points[i].y) {  // ! 
					++same;
				} else {
					++vertical;
					if(vertical > cur) {
						cur = vertical;
					}
				}
			}
			if(cur + same > max) {
				max = cur + same;
			}
		}

		return max;  // !
    }
};


class Solution {
public:
    int maxPoints(vector<Point> &points) {
    	int maxPoints = 0;
    	int curPoints = 0;
    	int samePoints = 0;
    	double slope = 0;
    	std::map<double, int> map;

    	for(int i = 0; i < points.size(); ++i) {
    		curPoints = 1;
    		samePoints = 0;
    		map.clear();

    		for(int j = i + 1; j < points.size(); ++j) {
    			if(points[j].x == points[i].x && points[j].y == points[i].y) {
    				++samePoints;
				} else {
    				if(points[j].x != points[i].x) {
    					slope = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
    				} else {
    					slope = std::numeric_limits<double>::infinity();
    				}

    				if(map.find(slope) == map.end()) {
    					map[slope] = 2;
    				} else {
    					map[slope] += 1;
    				}

    				if(map[slope] > curPoints) {
    					curPoints = map[slope];
    				}
    			}
    		}

    		curPoints += samePoints;

    		if(curPoints > maxPoints) {
    			maxPoints = curPoints;
    		}
    	}

    	return maxPoints;
    }
};

