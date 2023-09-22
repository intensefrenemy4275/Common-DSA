//link - https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int m = matrix.size();
	    int n = matrix[0].size();
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1e9;
	        }
	    }
	    for(int k=0;k<m;k++)
	    {
	        for(int i=0;i<m;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }   
	    }
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1;
	        }
	    }
	    
	}
};