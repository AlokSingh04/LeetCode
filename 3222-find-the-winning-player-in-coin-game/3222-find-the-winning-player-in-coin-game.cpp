class Solution {
public:
    string winningPlayer(int x, int y) {
        y = y/4;
        x = min(x,y);

        return (x%2==0 ? "Bob" : "Alice");
    }
};