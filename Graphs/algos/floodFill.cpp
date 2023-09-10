//problem link - https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
class Solution {
private:
  void dfsFill(vector<vector<int>> &img , int r, int c, int before, int after,vector<vector<int>>& image)
  {
    img[r][c] = after;
    int dr[] = {-1,0,0,1};
    int dc[] = {0,-1,1,0};
    int totRow = img.size();
    int totCol = img[0].size();
    for(int i=0;i<4;i++)
    {
      int nrow = r + dr[i];
      int ncol = c + dc[i];
      if(nrow >= 0 && nrow < totRow && ncol >= 0 && ncol < totCol && img[nrow][ncol] == before && image[nrow][ncol] != after)
      {
        dfsFill(img,nrow,ncol,before,after,image);
      }
    }
    return;
  }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> img(image.size(),vector<int>(image[0].size(),0));
        for(int i=0;i<image.size();i++)
        {
          for(int j=0;j<image[0].size();j++)
          {
            img[i][j] = image[i][j];
          }
        }
        int before = image[sr][sc];
        dfsFill(img,sr,sc,before,newColor,image);
  return img;

    }
};
