#include "components.cpp"

class machine
{
  int NUM_ROTORS;
  plugboard pbd;
  rotor* rtr;

public:
  machine(int argc, char** argv)
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