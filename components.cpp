#include "mappingComponent.cpp"

class rotor : public mappingComponent
{
public:
  void setUpComponent(char* path)
  {
    int read_int;
    ifstream fin(path);

    if (!fin) 
    {
      throw ios_base::failure("Set up rotor failed");
    }
    for (int i = 0; fin >> read_int; i++) 
    {
      mapping[i] = read_int;
    }
  }

  void rotate()
  {
    position++;
    mapping.push_back(mapping[0]);
    mapping.pop_front();
  }
};

class plugboard : public mappingComponent
{
public:
  void setUpComponent(char* path)
  {
    int read_int1;
    int read_int2;
    ifstream fin(path);
    
    if (!fin) 
    {
      throw ios_base::failure("Set up plugboard failed");
    }
    while (fin >> read_int1) {
      // Always possible due to even amount of ints in file
      fin >> read_int2; 
      mapping[read_int1] = read_int2;
      mapping[read_int2] = read_int1;
    }
  }
};