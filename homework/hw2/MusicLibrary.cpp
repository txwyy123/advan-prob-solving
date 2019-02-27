#define STRMAX 100
#define SONGMAX 1024

#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <stdio.h> 
#include <iostream>

using namespace std;

struct Song {
	char title[STRMAX];
	char artist[STRMAX];
	int year_published;
};

struct Song music_library[SONGMAX];
int current_number_of_songs = 0;
string filename;
fstream fs;

int open_file(char mode){
	switch(mode){
		case 'r': fs.open(filename.c_str(), ios_base::in);break;
		case 'w': fs.open(filename.c_str(), ios_base::out);break;
		default: break;
	}

	if(fs.is_open())
		return 0;
	return 1;
}

void split(string s, string *d){
	const char *sep = ":,";

	char *ss = new char[s.size() + 1];
	std::copy(s.begin(), s.end(), ss);
	ss[s.size()] = '\0';

    char *p;
    int i = 0;

    p = strtok(ss, sep);
    while(p){
        d[i++] = p;
        p=strtok(NULL, sep);
    }
}

int read_song(){
	if(open_file('r') != 0)
		return 1;
	
	string line;
	Song song;

	while(getline(fs,line)){
		string strs[6];
		split(line, strs);
		strcpy(song.title, strs[1].c_str());
		strcpy(song.artist, strs[3].c_str());
		song.year_published = atoi(strs[5].c_str());
		music_library[current_number_of_songs++] = song;
	}
	fs.close();
	return 0;
}

int write_song(){
	if(open_file('w') != 0)
		return 1;

	for(int i = 0; i < current_number_of_songs; i++){
		Song song = music_library[i];
		fs << "Title:" << song.title << "," << "Artist:" << song.artist << "," << "Year Published:" << song.year_published << endl;
	}
	fs.close();
	return 0;
}

int load_MusicLibrary(){
	if(read_song() != 0){
		cerr << "fail to load music library";
		return 1;
	}
	return 0;
}

int store_MusicLibrary(){
	if(write_song() != 0){
		cerr << "fail to store music library";
		return 1;
	}
	return 0;
}

bool read_command(char & command){
	cin >> command;
	if(command == 'I' || command == 'P' || command == 'D' || command == 'L' || command == 'Q')
		command += 32;
	else if(command != 'i' && command != 'p' && command != 'd' && command != 'l' && command != 'q')
		return false;
	return true;
}

bool find_index_of_song_with_name(string name, int & index){
	int l = 0, r = current_number_of_songs-1;
	int m = l+(r-l)/2;
	while(l <= r){
		if(strcmp(music_library[m].title, name.c_str()) < 0)
			l = m+1;
		else if(strcmp(music_library[m].title, name.c_str()) > 0)
			r = m-1;
		else{
			index = m;
			return true;
		}
		m = l+(r-l)/2;
	}
	index = l;
	return false;
}

void crunch_up_from_index(int index){
	for(int i = index+1; i < current_number_of_songs; i++)
		music_library[i-1] = music_library[i];
}
	
void crunch_down_from_index(int index){
	for(int i = current_number_of_songs-1; i >= index; i--)
		music_library[i+1] = music_library[i];
}

void add_song_to_MusicLibrary(){
	Song song;

	cin.ignore();
	cout << "Title: ";
	cin.getline(song.title, STRMAX);
	cout << "Artist: ";
	cin.getline(song.artist, STRMAX);
	cout << "Year Published: ";
	cin >> song.year_published;

	int index;
	if(!find_index_of_song_with_name(song.title, index)){
		crunch_down_from_index(index);
		music_library[index] = song;
		current_number_of_songs++;
	}else{
		music_library[index] = song;
	}
}

void remove_song_from_MusicLibrary_by_name(){
	string title;
	cout << "Title: ";
	cin.ignore();
	getline(cin, title);

	int index;
	if(find_index_of_song_with_name(title, index)){
		crunch_up_from_index(index);
		current_number_of_songs--;
	}else{
		cout << "title " << title << " not found" << endl;
	}
}

void print_MusicLibrary(){
	for(int i = 0; i < current_number_of_songs; i++){
		Song song = music_library[i];
		cout << i+1 << " ";
		cout << "Title: " << song.title << ",";
		cout << "Artist: " << song.artist << ",";
		cout << "Year Published: " << song.year_published;
		cout << endl;
	}
}

void lookup_song_from_MusicLibrary_by_name(){
	string title;
	cout << "Title: ";
	cin.ignore();
	getline(cin, title);

	int index;
	if(find_index_of_song_with_name(title, index)){
		Song song = music_library[index];
		cout << "Title: " << song.title << endl;
		cout << "Artist: " << song.artist << endl;
		cout << "Year Published: " << song.year_published << endl;
	}else{
		cout << "title " << title << " not found" << endl;
	}
}

void evaluate_command(char command){
	switch(command){
		case 'i':
		case 'I':
			add_song_to_MusicLibrary();break;
		case 'p':
		case 'P':
			print_MusicLibrary();break;
		case 'd':
		case 'D':
			remove_song_from_MusicLibrary_by_name();break;
		case 'l':
		case 'L':
			lookup_song_from_MusicLibrary_by_name();break;
	}
}

int main(int argc, char** argv){
	if(argc == 1)
		filename = "myMusic";
	else
		filename = argv[1];

	if(load_MusicLibrary() != 0)
		return 1;

	char command;
	while(true){
		if(read_command(command)){
			if(command == 'q') break;
			evaluate_command(command);
		}
	}

	if(store_MusicLibrary() != 0)
		return 1;

	return 0;
}