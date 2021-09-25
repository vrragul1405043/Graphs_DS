class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)return image;
        fill(image, sr, sc, image[sr][sc], newColor);
        return image; 
    }
private:
    void fill(vector<vector<int>>& image, int row, int col, int source_color, int new_color){
        if(row<0 || row>=image.size() || col<0 || col>=image[0].size() || image[row][col]!=source_color)return;
        
        image[row][col] = new_color;
        fill(image,row+1,col,source_color,new_color);
        fill(image,row-1,col,source_color,new_color);
        fill(image,row,col+1,source_color,new_color);
        fill(image,row,col-1,source_color,new_color);
    }
};
