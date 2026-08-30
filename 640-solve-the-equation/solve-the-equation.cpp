class Solution {
public:

    void fillArrays(vector<string> &LHS, vector<string> &RHS, string &equation)
    {
        if(equation[0] != '-')
        equation.insert(0, 1, '+');

        for(int i = 0; i < equation.size(); i++)
        {
            if(equation[i] == '=' && equation[i+1] != '-')
            {
                equation.insert(i+1, 1, '+');
                break;
            }
        }

        int i = 0; int size = equation.size();
        while(i < size && equation[i] != '=')
        {
            if(equation[i] == '+' || equation[i] == '-')
            {
                string newNum = "";
                newNum += equation[i];
                i++;
                while(i < size && equation[i] != '=' && (isdigit(equation[i])||isalpha(equation[i])))
                {
                    newNum += equation[i];
                    i++;
                }
                LHS.push_back(newNum);
            }
            else
            i++;
        }

        i++;
        while(i < size && equation[i] != '=')
        {
            if(equation[i] == '+' || equation[i] == '-')
            {
                string newNum = "";
                newNum += equation[i];
                i++;
                while(i < size && equation[i] != '=' && (isdigit(equation[i])||isalpha(equation[i])))
                {
                    newNum += equation[i];
                    i++;
                }
                RHS.push_back(newNum);
            }
            else
            i++;
        }
    }

    string solveEquation(string equation) {
        vector<string> LHS;
        vector<string> RHS;
        fillArrays(LHS, RHS, equation);

        int LHSConstant = 0; int RHSConstant = 0; int LHSVariable = 0; int RHSVariable = 0;

        for(auto &s : LHS)
        {
            if(s.back() == 'x')
            {
                if(s=="+x")
                {
                    LHSVariable += 1;
                }

                else if(s == "-x")
                {
                    LHSVariable -= 1;
                }

                else
                {
                s.pop_back();
                LHSVariable += stoi(s);
                }
            }

            else
            {
                LHSConstant += stoi(s);
            }
        }

        for(auto &s : RHS)
        {
            if(s.back() == 'x')
            {
                if(s=="+x")
                {
                    RHSVariable += 1;
                }

                else if(s == "-x")
                {
                    RHSVariable -= 1;
                }

                else
                {
                s.pop_back();
                RHSVariable += stoi(s);
                }
            }

            else
            {
                RHSConstant += stoi(s);
            }
        }

        //cout<<LHSVariable<<"x+("<<LHSConstant<<")="<<RHSVariable<<"x+("<<RHSConstant<<")";
        int LHSCoeffOfX = LHSVariable - RHSVariable;
        int RHSValue = RHSConstant - LHSConstant;

        if(LHSCoeffOfX == 0 && RHSValue == 0)
        {
            return "Infinite solutions";
        }

        else if(LHSCoeffOfX == 0 && RHSValue != 0)
        {
            return "No solution";
        }

        else
        {
            return "x=" + to_string(RHSValue/LHSCoeffOfX);
        }

        return "";
    }
};