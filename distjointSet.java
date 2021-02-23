class dsd{
        public int[] p;
        public int[] rank;

        public dsd(int n)
        {
            p=new int[n];
            rank=new int[n];
            for(int i=0;i<n;i++)
            {    p[i]=i;
                rank[i]=0;
            }   
        }
        int root(int a)
        {
            if(a==p[a])
                return a;
            
            p[a]=root(p[a]);
            return p[a];
        }
        void unite(int a,int b)
        {
            a=root(a);
            b=root(b);
            if(a==b)
                return ;
            if(rank[a]==rank[b])
            {
                rank[a]++;
                p[b]=a;
            }
            else if(rank[a]>rank[b])
            {
                p[b]=a;   
            }
            else
                p[a]=b;


        }
    }
