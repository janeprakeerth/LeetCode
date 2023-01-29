class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int n=1;
        int count = 0;
        while(n<=right){
            if(n>left){
                return 0;
            }
            if(count<31){
                cout<<"ok"<<endl;
                n = n<<1;
            }else{
                break;
            }
            count++;
        }
        cout<<n<<endl;
        n=n>>1;
        if(n>left){
            return 0;
        }
        int num = 0;
        num = ~num;
        for(int i=left;i<right;i++){
            num = num&i;
        }
        num= num&right;
        return num;
    }
};