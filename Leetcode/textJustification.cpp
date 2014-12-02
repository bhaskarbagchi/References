#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:

	void process(vector<string> &words, vector<string>&result, int start, int end, int L) {
	    int size = 0;
	    // end of the setence, left justification
	    if(end==words.size()-1 ) {
	        string s;
	        int last_space = L;
	        for(int i=start; i<=end; i++) {
	            last_space-=words[i].size();
	            s+=words[i];
	            if(i!=end) {
	                s+= "-";
	                last_space--;
	            }else {
	                s+= string(last_space, '-');
	            }
	        }
	        result.push_back(s); return;
	    }
	    // find the total size of the words
	    for(int i=start; i<=end; i++) {
	        size+=words[i].size();
	    }
	    // find the total space size
	    int space = L-size;
	    // if it's just one word, left justification
	    if(start==end) {
	        string s = words[start];
	        s+= string((L-size), '-');
	        result.push_back(s); return;
	    }
	    // get the average space - n words needs (n-1) consecutive space
	    int e_space = space/(end-start);
	    // get the leftover space for the first kth words
	    int n=space-e_space*(end-start);
	    string s;
	    for(int i=start; i<=end; i++) {
	        s+= words[i];                       // word
	        if(i!=end) s+=string(e_space, '-'); // space
	        if((n--)>0) s+=string(1, ' ');      // additional space if any
	    }
	    result.push_back(s);
	}
	vector<string> fullJustify(vector<string> &words, int L) {
	    vector<string> result;
	    if (L<0) return result;
	    if(words.size()==0) return result;
	    int start = 0; int sofar = 0;
	    for(int i=0; i<words.size(); i++) {
	        if(i+1<words.size() && (sofar+words[i].size()+words[i+1].size()<L)) {
	            sofar = sofar+ words[i].size()+1;
	        }else{
	            process(words, result, start, i, L);
	            start = i+1; sofar = 0;
	        }
	    }

	    return result;
	}

	/*vector<string> fullJustify(vector<string> &word, int L) {
		int len = 0, count = 0;
		vector<string>::iterator prev = word.begin();
		vector<string> output;
		for(vector<string>::iterator it = word.begin(); it<word.end(); it++) {
			len+=(*it).length();
			count++;
			if (len+count>L+1) {
				cout<<"here1"<<endl;
				int spaces = L ;
				for(vector<string>::iterator temp = prev; temp<it; temp++)
					spaces-=(*temp).length();
				int each = spaces/(count-2);
				int greater = spaces%(count-2);
				string greaterString = "";
				for(int i = 0; i<each+1; i++)
					greaterString = greaterString + " ";
				string eachString = "";
				for(int i = 0; i<each; i++)
					eachString = eachString + " ";
				cout<<spaces<<" "<<count-2<<" "<<"-"<<greaterString<<"-"<<"\n";
				string line = "";
				int k = 0;
				cout<<"each = "<<each<<" and greater = "<<greater<<"\n";
				while(prev < it){
					line = line + (*prev);
					if(k<greater)
						line = line + greaterString;
					else
						line = line + eachString;
					k++;
					prev++;
				}
				output.push_back(line);
				//
				prev = it;
				count = 1;
				len = 0;
				it--;
				cout<<line<<endl;
			} else if(len + count == L+1) {
				cout<<"here2"<<endl;
				string line = "";
				while(prev < it){
					line = line + (*prev);
					line = line + " ";
					prev++;
				}
				line = line.substr(line.length()-1);
				output.push_back(line);
				prev = it;
				count = 1;
				len = 0;
				it--;
				cout<<line<<endl;
			}
		}
		return output;
	}*/
};

int main(int argc, char* argv[]) {
	vector<string> vec;
	vec.push_back("This");
	vec.push_back("is");
	vec.push_back("an");
	vec.push_back("example");
	vec.push_back("of");
	vec.push_back("text");
	vec.push_back("justification.");
	vec.push_back("This");
	vec.push_back("will");
	vec.push_back("never");
	vec.push_back("be");
	vec.push_back("used");
	vec.push_back("anywhere.");

	Solution s;
	vector<string> v = s.fullJustify(vec, 16);
	for(vector<string>::iterator it = v.begin(); it<v.end(); it++)
		cout<<(*it)<<"\n";
	return 0;
}