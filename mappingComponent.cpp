#include <deque>
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace std;

static inline deque<int> initialiseDeque(deque<int>& dq);

class mappingComponent
{
protected:
  int position;
  deque<int> mapping; 

public:
  mappingComponent()
  {
    position = 0;
    initialiseDeque(mapping);
  }
  int getPosition() 
  {
    return position;
  }
  int getMapping(int index)
  {
    return mapping[index];
  }
  int getReverseMapping(int chr)
  {
    for(int i = 0; i < 26; i++)
    {
      if(mapping[i] == chr)
      {
        return i;
      }
    }
    throw out_of_range("Letter not contained in mapping"); 
  }
  virtual void setUpComponent(char* path) = 0;
};

static inline deque<int> initialiseDeque(deque<int>& dq)
{
  for(int i = 0; i < 26; i++)
  {
    dq.push_back(i);
  }
  return dq;
}
