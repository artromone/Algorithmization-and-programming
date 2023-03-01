#include <iostream>
#include <fstream>
#include <ctime>
#include "countelements.h"
#include "arraydynamic.h"
int main(int argc, char **argv)
{
  size_t beginIndex = 0, endIndex = 1;
  const size_t arrayConstSize = 10;
  int arrayConst[arrayConstSize] = {1, -1, 3, 4, 5, 4, -1, -1, 2, 1};
  size_t countNrfmConst = countNegativeRightFromMax(arrayConst, arrayConstSize);
  bool countRirConst = countRepetitiveInRange(arrayConst, arrayConstSize, beginIndex, endIndex);
  std::cout << countNrfmConst << "\n";
  std::cout << countRirConst << "\n";
  size_t arrayDynamicSize = 0;
  std::cin >> arrayDynamicSize;
  if (!std::cin)
  {
    std::cerr << "Error while dynamic input.\n";
    return 2;
  }
  ArrayDynamic arrayDynamic(arrayDynamicSize);
  std::srand(time(nullptr));
  for (size_t i = 0; i < arrayDynamicSize; i++)
  {
    arrayDynamic.data[i] = std::rand() % 10 - 5;
  }
  size_t countNrfmDynamic = countNegativeRightFromMax(arrayDynamic.data, arrayDynamicSize);
  bool countRirDynamic = countRepetitiveInRange(arrayDynamic.data, arrayDynamicSize, beginIndex, endIndex);
  std::cout << countNrfmDynamic << "\n";
  std::cout << countRirDynamic << "\n";
  if (argc == 1)
  {
    std::cout << "No file provided.";
    return 2;
  }
  if (argc > 2)
  {
    std::cout << "Too much parameters.\n";
    return 2;
  }
  std::string fileName = argv[1];
  std::fstream fileInput(fileName);
  if (!fileInput.is_open())
  {
    std::cerr << "Error while opening file " << argv[1] << "\n";
    return 2;
  }
  while (!fileInput.eof())
  {
    size_t arrayFileSize = 0;
    fileInput >> arrayFileSize;
    if (!fileInput)
    {
      std::cerr << "Error while reading file " << argv[1] << "\n";
      return 2;
    }
    ArrayDynamic arrayFile(arrayFileSize);
    for (size_t i = 0; i < arrayFileSize; i++)
    {
      fileInput >> arrayFile.data[i];
      if (!fileInput)
      {
        std::cerr << "Error while reading file " << argv[1] << "\n";
        return 2;
      }
    }
    size_t countNrfmFile = countNegativeRightFromMax(arrayFile.data, arrayFileSize);
    bool countRirFile = countRepetitiveInRange(arrayFile.data, arrayFileSize, beginIndex, endIndex);
    std::cout << countNrfmFile << "\n";
    std::cout << countRirFile << "\n";
  }
}
