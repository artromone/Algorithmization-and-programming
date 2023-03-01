#ifndef I1_SEQUENCE_H
#define I1_SEQUENCE_H

struct Counter {
  void operator()(unsigned int currentValue);

  unsigned int count;
  unsigned int countMax;

  unsigned int previousValue;
};

struct LocalMax {
  void operator()(unsigned int currentValue);

  unsigned int previousValue;
  unsigned int beforePreviousValue;

  unsigned int count;
};

#endif
