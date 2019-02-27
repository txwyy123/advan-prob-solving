#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

void open_file(fstream &fs, char mode, string filename){
	switch(mode){
		case 'r': fs.open(filename.c_str(), ios_base::in);break;
		case 'w': fs.open(filename.c_str(), ios_base::out);break;
		default: break;
	}
}

void readStopWords(set<string> &stopwords, string stop_filename){
	fstream stop_fs;
	open_file(stop_fs, 'r', stop_filename);
	for_each(istream_iterator<string>(stop_fs), istream_iterator<string>(), 
		[&](string word){
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			stopwords.insert(word);
		});
	stop_fs.close();
}

void calcFreq(map<string, int> &frequency, set<string> stopwords, string doc_filename){
	fstream doc_fs;
	open_file(doc_fs, 'r', doc_filename);
	for_each(istream_iterator<string>(doc_fs), istream_iterator<string>(), 
		[&](string word){
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			if(stopwords.find(word) == stopwords.end()){
				if(frequency.find(word) != frequency.end())
					frequency[word] = frequency.find(word)->second+1;
				else
					frequency.insert(make_pair(word, 1));
			}
		});
	doc_fs.close();
}

void outputFreq(map<string, int> frequency, string freq_filename){
	fstream freq_fs;
	open_file(freq_fs, 'w', freq_filename);
	for_each(frequency.begin(), frequency.end(), [&](pair<string, int> pair){freq_fs << pair.first << ":" << pair.second << endl;});
	freq_fs.close();
}

int main(){
	string stop_filename = "stopwords.txt", doc_filename = "sample_doc.txt", freq_filename = "frequency.txt";
	set<string> stopwords;
	map<string, int> frequency;

	readStopWords(stopwords, stop_filename);
	calcFreq(frequency, stopwords, doc_filename);
	outputFreq(frequency, freq_filename);
}