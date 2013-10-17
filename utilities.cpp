#include <array>
#include <fstream>

using namespace std;

static inline array<int,26> initialiseArray(array<int,26> array);

class mappingComponent
{
protected:
  int position;
  array<int,26> mapping; 

public:
  mappingComponent()
  {
    position = 0;
    initialiseArray(mapping);
  }
  int getRotate() 
  {
    return position;
  }
  void rotate()
  {
    position++;
  }
  virtual int getMapping(int index)
  {
    return mapping[index];
  }
  virtual void setUpComponent(char* path) = 0;
};

class rotor : public mappingComponent
{
public:
  void setUpComponent(char* path)
  {
    int i = 0;
    int read_int = 0;
    ifstream fin(path);

    if (!fin) 
    {
      throw ios_base::failure("Set up rotor failed");
    }
    while (fin >> read_int) {
      mapping[i] = read_int;
      i++;
    }
  }

  int getMapping(int index)
  {
    return mapping[index + (position % 26)];
  }
};

class plugboard : public mappingComponent
{
public:
  void setUpComponent(char* path)
  {
    int read_int1 = 0;
    int read_int2 = 0;
    ifstream fin(path);
    
    if (!fin) 
    {
      throw ios_base::failure("Set up plugboard failed");
    }
    while (fin >> read_int1) {
      // Always possible to even amount of ints in file
      fin >> read_int2; 
      mapping[read_int1] = read_int2;
    }
  }
};

static inline array<int,26> initialiseArray(array<int,26> array)
{
  for(int i = 0; i < 26; i++)
  {
    array[i] = i;
  }
  return array;
}