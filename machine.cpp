#include "components.cpp"

class machine
{
  int NUM_ROTORS;
  plugboard pbd;
  rotor* rtr;

  void rotate()
  {
    rtr[0].rotate();
    for(int i = 0; i < NUM_ROTORS; i++)
    {
      if(rtr[i].getPosition() >= 26 && (rtr[i].getPosition() % 26) == 0)
      {
        if(i + 1 < NUM_ROTORS)
        {
          rtr[i + 1].rotate();
        }
      }
    }
  }

  int reflect(int chr)
  {
    return ((chr + 13) % 26);
  }

public:
  machine(int argc, char** argv)
  {
    NUM_ROTORS = argc - 2;

    pbd.setUpComponent(argv[argc - 1]);

    if(NUM_ROTORS > 0)
    {
      rtr = new rotor[NUM_ROTORS];
      for(int i = 0; i < NUM_ROTORS; i++)
      {
        rtr[i].setUpComponent(argv[i + 1]);
      }
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
    if(NUM_ROTORS > 0)
    {
      for(int i = NUM_ROTORS - 1; i >= 0; i--)
      {
        chr = rtr[i].getReverseMapping(chr);
      }
      rotate();
    }
    chr = pbd.getMapping(chr);
    return chr;
  }

  void delete_machine()
  {
    if(NUM_ROTORS > 0)
    {
      delete [] rtr;
    }
  }
};