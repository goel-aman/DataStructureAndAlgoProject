#include<bits/stdc++.h>
#include<iostream>
#include<string>

#include<fstream>
using namespace std;


void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
 
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};
 
class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        // Recursive call
        insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word) {
        insertWord(root, word);
    }


    bool search(string word) {
        // Write your code here
        return search(root,word);

    }
    bool search(TrieNode* root,string word){
        if(word.size() == 0){
            if(root->isTerminal == true){
                return true;
            }else{
                return false;
            }
        }
        TrieNode* child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            child = root->children[index];
            return search(child,word.substr(1));
        }else{
            return false;
        }
    }
    
    
    
      void print(TrieNode* root,string output){
        if(root == NULL){
            return;
        }
        
        if(root->isTerminal){
            cout<<output<<endl;
        }
        
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                string mm = output  + root->children[i]->data;
                print(root->children[i],mm);
            }
        }
    }
    
    
    void helper(TrieNode* root,string pattern,string output){
        if(root == NULL){
            return ;
        }
        
        if(pattern.size() == 0){
            if(root->isTerminal){
                cout<<output<<endl;
            }
            for(int i=0;i<26;i++){
                if(root->children[i] != NULL){
                    string mm = output + root->children[i]->data;
                    print(root->children[i],mm);
                }
            }
            return ;
        }
        
        
        int index = pattern[0] - 'a';
        if(root->children[index]){
            output += root->children[index]->data;
            helper(root->children[index],pattern.substr(1),output);
        }
        return ;
        
        
    }
    
    
    
    void autoComplete(/*vector<string> input,*/string pattern) {
        // Complete this function
        // Print the output as specified in question
     //   for(int i=0;i<input.size();i++){
       //     insertWord(input[i]);
       // }
    	    
        string output = "";
        helper(root,pattern,output);
    }
    
    
    
    
    
};

int main(){
	cout<<endl<<endl<<endl<<endl;
	cout<< "\t\t\t\t\t\t Name : Aman Goel  "<<endl;
	cout<< "\t\t\t\t\t\t Registration Number : 18BCE0895 "<<endl;
	cout<< "\t\t\t\t\t\t Subject Course Code: CSE2003"<<endl;
	cout<< "\t\t\t\t\t\t Slot : B1"<<endl;
	cout<< "\t\t\t\t\t\t Faculty Name : Gopinath MP"<<endl;
	delay(5);
	system("cls");
	
	cout<<"1) To Insert The Word ( By Giving Manual Input ) : "<<endl;
	//cout<<"2) To Search The Word Whether it is there in the dictionary Or Not : "<<endl;
	cout<<"3) To Take The Input From The English GitHub Word Dictionary: "<<endl;
	//cout<<"4) To Autocomplete a word : "<<endl;
	
    int choice;
    cin >> choice;
    Trie t;
    while(choice != -1){
        string word;
        bool ans;
        switch(choice) {
            case 1 :
            	cout<<"Please Enter The Word To Append In The Dictionary : "<<endl;
                cin >> word;
                transform(word.begin(),word.end(),word.begin(),::tolower);
                t.insertWord(word);
                cout<<"Word Got Inserted Successfully : "<<endl;
                break;
            case 2 :
            	cout<<"Please enter the word to search : "<<endl;
                cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            case 3:
            	{
            			ifstream file;
				file.open("words_alpha.txt");
				if(!file.is_open()){
					cout<<"Error while opening the file";
				}else{
					cout<<"Process Initiated"<<endl;
					string line;
					while(file.good()){
						getline(file,line);
						t.insertWord(line);
						//cout<<line.size()<<endl;
					}
					cout<<"Process Ended"<<endl;
				}
				
				}
				break;
			case 4:
				cout<<"Please enter the word for Autocomplete feature to work: "<<endl;
				cin>>word;
				transform(word.begin(),word.end(),word.begin(),::tolower);
				t.autoComplete(word);
				break;
            default :
                return 0;
        }
        cout<<"1) To Insert The Word ( By Giving Manual Input ) : "<<endl;
		cout<<"2) To Search The Word Whether it is there in the dictionary Or Not : "<<endl;
		cout<<"3) To Take The Input From The English GitHub Word Dictionary: "<<endl;
		cout<<"4) To Use AutoComplete Feature : "<<endl;
        cin >> choice;
    }
    return 0;
}

