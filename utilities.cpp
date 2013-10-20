#include <deque>
#include <fstream>

// TODO: Make sure everything assumes A = 1
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
    return 0; // TODO
  }
  virtual void setUpComponent(char* path) = 0;
};

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
    mapping.push_back(mapping[mapping.size() - 1]);
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

class enigma
{
  int NUM_ROTORS;
  plugboard pbd;
  rotor* rtr;

public:
  enigma(int argc, char** argv)
  {
    NUM_ROTORS = argc - 2;
    rtr = new rotor[NUM_ROTORS];

    pbd.setUpComponent(argv[argc - 1]);
    for(int i = 0; i < NUM_ROTORS; i++)
    {
      rtr[i].setUpComponent(argv[i + 1]);
    }
  }

  int encode_decode(int chr)
  {
    chr = pbd.getMapping(chr);
    for(int i = 0; i < NUM_ROTORS; i++)
    {
      chr = rtr[i].getMapping(chr);
    }
    chr = reflect(chr);
    for(int i = NUM_ROTORS - 1; i > 0; i--)
    {
      chr = rtr[i].getReverseMapping(chr);
    }
    chr = pbd.getMapping(chr);
    rotate();
    return chr;
  }

  void rotate()
  {
    // Needs to sort out rotating for the rtr deque
  }

  int reflect(int chr)
  {
    return (chr + 13) % 26;
  }

  void delete_enigma()
  {

  }

};

// TODO: Make sure this isnt creating a copy of deque
static inline deque<int> initialiseDeque(deque<int> dq)
{
  for(int i = 1; i <= 26; i++)
  {
    dq.push_back(i);
  }
  return dq;
}