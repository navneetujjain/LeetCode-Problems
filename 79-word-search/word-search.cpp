class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int index, int m, int n, int i, int j){
      if(index == word.length()) return true;

      if(i < 0 || j < 0 || i == m || j == n || board[i][j] != word[index] || board[i][j] == '!') return false;

      char c = board[i][j];
      board[i][j] = '!';

      bool top = check(board, word, index + 1, m, n, i - 1, j); //upar
      bool right = check(board, word, index + 1, m, n, i, j + 1); //right
      bool down = check(board, word, index + 1, m, n, i + 1, j); //neeche
      bool left = check(board, word, index + 1, m, n, i, j - 1); //left

      board[i][j] = c;

      return top || down || right || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
      int m = board.size();
      int n = board[0].size();
      int index = 0;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(board[i][j] == word[index]){
            if(check(board, word, index, m , n, i, j)) return true;
          }
        }
      }
      return false;
    }
};