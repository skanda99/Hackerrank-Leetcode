
// problem: "https://leetcode.com/problems/count-and-say/"

class Solution {
public:
    string countAndSay(int n) {
        queue<int> A, B;
        A.push(1);
        return countAndSay(A, B, 1, n);
    }

private:
    string countAndSay(queue<int> &A, queue<int> &B, int i, int n) {
        if (i == n) {
            return convertToString(A);
        }

        int previous, count;

        while (!A.empty()) {
            previous = A.front();
            count = 0;

            while (!A.empty() && A.front() == previous) {
                A.pop();
                count++;
            }

            B.push(previous);
            splitDigits(count, B);
        }


        return countAndSay(B, A, i+1, n);
    }

    string convertToString(queue<int> &Q) {
        string s = "";
        while (!Q.empty()) {
            s += std::to_string(Q.front());
            Q.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }

    void splitDigits(int num, queue<int> &Q) {
        while (num > 0) {
            Q.push(num%10);
            num /= 10;
        }
    }
};
