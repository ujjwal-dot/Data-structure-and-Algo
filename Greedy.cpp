/////N meeting
#include<bits/stdc++.h>
bool comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
	if(a.second.first<b.second.first) return true;
	else if(a.second.first>b.second.first) return false;
	else if(a.second.second<b.second.second) return true;
	else
		return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
	int n=start.size();
	vector<pair<int,pair<int,int>>> v;
	
	for(int i=0;i<n;i++){
		v.push_back({start[i],{end[i],i+1}});
	}
	
	sort(v.begin(),v.end(),comp);
	int limit=v[0].second.first;
	vector<int> ans;
	ans.push_back(v[0].second.second);
	for(int i=1;i<n;i++){
		if(v[i].first>limit){
			ans.push_back(v[i].second.second);
			limit=v[i].second.first;
		}
	}
	
	return ans;
}

//////number of platform required
#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(dt,dt+n);
	sort(at,at+n);
	int plat=1;
	int maxplat=1;
	int i=1;
	int j=0;
	while(i<n&&j<n){
		if(at[i]<=dt[j]){
			plat++;
			i++;
		}else{
			plat--;
			j++;
		}
		maxplat=max(maxplat,plat);
	}
	return maxplat;
}

///// job schedule
#include<bits/stdc++.h>
bool comp(vector<int> a,vector<int> b){
	return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),comp);
	int n=jobs.size();
	int maxi=0;
	for(int i=0;i<n;i++){
		maxi=max(maxi,jobs[i][0]);
	}
	vector<int> slot(maxi+1,-1);
	int cnt=0;
	int maxprofit=0;
	for(int i=0;i<n;i++){
		for(int j=jobs[i][0];j>0;j--){
			if(slot[j]==-1){
				slot[j]=i;
				cnt++;
				maxprofit+=jobs[i][1];
				break;
			}
		}
	}
	
	return maxprofit;
}

///////minimum no of coins
int findMinimumCoins(int amount) 
{
    int deno[]={1,2,5,10,20,50,100,500,1000};
	int n=9;
	int cnt=0;
	vector<int> ans;
	 for(int i=8;i>=0;i--){
		 while(amount>=deno[i]){
			 amount-=deno[i];
			 cnt++;
			 ans.push_back(deno[i]);
		 }
	 }
	
	return cnt;
}
/////fractional knapsack
bool comp(pair<int,int> a,pair<int,int> b){
	double r1=(double)a.second/(double)a.first;
	double r2=(double)b.second/(double)b.first;
	
	return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
	sort(items.begin(),items.end(),comp);
	int cur=0;
	double val=0.0;
	for(int i=0;i<n;i++){
		if(cur+items[i].first<=w){
			cur+=items[i].first;
			val+=items[i].second;
		}else{
			int remain=w-cur;
			val+=((double)items[i].second/(double)items[i].first)*(double)remain;
			break;
		}
	}
	return val;
}


