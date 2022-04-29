#include <iostream>
using namespace std;

int maxSubsequenceSum_N3(int a[], int size, int &start, int &end) {
    int maxSum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int thisSum = 0;
            for (int k = i; k <= j; k++)
                thisSum += a[k];
            if (thisSum > maxSum) {
                maxSum = thisSum;
                start = i;
                end = j;
            }
        }
    }
    return maxSum;
}

int maxSubsequenceSum_N2(int a[], int size, int &start, int &end) {
    int maxSum = 0;
    for (int i = 0; i < size; i++) {
        int thisSum = 0;
        for (int j = i; j < size; j++) {
            thisSum += a[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
                start = i;
                end = j;
            }
        }
    }
    return maxSum;
}

int maxSubsequenceSum_NlogN_(int a[], int left, int right, int &start, int &end) {
    int center;
    int maxLeft, maxRight;
    int leftSum = 0, rightSum = 0;
    int maxLeftTmp = 0, maxRightTmp = 0;
    int startL, endL, startR, endR;

    if (left == right) {
        start = end = left;
        return a[left]>0 ? a[left] : 0;
    }

    center = (left + right) / 2;
    maxLeft = maxSubsequenceSum_NlogN_(a, left, center, startL, endL);
    maxRight = maxSubsequenceSum_NlogN_(a, center+1, right, startR, endR);

    start = center;
    for (int i = center; i >= left; i--) {
        leftSum += a[i];
        if (leftSum > maxLeftTmp) {
            maxLeftTmp = leftSum;
            start = i;
        }
    }
    end = center + 1;
    for (int i = center + 1; i <= right; i++) {
        rightSum += a[i];
        if (rightSum > maxRightTmp) {
            maxRightTmp = rightSum;
            end = i;
        }
    }

    if (maxLeft > maxRight) {
        if (maxLeft > maxLeftTmp + maxRightTmp) {
            start = startL;
            end = endL;
            return maxLeft;
        } else {
            return maxLeftTmp+maxRightTmp;
        }
    } else {
        if (maxRight > maxLeftTmp + maxRightTmp) {
            start = startR;
            end = endR;
            return maxRight;
        } else {
            return maxLeftTmp+maxRightTmp;
        }
    }
}
int maxSubsequenceSum_NlogN(int a[], int size, int &start, int &end) {
    return maxSubsequenceSum_NlogN_(a, 0, size-1, start, end);
}

int maxSubsequenceSum_N(int a[], int size, int &start, int &end) {
    int maxSum = 0, thisSum = 0;
    int startTmp = 0;
    start = end = 0;

    for (int i = 0; i < size; i++) {
        thisSum += a[i];
        if (thisSum <= 0) {
            thisSum = 0;
            startTmp = i + 1;
        } else {
            if (thisSum > maxSum) {
                maxSum = thisSum;
                start = startTmp;
                end = i;
            }
        }
    }
    return maxSum;
}

int main() {
    int a[]={1, -2, 3, 5, 6, -7, -8, -9, 11};
    int start, end;
    cout << maxSubsequenceSum_N(a, 9, start, end) << endl;
    cout << start << ' ' << end << endl;
    return 0;
}
