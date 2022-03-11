
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ostream>
#include <cstdlib>
#include "stack.hpp"
#include "stack.cpp"
using namespace std;
using namespace stack;

//int
void test1();
//double 
void test2();
//char test
void test3(); 
//help print
template<typename U>
void printStack(Stack<U> s);

int main() 
{
  char test;
  do
  {
   cout << "Make a selection, a for test3, b for test2, and c for test3, enter n to quit.\n ** note : not case sensitive ** \n"; 
   cin >> test;
   cin.ignore(10000, '\n');
   if(test == 'a' || test == 'A')
  {
   test3();
  }
   if(test == 'b' || test == 'B')
   {
   test2();
   }
   if(test == 'c' || test == 'C')
   {
   test1();
   }
  }while(test != 'n' || test != 'N');

   
    
    return 0;
}


void test1()
{
  //stack 1 & 2
    Stack<int> sint1;
    Stack<int> sint2;
    char ans;

    do{
        cout<<" \n *** Int test ***\n";
           for(int x = 1; x < 7; x++)
           {
            sint1.push(x);
           }
           
        
        //assiging 1 to 2
        sint2 = sint1;
        //reversing 1
        sint1.reverse(sint1);
        cout << "Printing 1st stack , reversed : ";
        //template helper func
        printStack(sint1);
           
        cout << "\n Printing 2nd stack : ";
        printStack(sint2);

        cout<<"\n Re-Test? Enter y for yes and n for no ";
        cin>>ans;
        cin.ignore(10000, '\n');//ignore unwanted values 
    }while (ans != 'n' && ans != 'N');
    
}

void test3()
{
  
    Stack<char> palindrome;
    Stack<char> palindrome1;
    int count = 0;
    cout << " \n*** palindrome test *** \n";
    char next,ans;
    do{
        cout<<"Enter a word:";
        cin.get(next);
        cin.ignore();
        while (next != '\n'){
            palindrome.push(next);
            palindrome1.push(next);
            cin.get(next);
            count++;
        }
     //reverse function for output
        palindrome.reverse(palindrome);
        cout << "Printing Palidrome : ";
        printStack(palindrome);
        printStack(palindrome1);
           
           //s.reverse(s);
        cout<<"\nre-Test? Enter y for yes and n for no";
        cin>>ans;
        cin.ignore(10000, '\n');//ignore unwanted values 
    }while (ans != 'n' && ans != 'N');
    
}

void test2()
{   
    Stack<double> sdouble1;
    char ans;
    do{
        cout<<  "\n*** Double test ***\n ";
           for(double x = 1.5; x < 7.5; x++)
           {
            //pushing {1.5,2.5,...,6.5}
            sdouble1.push(x);
           }
          //printing stack1
          cout << "Printing sdouble : ";
          printStack(sdouble1); 
        //copy constructing stack 2
        Stack<double> sdouble2(sdouble1);
      
           
           sdouble2.reverse(sdouble2);
           //printing out top of reversed stack
           cout << "\n\nTop of sdouble2 : " << setprecision(3) << sdouble2.peek(sdouble2) ;
           
        
        cout<<" \nre-Test? Enter y for yes and n for no";
        cin>>ans;
        cin.ignore(100000, '\n');//ignore unwanted values 
    }while (ans != 'n' && ans != 'N');

}

template <typename U>
void printStack(Stack<U> s)
{ //template helper function to print
  s.display(s);
}