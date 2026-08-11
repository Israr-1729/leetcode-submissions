class Spreadsheet {
public:

    vector<vector<int>> ss;
    Spreadsheet(int rows) {
        vector<int> toInsert(26, 0);
        for(int i = 0; i<rows; i++)
        {
            ss.push_back(toInsert);
        }
    }
    
    bool isDigit(char c)
    {
        if(c >= '0' && c <= '9')
        return true;

        return false;
    }
pair<int, int> parser(const string &cell)
{
    pair<int, int> result;

    result.first = stoi(cell.substr(1)) - 1; // row
    result.second = cell[0] - 'A';           // column

    return result;
}
    void setCell(string cell, int value) {
        pair<int, int> cellCopy = parser(cell);
        ss[cellCopy.first][cellCopy.second] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        int plusIndex;
        for(int i = 0; i<formula.size(); i++)
        {
            if(formula[i] == '+') {
            plusIndex = i; 
            break;
            }
        }

        // =A17+65
        // 0123456
        //7
        string s1 = formula.substr(1, plusIndex - 1);
        string s2 = formula.substr(plusIndex + 1, formula.size() - plusIndex - 1);
        int num1; int num2;

        if(isDigit(s1[0]))
        num1 = stoi(s1);
        else
        {
            pair<int, int> cell = parser(s1);
        num1 = ss[cell.first][cell.second];
        }

        if(isDigit(s2[0]))
        num2 = stoi(s2);

        else
        {
            pair<int, int> cell = parser(s2);
            num2 = ss[cell.first][cell.second];
        }
        
        return num1 + num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */