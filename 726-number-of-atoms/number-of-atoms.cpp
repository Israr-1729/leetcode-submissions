//SPENT 3 HOURS ON THIS. COULDN'T SOLVE. JUST FOR FUTURE REFERENCE.
//P.S. I MADE THE MISTAKE OF MISUNDERSTANDING NESTED LOOPS

class Solution {
public:
    vector<string> atoms;
    vector<string> uniqueAtoms;
    vector<int> runningBracket;
    unordered_map<string, vector<int>> positions; //Index of last letter of element's symbol
    unordered_map<string, vector<int>> bracketsToAccount;
    unordered_map<string, int> freq;
    unordered_map<string, vector<vector<int>>> atomToFactors; // First Number is Immediate Left. Rest are after brackets
    unordered_map<string, int> result;
    int extractNumber (const string &formula, int k)
    {
        if(k == formula.size() - 1 || !isDigit(formula[k+1]))
        return 1;

        int ans = 0;
        k++;
        while(k < formula.size() && isDigit(formula[k]))
        {
            ans = ans * 10 + (formula[k] - '0');
            k++;
        }
        return ans;
    }

    bool isCapital(char c) {
        if (c >= 'A' && c <= 'Z')
            return true;

        return false;
    }

    bool isSmall(char c) {
        if (c >= 'a' && c <= 'z')
            return true;

        return false;
    }

    bool isDigit(char c) {
        if (c >= '0' && c <= '9')
            return true;

        return false;
    }

    //fills the atom vector with the symbols of all the atoms present in formula.
    //fills the position map with all the positions at which a particular atom appears
    void fillAtomsVectorAndPositionMap (const string &formula) {
        int i = 0;
        int size = formula.size();
        bool twoLetterElementFound = false;

        while (i < size) {
            twoLetterElementFound = false;
            if (formula[i] == '(') {
                i++;
            }

            if (formula[i] == ')') {
                i++;
            }

            if (i<size && isCapital(formula[i])) {
                string newElement = "";
                newElement += formula[i];
                if (i + 1 < size && isSmall(formula[i + 1])) //To not skip consecutive elements
                    i++;
                while (i < size && isSmall(formula[i])) {
                    newElement += formula[i];
                    i++;
                }
                atoms.push_back(newElement);
                positions[newElement].push_back(newElement.size() == 1 ? i : i-1);
                if(newElement.size() == 2)
                twoLetterElementFound = true;
            }
            if(!twoLetterElementFound) i++;
        }
    }

    //fills uniqueAtoms vector with all the unique atoms in the formula
    void fillUniqueAtomsVector() {
        for(auto &a : freq)
        {
            uniqueAtoms.push_back(a.first);
        }

        sort(uniqueAtoms.begin(), uniqueAtoms.end());
    }

    //fills frequency map with all the number of instances of a particular element
    void fillFreq() {
        for(auto &s : atoms)
        {
            freq[s]++;
        }
    }

    //for each occurence of an element, fills the map with an integer of number of brackets to be taken into account while multiplying
    void fillBracketsToAccount(const string &formula) {
        for(string &s : uniqueAtoms)
        {
            int numberOfOccurences = freq[s];
            vector<int> result(numberOfOccurences);

            for(int a : positions[s])
            bracketsToAccount[s].push_back(runningBracket[a]);

        }
    }

    //just a helper function to reduce time complexity
    void fillRunningBracketVector(const string &formula)
    {
        int runningSum = 0;
        for(char c : formula)
        {
            if(c == '(')
            runningSum++;

            if(c == ')')
            runningSum--;

            runningBracket.push_back(runningSum);
        }
    }

    void fillAtomToFactors (const string &formula) {
        //choses an element from the list of unique elements
        for (string &s : uniqueAtoms)
        {
            vector<vector<int>> forThisAtom;
            //chooses the kth instance of appearance of that atom
            for(int i = 0; i<freq[s]; i++)
            {
                vector<int> forThisInstance;
                //gives number of brackets to consider
                int numberOfBracketsToConsider = bracketsToAccount[s][i];
                int startingPosition = positions[s][i];
                int j = startingPosition;
                int bracketsEncountered = 0;
                int newStarted = 0;

                forThisInstance.push_back(extractNumber(formula, startingPosition));

                while(true)
                {

                    if(j < formula.size() && formula[j] == ')' && newStarted != 0)
                    {
                        newStarted--;
                    }

                    else if(j < formula.size() && formula[j] == ')' && newStarted == 0)
                    {
                        bracketsEncountered++;
                        forThisInstance.push_back(extractNumber(formula, j));
                    }

                    if(j < formula.size() && formula[j] == '(')
                    {
                        newStarted++;
                    }


                    if(bracketsEncountered == numberOfBracketsToConsider)
                    break;

                    j++;
                }
                forThisAtom.push_back(forThisInstance);
            }
            atomToFactors[s] = forThisAtom;
        }
    }

    void FillResult()
    {
        for(auto &s : atomToFactors)
        {
            int ans = 0;
            const vector<vector<int>> &karoSolve = s.second;
            for(auto &v : karoSolve)
            {
                int runningProduct = 1;
                for(int a : v)
                {
                    runningProduct *= a;
                }
                ans += runningProduct;
            }
            result[s.first] = ans;
        }
    }



    string countOfAtoms(string formula) {


        fillAtomsVectorAndPositionMap(formula);
        fillFreq();
        fillUniqueAtomsVector();
        fillRunningBracketVector(formula);
        fillBracketsToAccount(formula);
        fillAtomToFactors(formula);
        FillResult();

        string finalAns = "";

        for(string &s : uniqueAtoms)
        {
            finalAns += s;
            if(result[s] != 1)
            finalAns += to_string(result[s]);
        }

        return finalAns;
    }
};