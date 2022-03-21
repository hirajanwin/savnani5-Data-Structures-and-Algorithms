#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> getBeforeMatrix(vector<vector<int>> after) {
    auto before = after;
  
    int maxRows = after.size();
    int maxCols = after[0].size();

    for (int row = 0; row < maxRows; row++) {
        for(int col = 0; col < maxCols; col++) {
            if (row > 0) 
              before[row][col] -= after[row - 1][col];
            if (col > 0) 
              before[row][col] -= after[row][col - 1];
            if (row > 0 && col > 0) 
              before[row][col] += after[row - 1][col - 1];
        }
    }

  return before;
}

int main()
{
    vector<vector<int>> after = {{2,5,9}, {7,16,27}, {15,33,45}};
    vector<vector<int>> before = getBeforeMatrix(after);
    for(int i=0; i<before.size(); i++)
    {
        for(int j=0; j<before[0].size(); j++)
        {
            cout << before[i][j] << " ";
        }
        cout << endl;
    }
}