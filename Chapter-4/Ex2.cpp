#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);cin.tie(0);
	#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	int nxt[18][4];
	/*
	1 -> left
	2 -> right
	3 -> up
	4 -> down
	*/
	for (int i = 1; i < 15; ++i)
	{
		nxt[i][3] = i-4;
	}
	nxt[1][3] = 1;
	nxt[2][3] = 2;
	nxt[3][3] = 3;
	nxt[17][3] = 13;

	for (int i = 1; i < 15; ++i)
	{
		nxt[i][4] = i+4;
	}
	nxt[12][4] = 12;
	nxt[14][4] = 14;
	nxt[13][4] = 13;
	nxt[17][4] = 17;	

	for (int i = 1; i < 15; ++i)
	{
		nxt[i][2] = i+1;
	}
	nxt[3][2] = 3;
	nxt[7][2] = 7;
	nxt[11][2] = 11;
	nxt[17][2] = 14;

	for (int i = 1; i < 15; ++i)
	{
		nxt[i][1] = i-1;
	}
	nxt[4][1] = 4;
	nxt[8][1] = 8;
	nxt[12][1] = 12;
	nxt[17][1] = 12;
	
	float old_v[18];
	float new_v[18];
	memset(old_v, 0, sizeof(old_v));	
	memset(new_v, 0, sizeof(new_v));	
	float del = 0;
	int cnt = 0;
	
	do
	{
		del = 0;
		cnt++;
	    for (int j = 0; j < 18; ++j)
			old_v[j] = new_v[j];
		for (int i = 1; i <= 17; ++i)
		{
			if(i==15||i==16) continue;
			new_v[i]=0;
			for (int dir = 1; dir <= 4; ++dir)
			{
				new_v[i]+= (0.25*(-1+old_v[nxt[i][dir]]));
				//cout<<nxt[i][dir]<<" "<<old_v[nxt[i][dir]]<<endl;

			} 
			
		}
		for (int j = 1; j < 17; ++j)
		{	if(j==15||j==16) continue;
			del = max(del, abs(new_v[j]-old_v[j]));
		}
	}
	while(del>0.001);
	cout<<"loop has run "<<cnt<<" times "<<endl;
	for (int i = 1; i <= 17; ++i)
	{   if(i==16 || i==15) continue;
		cout<<i<<" "<<round(new_v[i])<<endl;
	}
	return 0;
}