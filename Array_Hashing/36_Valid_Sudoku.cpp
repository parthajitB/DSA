/**	
	Valid Sudoku
	Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

	Each row must contain the digits 1-9 without repetition.
	Each column must contain the digits 1-9 without repetition.
	Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
	Note:

	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
	Only the filled cells need to be validated according to the mentioned rules.
	
	https://leetcode.com/problems/valid-sudoku/description/
	
	https://www.youtube.com/watch?v=RdakO1_niYE&t=19s
	
**/
// LATEST one 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> subbox[9];

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if( board[i][j] == '.')
                    continue;

                char value=board[i][j];

                int boxIndex= (i/3)  * 3 + (j/3);

                if( row[i].count(value) || col[j].count(value) || subbox[boxIndex].count(value) )
                {
                    return false;
                }

                row[i].insert(value);
                col[j].insert(value);
                subbox[boxIndex].insert(value);
            }
        }

        return true;
    }
};
Time complexity: O(81) → O(1)
			rows(9) * columns(9)=81

Space complexity: O(243) → O(1)
		rows(81)+columns(81)+boxes(81)=243

//=================================================

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<int> row[9];
        unordered_set<int> col[9];
        unordered_set<int> subbox[9];

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int val=board[i][j];

                if(val==0)
                    continue;

                if(row[i].find(val) != row[i].end())
                {
                        return false;
                }
                row[i].insert(val);

                if(col[j].find(val) != col[j].end())
                {
                        return false;
                }
                col[j].insert(val);

                int indx= ((i /3) * 3) + j / 3; 

                if(subbox[indx].find(val) != subbox[indx].end())
                {
                        return false;
                }

                subbox[indx].insert(val);

            }
        }

        return true;
    }
};


Time complexity:  O(n2)   ---   O(1) 
space complexity:  O(n2)	--- O(1)

Becasue here n is defined and we know the N , hence its constant work 