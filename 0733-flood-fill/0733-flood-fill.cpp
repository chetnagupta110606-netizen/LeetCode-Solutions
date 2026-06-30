class Solution {
public:
 
    void DFS(vector<vector<int>>& image, int i, int j, int orgColor,int newColor){
        if(i<0 || j<0 || i>image.size()-1 || j>image[0].size()-1 || image[i][j]==newColor || image[i][j] != orgColor){
            return;
        }
        image[i][j] = newColor;
        DFS(image,i-1,j,orgColor,newColor);//top
        DFS(image,i+1,j,orgColor,newColor);//bottom
        DFS(image,i,j-1,orgColor,newColor);//left
        DFS(image,i,j+1,orgColor,newColor);//right

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

         DFS(image,sr,sc,image[sr][sc],color);
         return image;
    }
};