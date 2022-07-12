vector<int> Solution::solve(int n) {
    if(n==1)return {1,1};
    if(!(n&(n+1))){
        return {1,n-1};
    }
    int x=0,tp=n;
    int i=0;
    while(tp){
        if((tp&1)==0){
            x|=(1<<i);
            //cout<<"Dsfadf";
        }
        i++;
        tp>>=1;
    }
    return {x,n};
}
