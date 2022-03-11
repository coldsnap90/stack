
#ifndef stack_hpp
#define stack_hpp
#include <stdio.h>
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <ostream>
#include <exception>
using namespace std;


namespace stack
{
    template <class T> 
    struct StackFrame
    {
        T data;
        StackFrame<T>* link;  
    }; template <class T> using StackFramePtr =  StackFrame<T>*;
   

    template <class T> 
    class Stack 
    {
   
        public:
        //constructor
            Stack();
            //copy constructor
            Stack(const Stack<T>& a_Stack);
            ~Stack();

            void push(T the_symbol);
            T pop();
            //recursive algo for reversing stack
            void reverse(Stack<T>& s1);
            void addToBottom(Stack<T>& s1, T temp);
            //check top of stack
            const T& peek(Stack<T>& s1) const;
            //check if stack is e,pty
            bool empty() const;
            //print function
            void display(const Stack<T>& s1) const;
            //assignment operator
            void operator =(const Stack<T>& a_Stack);
            //overloading output
            friend ostream& operator <<(ostream& outs, const Stack<T>& s1);
        private:
            StackFramePtr<T> top;//pointer to the top stack
        
    };
}
#endif