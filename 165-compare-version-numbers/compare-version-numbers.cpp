class Solution {
public:

    int revised(string &version1, string &version2)
    {
        int numDots1 = 0;
        int numDots2 = 0;
        int size1 = version1.size();
        int size2 = version2.size();

        for(int i = 0; i<size1; i++)
        {
            if(version1[i]=='.')
            numDots1++;
        }

        for(int i = 0; i<size2; i++)
        {
            if(version2[i]=='.')
            numDots2++;
        }

        if(numDots1<numDots2)
        {
            int toAdd = numDots2-numDots1;
            for(int i = 0; i<toAdd; i++)
            {
                if(i!=toAdd-1)
                version1 += ".0";
                else
                version1 += "0";
            }
        }

        if(numDots2<numDots1)
        {
            int toAdd = numDots1-numDots2;
            for(int i = 0; i<toAdd; i++)
            {
                if(i!=toAdd-1)
                version2 += ".0";
                else
                version2 += "0";
            }
        }
        return max(numDots1, numDots2);
    }
    int compareVersion(string version1, string version2) {
        int size1 = version1.size();
        int size2 = version2.size();

        int numSegments = revised(version1, version2) + 1;

        vector<int> arr1 (numSegments);
        vector<int> arr2 (numSegments);

        int i = 0; int idx = 0;
        while(i<size1)
        {
            string thisString = "";
            while (i<size1 && version1[i] != '.')
            {
                thisString += version1[i];
                i++;
            }
            arr1[idx++] = stoi(thisString);
            i++;
        }

        i = 0; idx = 0;
        while(i<size2)
        {
            string thisString = "";
            while(i<size2 && version2[i] != '.')
            {
                thisString += version2[i];
                i++;
            }
            arr2[idx++] = stoi(thisString);
            i++;
        }

        for(int j = 0; j<numSegments; j++)
        {
            if(arr1[j]<arr2[j])
            {
                return -1;
            }

            else if(arr1[j]>arr2[j])
            {
                return 1;
            }
        }
        return 0;
    }
};