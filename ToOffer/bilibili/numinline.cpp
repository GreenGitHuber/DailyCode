/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
///这道题我不会！！！！
///放弃！！！！！！
class Solution {
public:
    /**
     * @param points: an array of point
     * @return: An integer
     */
    int maxPoints(vector<Point> &points) {
        // write your code here
        map<double,int> k;
        int len = points.size();
        if(len ==0)
            return 0;
        if(len == 1)
         return 1;
        int max_k = INT_MIN;
        for(int i=0;i<len;++i)
        {
            double k_i;
            int samepoint =0;
            int tem_max=1;

            for(int j=i+1;j<len;++j)
            {
                
                if(points[i].y==points[j].y && points[i].x == points[j].x)
                    {
                        samepoint++;
                        continue;
                    }
                else if(points[i].x == points[j].x)
                {
                    k_i = INT_MAX;
                }
                    
                else
                    k_i=(points[i].y-points[j].y)/(points[i].x-points[j].x);
                int cur_item_num=1;
                if(k.find(k_i)!=k.end())
                {
                    k[k_i]++;
                    cur_item_num=k[k_i];
                    // if(k[k_i]>max_k)
                    //     max_k= k[k_i];
                    // tem_max = max(tem_max,k[k_i]);
                }
                else
                {
                    k[k_i]=2;
                    cur_item_num=k[k_i];
                    // if(k[k_i]>max_k)
                    //     max_k= k[k_i];
                }
                tem_max = max(tem_max,cur_item_num);
            }
            k.clear();
            max_k = max(tem_max+samepoint,max_k);
        }
        return max_k;
    }
};