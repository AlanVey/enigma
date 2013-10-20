#include <deque>
#include <fstream>

using namespace std;

static inline deque<int> initialiseDeque(deque<int> dq);

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
    // Index - 1 because A = 1 but first element is mapping[0]
    return mapping[index - 1];
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

// TODO: Make sure this isnt creating a copy of deque (pass by reference)
static inline deque<int> initialiseDeque(deque<int> dq)
{
  for(int i = 1; i <= 26; i++)
  {
    dq.push_back(i);
  }
  return dq;
}