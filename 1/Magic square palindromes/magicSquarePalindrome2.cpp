#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string Convert(const std::string& line)
{
    string phrase = "";
    
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
            phrase += line[i];
    }
    
    return phrase;
}

int MagicBoxSize(const std::string phrase)
{
	int i, j;
	int ltr, rtl, topDown, bottomUp;
	int N = sqrt(phrase.size());
		
	ltr = topDown = 0;
	rtl = bottomUp = N*N-1;
	
	int start, end;
	
	
	if(N*N != phrase.size())
		return 0;
	
	start = 0;
	end = N*N-1;
	for(i=0; i<(N*N)/2+(N*N)%2; i++)
	{
		
		if((phrase[ltr] != phrase[rtl] || phrase[ltr] != phrase[topDown] || phrase[ltr] != phrase[bottomUp]))
		{
			return 0;
		}
		
		ltr++;
		rtl--;
		topDown = (topDown >= N*(N-1)) ? topDown%N+1 : topDown+N;
		bottomUp = (bottomUp <= N-1) ? bottomUp+N*(N-1)-1 : bottomUp-N;
		
	}
	
	
	return 1;
	
	/*----------------------*/
    
	/*int boxSize = sqrt(phrase.size());
    
    if (boxSize * boxSize != phrase.size())
        return 0;
    
    int end = phrase.size() - 1;
    int goTo = phrase.size() / 2;
    
    for (int main = 0; main <= goTo; ++main)
    {
        if (phrase[main] != phrase[end - main])
        {
            return 0;
        }
    }
    
    return boxSize;*/
}


int main()
{
    string line;
    string phrase;
    
    int T;
    cin >> T;
    cin.ignore();
    
    for (int t = 1; t <= T; ++t)
    {
        getline(cin, line);
        
        phrase = Convert(line);
        
        cout << "Case #" << t << ":\n";
        	
        int size = MagicBoxSize(phrase);
        
        if (size)
            cout << size << '\n';
        else
            cout << "No magic :(\n";
    }
}