class Solution {
public:
    
    
    string addBinary(string a, string b) {
        
        // string to int method
        // stoi(string, index of the start of the string, base)
        // base = (for binary = 2, for decimal = 10, for hexadecimal = 16 and octal - 8)
        // base = 10 and index = 0 (default) and optional parameters
        
        // way to convert binary number to binary string
        // string ans = bitset<32>(n1+n2).to_string();
        
        string ans = "";
        
        int carry = 0;
        
        long long i = a.size()-1, j = b.size()-1;
        
        
        while(i >= 0 || j >= 0)
        {
            int x, y;
            
            if (i < 0)
                x = 0;
            else
                x = a[i]-'0';
            
            if (j < 0)
                y = 0;
            else
                y = b[j]-'0';
            
            // cout << x << " " << y << " " << carry << endl;
            // cout << ans << endl;
            
            if (x + y + carry == 3)
            {
                carry = 1;
                ans += '1';
            }
            else if (x + y + carry == 2)
            {
                carry = 1;
                ans += '0';
            }
            else if (x + y + carry == 1)
            {
                ans+= '1';
                carry = 0;
            }
            else if (x + y + carry == 0)
            {
                ans+= '0';
                carry = 0;
            }
            
            
            // cout << x << " " << y << " " << carry << endl;
            // cout << ans << endl << endl << endl;
            
            i--, j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        if (carry)
            ans.insert(ans.begin(),'1');
        
        return ans;
        
        
        
        
    }
};