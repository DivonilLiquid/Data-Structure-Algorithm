class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& ar, int k) {
        int n=ar.size();
        vector<double> v;
        vector<int>::iterator vtr;
            vtr=ar.begin();
        multiset<pair<int,int> > s;
        multiset<pair<int,int> > ::iterator st;
        for(int i=0;i<k;i++)
        {
            s.insert(make_pair(ar[i],i));
        }
        int start=0;
        for(int j=k-1;j<n;j++)
        {
            st=s.begin();
            if(s.size()%2!=0)
            {
                int md=(s.size())/2;
                for(int z=0;z<md;z++)
                {
                    st++;
                }
                pair<int,int> p=*(st);
                double in=p.first;
                v.push_back(in);

                s.erase(make_pair(*vtr,start++));
                vtr++;
                if(j<=n-2)
                {
                    s.insert(make_pair(ar[j+1],j+1));
                }
            }
            else
            {

                int md1=s.size()/2;
                for(int z=0;z<md1;z++)
                {
                    st++;
                }
                pair<int,int> p1=*st;
                pair<int,int> p2=*(--st);
                double v1=p1.first;
                double v2=p2.first;
                s.erase(make_pair(*vtr,start++));
                vtr++;
                double in=(v1+v2)/2.0;
                v.push_back(in);
                if(j<=n-2)
                {
                    s.insert(make_pair(ar[j+1],j+1));
                }

            }

        }
        return v;
    }
};