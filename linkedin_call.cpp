#include<iostream>
#include<string>
 
using namespace std;
 
int main()
{
 string yourjob;
 string yourstatus;
 cout<<"Describe your work status in one word: ";
 cin>>yourstatus;
 
 if ( yourstatus == "looking” || yourstatus == "interviewing” || yourstatus == "unsatisfied” ) {
  cout<< "My company is your oasis.  We are hiring software developers!  Contact me right away!!” <<endl;
 } else if ( yourstatus != "employed” &&yourstatus != "satisfied” ) {
  cout<< "We are hiring! Contact me to find out more!!” <<endl;
 } else {
  cout<< "Thanks for playing! Please forward this to any friends that are looking.” <<endl; // They’ll be back…
 }
 // TODO: For more info or to refer a friend reply to this message or call at 630-870-1936 0;
}