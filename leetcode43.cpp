
// problem: "https://leetcode.com/problems/multiply-strings/"

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0')
            return "0";

        int r,c,q,i,j,n1,n2;
        string result;

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        for(i=0;i!=num2.size();i++)
        {
            string output = "";
            Append0(output,i);          // define
            n2 = num2[i]-'0';
            c = 0;

            for(j=0;j!=num1.size();j++)
            {
                n1 = num1[j]-'0';

                r = (n1*n2+c)%10;
                c = (n1*n2+c)/10;

                output.append(to_string(r));
            }

            if(c)
                output.append(to_string(c));

            Add(result,output);         // define
        }

        reverse(result.begin(),result.end());

        return result;
    }

    void Append0(string &output,int n)
    {
        int i;
        for(i=0;i!=n;i++)
            output.append("0");
    }

    void Add(string &result,string &output)
    {
        if(result.empty())
            result = output;

        else
        {
            int n1,n2,r,c,i;
            c = 0;

            for(i=0;i!=output.size();i++)
            {
                if(i >= result.size())
                {
                    n1 = output[i]-'0';
                    r = (n1+c)%10;
                    c = (n1+c)/10;

                    result.append(to_string(r));
                }
                else
                {
                    n1 = output[i]-'0';
                    n2 = result[i]-'0';

                    r = (n1+n2+c)%10;
                    c = (n1+n2+c)/10;

                    result[i] = r+'0';
                }
            }

            if(c)
                result.append(to_string(c));
        }
    }
};
