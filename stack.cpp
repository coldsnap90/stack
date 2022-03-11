#include "stack.hpp"
using namespace std;

namespace stack{
//constructor
template <class T>
Stack<T>::Stack( ):top(NULL)
{}

//template copy constructor
template <class T>
Stack<T>::Stack(const Stack& a_Stack) : top(a_Stack.top){
  
    if (a_Stack.top==NULL)
    {
        cout << "NULL";
        return;
    }
    else
    {
    
        StackFramePtr<T> temp = a_Stack.top;//temp go thru 
        //nodes in a_Stack
        //ptr to end of stack
        StackFramePtr<T> end;
        
        try
        {
          //form a node end
          //attempt to allocate memory
         end = new StackFrame<T>;
        }
       
        catch(bad_alloc a_Stack)
        {//exit if no memory is allocated
          cout<<a_Stack.what()<<endl;
          return;     
        }
        
        // 1st node created and populated
        end->data = temp->data;
        top = end;
        temp=temp->link;
        
        while(temp!=NULL)
        {
        
          try
            {//form a node end
                //attempt to allocate memory
              end->link = new StackFrame<T>;
            }
            catch(bad_alloc a_Stack)
            {
              //exit if no memory is allocated
              cout<<a_Stack.what()<<end;
              return;
            }
            //creatimn new node
            end->link = new StackFrame<T>;
            end=end->link;
            end->data=temp->data;
            temp=temp->link;
        }
        //setting end to null
        end->link=NULL;
    }
    
}
//destructor
template<class T>
Stack<T>::~Stack()
{
  //strack pointer to top
   StackFramePtr<T> temp, link;
   temp = top;

   // Traverse the list deleting each node
   while (temp != NULL)
   {
       link = temp->link;
       delete temp;
       temp = link;
   }
}
template<class T>
void Stack<T>::push(T the_symbol)
{
  
    StackFramePtr<T> temp;
    try
    {//form an new node temp, attempt to allocate memory
      temp= new StackFrame<T>;
    }
    catch(bad_alloc a)
    {//exit if memory is not :ddd
      cout<<a.what()<<endl;
      return;
    }

    temp->data=the_symbol;
    temp->link=top;
    top=temp;
}

//empty stack func
template <class T>
bool Stack<T>::empty() const
{
 return (top == NULL);
}

template <class T>
T Stack<T>::pop()
{    //self explanatory
    if (empty())
    {
        cout<<" Error: popping a empty stack,\n";
        exit(1);
    }

    T result=top->data;
    //stack ptr
    StackFramePtr<T> temp_ptr;
    temp_ptr = top;
    top = top->link;
    
    delete temp_ptr;
    return result;
}

template<class T>
void  Stack<T>::reverse(Stack& s1)
{// uses addToBottom to pop all values in stack and saves in the call stack, then adds them back in as the stack is empty
  //Big O: O(1)
 if(s1.empty()) // 
 {//Big O: O(1)
   return;
 }
   
 //Big O: O(1)
 
 T temp = s1.pop();
 //Big O: O(1)
 //Big O: O(1)
 reverse(s1);//Big O: O(n)
 addToBottom(s1,temp);//Big O: O(1)
 }//the best case is O(n) and the worst case is 

//part of reverse recursion algorithm
template <class T>
void Stack<T>::addToBottom(Stack& s1,T temp)
{
  if(s1.empty())
  {
    s1.push(temp);
    return;
  }
  
  T temp2 = s1.pop();
  addToBottom(s1,temp);
  s1.push(temp2);
}
  
  

// returns top of stack
template <class T>
const T& Stack<T>::peek(Stack<T>& s1) const
{
  if(!empty())
  {
    return top->data;
  }
  else
  return -1;
}
  
//display
template <class T>
void Stack<T>::display(const Stack<T>& s1) const
{
  //stack ptr
  StackFramePtr<T> temp;
  //temp set to top
  temp=top;

  if(temp==NULL)
  {
    cout<<"\n Stack is empty";
  }

  else
  {
    //cout<<"\n The elements in the stack are: ";
    //moving through stack
    while(temp!=NULL)
    {
      cout << temp->data;
      temp = temp->link;
    }
  }

}


template<class T> //prints top of stack
ostream& operator << (ostream& outs, const Stack<T>& s1)
{
  cout << s1.peek(s1);
  return outs;
}


//assignment operator 
template<class T> 
void Stack<T>::operator=( const Stack<T>& a_Stack)
{
  if (a_Stack.top==NULL)
    {
        cout << "NULL";
        return;
    }
    else{
          StackFramePtr<T> temp = a_Stack.top;//temp go thru 
          //nodes in a_Stack
          //ptr to end of stack
          StackFramePtr<T> end;
        
          try
          {
            //form a node end
            //attempt to allocate memory
           end = new StackFrame<T>;
          }
        
          catch(bad_alloc a_Stack)
          {//exit if no memory is allocated
            cout<<a_Stack.what()<<endl;
            return;     
          }
          
        // 1st node created and populated
          end->data = temp->data;
          top = end;
          temp=temp->link;
          
          while(temp!=NULL)
          {
              try
                 {//form a node end
                  //attempt to allocate memory
                end->link = new StackFrame<T>;
                 }
              catch(bad_alloc a_Stack)
                {
                  //exit if no memory is allocated
                  cout<<a_Stack.what()<<end;
                  return;
                }
              //creation new node
              end->link = new StackFrame<T>;
              end=end->link;
              end->data=temp->data;
              temp=temp->link;
          }
          //setting end to null
          end->link=NULL;
      }
}
}
//stacksavitch