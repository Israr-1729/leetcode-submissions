class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> sortedCommon(size1 + size2);
        int entries = 0;
        int i = 0;
        int j = 0;
                 while (i < size1 && j < size2) {
                if (nums1[i] <= nums2[j]) {
                    sortedCommon[entries] = nums1[i];
                    entries++;
                    i++;
                }

                else {
                    sortedCommon[entries] = nums2[j];
                    entries++;
                    j++;
                }
            }

            while (j < size2) {
                sortedCommon[entries] = nums2[j];
                entries++;
                j++;
            }

            while (i < size1) {
                sortedCommon[entries] = nums1[i];
                entries++;
                i++;
            }

            int sizeCommon = size1 + size2;
            if (sizeCommon % 2 == 0) {
                return (sortedCommon[sizeCommon / 2] +
                        sortedCommon[(sizeCommon / 2) - 1]) /
                       2.0;
            } else {
                return (double)sortedCommon[sizeCommon / 2];
            }
        }
    };