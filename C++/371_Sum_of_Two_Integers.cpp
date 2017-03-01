
class Solution {
public:
    int getSum(int a, int b) {
        while(a & b) {
          int c = (a & b ) << 1;
          a = a ^ b;
          b = c;
        }
        return a ^ b;
    }
};


func getSum(a int, b int) int {
        m := a
        n := b
        for m & n != 0 {
          r := (m & n) << 1
          m = (m ^ n)
          n = r
        }

        return m ^ n
}

