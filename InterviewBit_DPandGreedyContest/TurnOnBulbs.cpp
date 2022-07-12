int Solution::solve(int n) {
    return (2*(n/6))+((n%6)?((n%6==1)?1:2):0);
}
