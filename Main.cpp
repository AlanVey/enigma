// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include "machine.cpp"

using namespace std;

static inline int toInt(char chr)
{
  if(chr < 'A' || chr > 'Z')
  {
    throw out_of_range("Not a valid enigma letter");
  }
  return (int) (chr - 'A');
}

static inline char toChar(int chr)
{
  return (char) (chr + 'A');
}

int main(int argc, char **argv)
{
  if(argc < 2)
  {
    throw out_of_range("You must at least give the path to a plugboard"); 
  }
  else
  {
    char chr;
    machine enigma (argc, argv);
    while(cin >> ws >> chr)
    {
      cout << toChar(enigma.encode_decode(toInt(chr))) << endl;
    }
    enigma.delete_machine();
  }
  return 0;
}
