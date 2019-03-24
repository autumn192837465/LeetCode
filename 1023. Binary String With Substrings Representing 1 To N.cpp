/*
	string IntToBitstring(int n){
		string bitstr;
		while(n){
			if(n&1){
				bitstr = "1" + bitstr;
			}
			else{
				bitstr = "0" + bitstr;
			}
			n >>=1;
		}
		return bitstr;
	}

	class Solution {
	public:
		bool queryString(string S, int N) {
			bool usedTable[N];
			memset(usedTable,false,sizeof(usedTable));
			for(int i = N;i;i--){
				if(!usedTable[i-1]){
					string::size_type pos = S.find(IntToBitstring(i));
					if(pos!=string::npos){
						int temp = i;
						while(temp && !usedTable[temp-1]){
							usedTable[temp-1] = true;
							temp >>=1;
						}
					}
					else{
						return false;
					}
				}
			}
			return true;
		}
	};
*/
string IntToBitstring(int n){
    string bitstr;
    while(n){
        if(n&1){
            bitstr = "1" + bitstr;
        }
        else{
            bitstr = "0" + bitstr;
        }
        n >>=1;
    }
    return bitstr;
}

class Solution {
public:
    bool queryString(string S, int N) {
        bool usedTable[N];
        memset(usedTable,false,sizeof(usedTable));
        for(int i = N;i;i--){
            if(!usedTable[i-1]){
                string::size_type pos = S.find(IntToBitstring(i));
                if(pos!=string::npos){
                    int temp = i;
                    while(temp && !usedTable[temp-1]){
                        usedTable[temp-1] = true;
                        temp >>=1;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};