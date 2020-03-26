class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'I' : 
                    ans = (s[i + 1] == 'V' || s[i + 1] == 'X') ? ans - 1 : ans + 1; 
                    break;
                case 'X' : 
                    ans = (s[i + 1] == 'L' || s[i + 1] == 'C') ? ans - 10 : ans + 10; 
                    break;                      
                case 'C' : 
                    ans = (s[i + 1] == 'D' || s[i + 1] == 'M') ? ans - 100 : ans + 100; 
                    break;
                case 'V' : 
                    ans = ans + 5; 
                    break;
                case 'L' : 
                    ans = ans + 50; 
                    break;
                case 'D' : 
                    ans = ans + 500; 
                    break;
                case 'M' : 
                    ans = ans + 1000; 
                    break;      
                default  : 
                    break;  
            }
        } 
        return ans;
    }
};

//I：1        
//V：5           
//X：10      
//L：50   
//C：100      
//D：500         
//M：1000
//V、X左邊小數只用I；L、C左邊小數只用X；D、M左邊小數只用C
