#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define F first
#define S second
using namespace std;
using namespace std::chrono;

struct libInfo {
	int booksCount, signUp, bookShips;
	vector <pair<int, int>> bScore;
};

struct ansUtility {
	int libId, numBooks;
	vector<int> bookId;
};


int nbooks, nlibs, ndays;
int bookScore[100005];
libInfo library[100005];
bool booksLookUp[100005] = {0};
set <int> libraryLookUp;
vector <ansUtility> ans;


pair<long double, int> reCalcScore()
{
	pair<long double, int> m = {-1.0, -1};

	for (auto &itr : libraryLookUp)
	{
		int numCurDays = ndays - library[itr].signUp, sum = 0;
		if (numCurDays > 0)
		{
			int reqBook = min(library[itr].booksCount, library[itr].bookShips * numCurDays);
			for (int i = 0, j = 0; i < library[itr].booksCount and j < reqBook; ++i)
			{
				if (booksLookUp[library[itr].bScore[i].second] == 0)
				{
					sum += library[itr].bScore[i].first;
					++j;
				}
			}
			long double score = ((sum * 1.0) / (library[itr].signUp * 1.0));
			if(score > m.first)
				m = {score, itr};
		}
	}
	return m;
}


bool makeAnswer()
{
	pair<long double, int> m = reCalcScore();
	if(m.second == -1)
		return false;
	ndays -= library[m.second].signUp;
	ansUtility curAns;
	curAns.libId = m.second;
	curAns.numBooks = min(library[m.second].booksCount, ndays * library[m.second].bookShips);
	for (int i = 0, j = 0; i < library[m.second].booksCount and j < curAns.numBooks; ++i)
	{
		if (booksLookUp[library[m.second].bScore[i].second] == 0)
		{
			++j;
			booksLookUp[library[m.second].bScore[i].second] == 1;
			curAns.bookId.push_back(library[m.second].bScore[i].second);
		}
	}
	libraryLookUp.erase(m.second);
	ans.push_back(curAns);
	return true;
}


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif

    // cout << "Starting . . .\n";
	
	cin >> nbooks >> nlibs >> ndays;
	for (int i = 0; i < nbooks; ++i)
		cin >> bookScore[i];

	for (int i = 0; i < nlibs; ++i)
	{
		libraryLookUp.insert(i);

		cin >> library[i].booksCount >> library[i].signUp >> library[i].bookShips;
		int temp;
		for (int j = 0; j < library[i].booksCount; ++j)
		{
			cin >> temp;
			library[i].bScore.push_back({bookScore[temp], temp});
		}
		sort(library[i].bScore.begin(), library[i].bScore.end());
		reverse(library[i].bScore.begin(), library[i].bScore.end());
	}
	auto start = high_resolution_clock::now();
	while(ndays > 0 and ans.size() != nlibs)
	{
		bool check = makeAnswer();
		if(!check)
			break;
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	// cout << duration.count() << endl;
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i].libId << " " << ans[i].numBooks << endl;
		for(auto itr:ans[i].bookId)
			cout << itr << " ";
		cout << endl;
	}


	// cout << "Working. . .\n";
	return 0;
}