/*
Given two integers representing the numerator and denominator of a fraction,
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

*/
#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) {
            return "0";
        }
        //注意INT_MAX和INT_MIN的处理
        long long numer = (long)numerator;
        long long denom = (long)denominator;
        string sign = "";
        if(((numer > 0)&&(denom < 0)) || ((numer < 0)&&(denom > 0))) {
            sign = "-";
        }
        string integer_part = std::to_string(std::abs(numer / denom));
        string decimal_part = get_decimal_string(numer % denom, denom);
        return sign + integer_part + decimal_part;
    }
private:
    string get_decimal_string(long long numer, long long denom) {
        if(numer == 0) {
            return "";
        }
        string ret;
        //哈希表保存已经出现过的余数，注意重复出现的余数可能出现在任何位置
        std::map<long long, int> remaind_hash;
        remaind_hash[numer] = 0;
        cal_decimal(remaind_hash, numer, denom, ret);
        return ret;
    }
    void cal_decimal(std::map<long long, int> &remaind_hash, long long numer, long long denom, string &ret) {
        int quotient = (numer * 10) / denom;
        int remaind = (numer * 10) % denom;
        ret += std::to_string(std::abs(quotient));
        if(remaind == 0) {
            ret = "." + ret;
            return;
        }else if(remaind_hash.find(remaind) != remaind_hash.end()) {
            string loopless = ret.substr(0, remaind_hash[remaind]);
            string loop = ret.substr(remaind_hash[remaind], ret.size() - remaind_hash[remaind]);
            ret = "." + loopless + "(" + loop + ")";
            return;
        }else {
            remaind_hash[remaind] = ret.size();
            return cal_decimal(remaind_hash, remaind, denom, ret);
        }
    }
};

int main() {
    Solution slt;
    cout<<slt.fractionToDecimal(-2147483648,-1)<<endl;
    return 0;
}
