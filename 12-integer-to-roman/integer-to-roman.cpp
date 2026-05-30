class Solution {
public:
    string intToRoman(int num) {
        int copy = num;
        int size = 0;
        while (copy > 0) {
            size++;
            copy /= 10;
        }
        vector<int> numArray(size);
        copy = num;
        for (int i = size - 1; i >= 0; i--) {
            numArray[i] = copy % 10;
            copy /= 10;
        }

        vector<string> digitRoman(size);
        for (int i = size - 1; i >= 0; i--) {
            if (i == size - 1) {
                switch (numArray[i])

                {

                case 0: digitRoman[i] = "";
                    break;

                case 1: digitRoman[i] = "I";
                    break;

                case 2: digitRoman[i] = "II";
                    break;
                
                case 3: digitRoman[i] = "III";
                    break;
                
                case 4: digitRoman[i] = "IV";
                    break;

                case 5: digitRoman[i] = "V";
                    break;

                case 6: digitRoman[i] = "VI";
                    break;
                
                case 7: digitRoman[i] = "VII";
                    break;

                case 8: digitRoman[i] = "VIII";
                    break;
                
                case 9: digitRoman[i] = "IX";
                    break;

                default: digitRoman[i] = "";
                }
            }

            if (i == size - 2) {
                switch (numArray[i])
                {

                case 0: digitRoman[i] = "";
                    break;

                case 1: digitRoman[i] = "X";
                    break;

                case 2: digitRoman[i] = "XX";
                    break;
                
                case 3: digitRoman[i] = "XXX";
                    break;
                
                case 4: digitRoman[i] = "XL";
                    break;

                case 5: digitRoman[i] = "L";
                    break;

                case 6: digitRoman[i] = "LX";
                    break;
                
                case 7: digitRoman[i] = "LXX";
                    break;

                case 8: digitRoman[i] = "LXXX";
                    break;
                
                case 9: digitRoman[i] = "XC";
                    break;

                default: digitRoman[i] = "";
                }
            }
            if (i == size - 3) {
                switch (numArray[i])
                {

                case 0: digitRoman[i] = "";
                    break;

                case 1: digitRoman[i] = "C";
                    break;

                case 2: digitRoman[i] = "CC";
                    break;
                
                case 3: digitRoman[i] = "CCC";
                    break;
                
                case 4: digitRoman[i] = "CD";
                    break;

                case 5: digitRoman[i] = "D";
                    break;

                case 6: digitRoman[i] = "DC";
                    break;
                
                case 7: digitRoman[i] = "DCC";
                    break;

                case 8: digitRoman[i] = "DCCC";
                    break;
                
                case 9: digitRoman[i] = "CM";
                    break;
                    
                default: digitRoman[i] = "";
                }

            }
            if (i == size - 4) {
                switch (numArray[i])
                {

                case 0: digitRoman[i] = "";
                    break;

                case 1: digitRoman[i] = "M";
                    break;

                case 2: digitRoman[i] = "MM";
                    break;
                
                case 3: digitRoman[i] = "MMM";
                    break;

                default: digitRoman[i] = "";
                }
            }
        }
        string s = "";
        for(int i = 0; i<size; i++)
        s+=digitRoman[i];
        return s;
    }
};