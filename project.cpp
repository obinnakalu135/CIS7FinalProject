#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

string encrypt(string, string);
string decrypt(string, string);
string upKey;
string message;
void convert();

int main() {
  int choice;
   
  do {
    cout << "Menu: " << endl;
    cout << "1. Encrypt Message."<< endl;
    cout << "2. Decrypt Message."<< endl;
    cout << "3. Exit Program."<< endl;
    cout << "Please enter a number to choose(1-3): ";
    cin >> choice;
    cin.ignore();// added this so the program stops the do while from repeating
    if(choice > 3 || choice < 1)
      cout << "Error! Please enter  valid option(1-3):" << endl;
    else {
      
    if(choice == 1)
    {
    convert();
     cout <<"Your message has been encrypted: "<<encrypt(message,upKey)<<endl;
      cout <<endl;
    }
    if(choice == 2) { 
        convert();
        cout <<"Your message has been decrypted: "<<decrypt(message,upKey) << endl;
    }
      
    }
    
  }while(choice != 3);
  cout << "Goodbye";
}

string encrypt(string pt, string k){
 
    string ct = "";
    for(int i=0;i<pt.size();i++)
        ct += (char) (((int)pt[i]-'A' + (int)k[i]-'A') % 26) + 'A';
 
    return ct;
}

string decrypt(string ct, string k){

    string text = "";
    for(int i=0;i<ct.size();i++)
        text += (char) ((((int)ct[i]- 'A' - (k[i] -'A')) + 26) % 26) + 'A';
 
    return text;
}

void convert() {
	string msg;
	cout << "Type message and press Enter twice to submit: ";
	getline(cin, msg);
	cin.ignore();

	//Make message capital
	for (int i = 0; i < msg.length(); i++) {
		msg[i] = toupper(msg[i]);
	}

	string key;
	cout << "Type key and press Enter twice to submit: ";
	getline(cin, key);
	cin.ignore();

	//Make user key capital
	for (int i = 0; i < key.length(); i++) {
		key[i] = toupper(key[i]);
	}
  string keyMap = "";
	for (int i = 0, j = 0; i < msg.length(); i++) {
		if (msg[i] == 32) {
			keyMap += 32;
		}
		else {
			if (j < key.length()) {
				keyMap += key[j];
				j++;
			}
			else {
				j = 0;
				keyMap += key[j];
				j++;
			}
		} 
	}
  
	message = msg;
	upKey = keyMap;
}
