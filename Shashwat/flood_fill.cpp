#include <iostream>
#include <vector>
using namespace std;


//LC 733
/*basically u are given a 2d grid (like an image) and u start from a pixel sr, sc.You have to change its color and also all the connected pixels (up, down, left, right) which have the same original color to a new one.*/

/*Approach-->first we take the color of the starting pixel and check if it’s already the same as the new color, 
if yes then we just return the image as it is. otherwise, we start a dfs (or bfs) from that pixel and move in all four directions — up, down, left, and right. whenever we find a pixel that has the same original color, we change it to the new color and then keep doing the same thing for its neighbours. basically it spreads like paint filling all the connected cells of the same color.*/
class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
        image[sr][sc] = newColor;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = sr + dx[i];
            int newCol = sc + dy[i];

            if (newRow >= 0 && newRow < image.size() &&
                newCol >= 0 && newCol < image[0].size() &&
                image[newRow][newCol] == originalColor) {
                dfs(image, newRow, newCol, newColor, originalColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor != newColor)
            dfs(image, sr, sc, newColor, originalColor);
        return image;
    }
};


int main() {
    Solution sol;

   
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Resultant Image after Flood Fill:\n";
    for (auto& it : result) {
        for (auto& pixel : it)
            cout << pixel << " ";
        cout << "\n";
    }

    return 0;
}
