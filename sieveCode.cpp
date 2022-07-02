// SIEVE CODE
 
const int N=1000005;
 
 
int h[N];
for(int i=1;i<N;++i) h[i]=i;
for(int i=4;i<N;i+=2) h[i]=2;
for(int i=3;i*i<N;++i)
{
    if(h[i]==i)
    {
        for(int j=i*i;j<N;j+=i) 
        {
            if(h[j]==j) h[j]=i;
        }
    }
}
 
 
