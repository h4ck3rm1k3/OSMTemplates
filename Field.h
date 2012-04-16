//each field class can define a get attribute 

template <class R> class FIELDTYPE
{
  R getValue (const Attributes& attrs);
};

class INTFIELD : public FIELDTYPE<int> 
{

};

template <class T> class TFIELD
{
  Field T; // hold a field of type t/
};
